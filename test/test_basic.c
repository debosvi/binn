
#include <stdlib.h>
#include <stdio.h>

#include "test_binn.h"

static void die(const char const *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

#define INIT_TEST_COMPLEX(name)                             \
    binn_t name=binn_##name();                              \
    if(name==BINN_INVALID)                                  \
        die("Unable to create binn ##name");                \
    fprintf(stderr, "binn %s created (%d)\n", #name, name);

#define END_TEST_COMPLEX(name)                              \
    binn_free(name);                            
    
int main(int ac, char** av) {
    (void)ac;
    (void)av;
    
    INIT_TEST_COMPLEX(list)
    INIT_TEST_COMPLEX(map)
    INIT_TEST_COMPLEX(object)
    
    END_TEST_COMPLEX(list)
    END_TEST_COMPLEX(map)
    END_TEST_COMPLEX(object)
    
    return 0;
}