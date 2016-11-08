
#include <stdlib.h>
#include <stdio.h>

#include "test_binn.h"

static void die(const char const *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

#define INIT_TEST_COMPLEX(name)                             \
    binn_t name=binn_object();                              \
    if(name==BINN_INVALID)                                  \
        die("Unable to create binn ##name");                \
    fprintf(stderr, "binn %s created (%d)\n", #name, name);

#define END_TEST_COMPLEX(name)                              \
    binn_free(name);                            
    
int main(int ac, char** av) {
    int8_t i8=-123, i8_2=0;
    uint8_t u8=129, u8_2=0;
    (void)ac;
    (void)av;
    
    INIT_TEST_COMPLEX(head)

    fprintf(stderr, "\nget key (%s), no data\n", "int8");
    if(binn_object_get_int8(head, "int8", &i8_2))
        fprintf(stderr, "Unable to add int8 value (normal case)\n"); 
    else 
        die("should have failed searching non existent element");
    
    fprintf(stderr, "\ninsert key (%s)\n", "int8");
    if(binn_object_set_int8(head, "int8", i8))
        die("Unable to add int8 value");  

    fprintf(stderr, "\ninsert key (%s)\n", "uint8");
    if(binn_object_set_int8(head, "uint8", u8))
        die("Unable to add int8 value");  

    fprintf(stderr, "\ninsert key (%s), once again\n", "int8");
    if(binn_object_set_int8(head, "int8", i8))
        fprintf(stderr, "Unable to add int8 value (normal case)\n");  
    
    fprintf(stderr, "\nget key (%s)\n", "int8");
    if(binn_object_get_int8(head, "int8", &i8_2))
        die("Unable to get int8 value");  
    fprintf(stderr, "result get key (%s), value(%d)\n", "int8", i8_2);
   
    fprintf(stderr, "\nget key (%s)\n", "uint8");
    if(binn_object_get_uint8(head, "uint8", &u8_2))
        die("Unable to get uint8 value");  
    fprintf(stderr, "result get key (%s), value(%d)\n", "uint8", u8_2);


    END_TEST_COMPLEX(head)
    
    return 0;
}