
#include <stdlib.h>
#include <stdio.h>

#include "test_binn.h"

static void die(const char const *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

///////////////////////////////////////////////////////////////////////////////
int main(int ac, char** av) {
    int8_t i8=-123;
    (void)ac;
    (void)av;
    
    binn_t head=binn_object();   
    binn_t sub=binn_map();   
    binn_t sub2=BINN_INVALID;   
    
    fprintf(stderr, "head (%d)\n", head);
    fprintf(stderr, "sub (%d)\n", sub);

    fprintf(stderr, "\ninsert key (%s)\n", "int8");
    if(binn_map_set_int8(sub, 2, i8))
        die("Unable to add int8 value");  
    if(binn_map_set_int8(sub, 1, i8))
        die("Unable to add int8 value");  
    
    fprintf(stderr, "\ninsert sub into head\n");
    if(binn_object_set_map(head, "sub", sub))
        die("Unable to add sub into head value");  
    
    fprintf(stderr, "\npouplate success\n");
    fprintf(stderr, "JSON: sub, result (%s)\n", binn_to_json_str(sub));
    fprintf(stderr, "JSON: head, result (%s)\n", binn_to_json_str(head));
  
    if(binn_object_get_map(head, "sub", &sub2))
        die("Unable to get sub from head value");  

    fprintf(stderr, "sub2 (%d)\n", sub2);
    fprintf(stderr, "JSON: sub2, result (%s)\n", binn_to_json_str(sub2));

    fprintf(stderr, "%s: SUCCESS\n", __FUNCTION__);
    return 0;
}