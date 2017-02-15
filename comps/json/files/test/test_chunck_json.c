
#define  _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <skalibs/djbunix.h>
#include <skalibs/stralloc.h>
#include <skalibs/buffer.h>
#include <skalibs/sig.h>
#include <skalibs/selfpipe.h>
#include <skalibs/iopause.h>
#include <skalibs/strerr2.h>

#include "test_binn.h"

#define MAX_ALLOC_CHUNCK    (1024)
#define MAX_ALLOCATED       (10)

static char output_s_g[MAX_ALLOC_CHUNCK];
static buffer output_b_g = BUFFER_ZERO;

static char input_s_g[MAX_ALLOC_CHUNCK];
static buffer input_b_g = BUFFER_ZERO;

static stralloc input_sa_g = STRALLOC_ZERO;

static void die(const char const *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

static int parse_string(char* json) {
    int _ret=-1;
    binn_t head=BINN_INVALID;
    
    fprintf(stderr, "parse string (%s)\n", json);
    _ret=json_to_binn(json, &head);
    
    if(_ret<0)
        fprintf(stderr, "ERROR: parsing impossible\n");
    else if(!_ret)
        fprintf(stderr, "WARNING: parsing incomplete\n");
    else {
        fprintf(stderr, "SUCCESS: parsing complete\n");
        binn_free(head);
    }
    
    return _ret;    
}
    
static const char *complete_str="{ \"cmd\": \"test\", \"data\": [ 0, 1, 2, 3] }      { \"titi\": \"toto\", \"vals\": [ 0, 1, 2, 3] }  [ 10, 11, 12, 13] ";
static char *p_str=0;
static int nb_error=0;
static unsigned int loop_cont_g = 1;

#define SIGNAL_FD_IDX (2)

static void handle_signals (void) {
    for (;;) {
        switch (selfpipe_read()) {
            case -1 : strerr_diefu1sys(111, "selfpipe_read") ;
            case 0 : return ;

            case SIGCHLD:
            case SIGTERM:
            case SIGHUP:
            case SIGQUIT:
            case SIGINT:
                strerr_warn3x(PROG, ": ", "now quitting ...");
                loop_cont_g = 0;
                break ;

            default :
                strerr_dief1x(101, "internal error: inconsistent signal state. Please submit a bug-report.") ;
        }
    }
}

static int init_sig_fd(void) {
    int fd = selfpipe_init() ;
    if (fd < 0) strerr_diefu1sys(111, "init selfpipe") ;

    if (sig_ignore(SIGPIPE) < 0) strerr_diefu1sys(111, "ignore SIGPIPE") ;

    {
        sigset_t set ;
        sigemptyset(&set) ;
        sigaddset(&set, SIGTERM) ;
        sigaddset(&set, SIGHUP) ;
        sigaddset(&set, SIGQUIT) ;
        sigaddset(&set, SIGCHLD) ;
        sigaddset(&set, SIGINT) ;
        if (selfpipe_trapset(&set) < 0) strerr_diefu1sys(111, "trap signals") ;
    }

    return fd;
}



///////////////////////////////////////////////////////////////////////////////
int main(int ac, char** av) {
    int _ret=0;
    int sfd=init_sig_fd();
    int p[2] = {0};
    tain_t deadline;
    
    (void)ac;
    (void)av;
    
    pipenb(&p[0]);
    stralloc_ready(&input_sa_g, MAX_ALLOC_CHUNCK);
    buffer_init(&output_b_g, buffer_write, p[1], output_s_g, MAX_ALLOC_CHUNCK);
    buffer_init(&input_b_g, buffer_read, p[0], input_s_g, MAX_ALLOC_CHUNCK);
        
    tain_now_g();
    tain_addsec_g(&deadline, 1);    
    p_str=(char*)complete_str;
    
    while(loop_cont_g) {
        iopause_fd x[3];
        int r=-1;
        
        x[SIGNAL_FD_IDX].fd = sfd; x[SIGNAL_FD_IDX].events = IOPAUSE_READ;
        x[0].fd = buffer_fd(&output_b_g);
        x[0].events = (buffer_iswritable(&output_b_g)?IOPAUSE_WRITE:0);
        x[1].fd = buffer_fd(&input_b_g);
        x[1].events = IOPAUSE_READ;        
        
        r=iopause_g(x, 3, &deadline);
        if(r<0) break;
        else if(!r) {
            
            int max=45+(rand()%16);
            int count=max;
            // fprintf(stderr, "write max (%d)\n", max);
            while(count>0) {
                // fprintf(stderr, "string (%s)\n", p_str);
                int l=strlen(p_str);
                int l2=(l>count?count:l);
                // fprintf(stderr, "write length(%d), loop (%d), count(%d)\n", l, l2, count);
                buffer_putallnoflush(&output_b_g, p_str, l2);
                if(l<count) {
                    p_str=(char*)complete_str;
                }
                else { 
                    p_str+=l2;  
                }

                count-=l2;
                
            }
            deadline=STAMP;
            deadline.nano+=1000*1000;    
            // tain_addsec_g(&deadline, 1);
        }
        else if(x[SIGNAL_FD_IDX].revents & IOPAUSE_READ) handle_signals() ;
        else if(x[0].revents&IOPAUSE_WRITE) {
            buffer_flush(&output_b_g);
        }
        else if(x[1].revents&IOPAUSE_READ) {            
            int got=0;

            buffer_fill(&input_b_g);
            stralloc_ready(&input_sa_g, buffer_len(&input_b_g));
            
            while(1) {
                if(!got) {
                    unsigned int lg1=buffer_len(&input_b_g);
                    unsigned int lg2=buffer_getnofill(&input_b_g, input_sa_g.s+input_sa_g.len, lg1);
                    // fprintf(stderr, "load new buffer(%d/%d)\n", lg1, lg2);
                    input_sa_g.len+=lg2;
                    input_sa_g.s[input_sa_g.len]=0;
                }
            
                got=parse_string(input_sa_g.s);
                if(got<0) {
                    if(nb_error++>=50) loop_cont_g=0;
                    break;
                }
                else {
                    // fprintf(stderr, "got(%d)\n", got);
                    
                    if(got>0) {
                        if(got<(int)input_sa_g.len) {
                            buffer_unget(&input_b_g, input_sa_g.len-got);
                        }
                        got=0;
                        input_sa_g.len=0;
                        nb_error=0;
                    }
                }
            } // while

        }
        
    }
    
    stralloc_free(&input_sa_g);
    selfpipe_finish() ;
    
    binn_term();
    return 0;
}
