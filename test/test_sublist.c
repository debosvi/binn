
#include <stdlib.h>
#include <stdio.h>

#include "test_binn.h"

static void die(const char const *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

///////////////////////////////////////////////////////////////////////////////
int main(int ac, char** av) {
    const int8_t i8=-123;
    const uint16_t u16=654;
	int8_t i8_r=0;
	uint16_t u16_r=0;
    (void)ac;
    (void)av;
    
    binn_t sub=binn_list();   
	binn_t bi8=binn_int8(i8);
	binn_t bu16=binn_uint16(u16);

    binn_t bi8_r=BINN_INVALID;   
    binn_t bu16_r=BINN_INVALID;   
    
    fprintf(stderr, "sub (%d)\n", sub);

    fprintf(stderr, "insert int8\n");
    if(binn_list_add_item(sub, bi8))
        die("Unable to add int8 value");  

    fprintf(stderr, "insert uint16\n");
    if(binn_list_add_item(sub, bu16))
        die("Unable to add int8 value");  
    
    fprintf(stderr, "\npouplate success\n");
  
    if(binn_list_get_item(sub, 0, &bi8_r))
        die("Unable to get binn item 0 from sub list");
	if(binn_to_int8(bi8_r, &i8_r))
        die("Unable to get value of binn item 0");
	if(i8_r!=i8)
        fprintf(stderr, "I8 values differs, expected (%d), current (%d)\n", i8, i8_r);
    else
		fprintf(stderr, "I8 values matches(%d)\n", i8);
  
    if(binn_list_get_item(sub, 1, &bu16_r))
        die("Unable to get binn item 1 from sub list");
	if(binn_to_uint16(bu16_r, &u16_r))
        die("Unable to get value of binn item 1");
	if(u16_r!=u16)
        fprintf(stderr, "U16 values differs, expected (%d), current (%d)\n", u16, u16_r);
    else
		fprintf(stderr, "U16 values matches(%d)\n", u16);

    fprintf(stderr, "%s: SUCCESS\n", __FUNCTION__);
    return 0;
}