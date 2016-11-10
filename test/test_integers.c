
#include <stdlib.h>
#include <stdio.h>

#include "test_binn.h"

static void die(const char const *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// LIST ///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#define INIT_TEST_LIST(name)                                \
    binn_t name=binn_list();                                \
    if(name==BINN_INVALID)                                  \
        die("Unable to create binn ##name");                \
    fprintf(stderr, "binn %s created (%d)\n", #name, name);

#define END_TEST_LIST(name)                                  \
    binn_free(name); 

static void test_list(void) {
    int8_t i8=-123, i8_2=0;
    uint8_t u8=129, u8_2=0, u8_3=0;
    
    fprintf(stderr, "\n\n%s: START\n", __FUNCTION__);
    
    INIT_TEST_LIST(head)

    fprintf(stderr, "\nget pos (%d), no data\n", 0);
    if(binn_list_get_int8(head, 10, &i8_2))
        fprintf(stderr, "Unable to get int8 value (normal case)\n"); 
    else 
        die("should have failed searching non existent element");
    
    fprintf(stderr, "\ninsert new int8\n");
    if(binn_list_add_int8(head, i8))
        die("Unable to add int8 value");  

    fprintf(stderr, "\ninsert new uint8\n");
    if(binn_list_add_uint8(head, u8))
        die("Unable to add uint8 value 1");  

    fprintf(stderr, "\ninsert new int8\n");
    if(binn_list_add_int8(head, u8))
        die("Unable to add int8 value 2");
    
    fprintf(stderr, "\nget pos (%d)\n", 0);
    if(binn_list_get_int8(head, 0, &i8_2))
        die("Unable to get pos 0 value");  
    fprintf(stderr, "result get pos (%d), value(%d)\n", 0, i8_2);
   
    fprintf(stderr, "\nget pos (%d)\n", 2);
    if(binn_list_get_uint8(head, 2, &u8_3))
        fprintf(stderr, "Unable to get pos 2 value\n");   
    else 
        die("should have failed searching bad type element");
   
    fprintf(stderr, "\nget pos (%d)\n", 1);
    if(binn_list_get_uint8(head, 1, &u8_2))
        die("Unable to get pos 1 value");   
    fprintf(stderr, "result get pos (%d), value(%d)\n", 1, u8_2);

    END_TEST_LIST(head)
    
    fprintf(stderr, "%s: END\n", __FUNCTION__);
} 
///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// MAP ///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#define INIT_TEST_MAP(name)                                 \
    binn_t name=binn_map();                                 \
    if(name==BINN_INVALID)                                  \
        die("Unable to create binn ##name");                \
    fprintf(stderr, "binn %s created (%d)\n", #name, name);

#define END_TEST_MAP(name)                                  \
    binn_free(name); 

static void test_map(void) {
    int8_t i8=-123, i8_2=0, i8_3=0;
    uint8_t u8=129, u8_2=0;
        
    fprintf(stderr, "\n\n%s: START\n", __FUNCTION__);
    
    INIT_TEST_MAP(head)

    fprintf(stderr, "\nget id (%d), no data\n", 0);
    if(binn_map_get_int8(head, 0, &i8_2))
        fprintf(stderr, "Unable to get int8 value (normal case)\n"); 
    else 
        die("should have failed searching non existent element");
    
    fprintf(stderr, "\ninsert id (%d)\n", 0);
    if(binn_map_set_int8(head, 0, i8))
        die("Unable to add int8 value");  

    fprintf(stderr, "\ninsert id (%d)\n", 1);
    if(binn_map_set_uint8(head, 1, u8))
        die("Unable to add uint8 value");  

    fprintf(stderr, "\ninsert id (%d), once again\n", 0);
    if(binn_map_set_int8(head, 0, i8))
        fprintf(stderr, "Unable to add int8 value (normal case)\n");  
    else die("Should have failed to add same id");
    
    fprintf(stderr, "\nget id (%d)\n", 0);
    if(binn_map_get_int8(head, 0, &i8_2))
        die("Unable to get id 0 value");  
    fprintf(stderr, "result get id (%d), value(%d)\n", 0, i8_2);
    
    fprintf(stderr, "\nget id (%d)\n", 2);
    if(binn_map_get_int8(head, 2, &i8_3))
        fprintf(stderr, "result get id (%d), value(%d) (fails normal)\n", 2, i8_3);
    else die("Should have failed to get unknown id");
   
    fprintf(stderr, "\nget id (%d)\n", 1);
    if(binn_map_get_uint8(head, 1, &u8_2))
        die("Unable to get id 1 value");   
    fprintf(stderr, "result get id (%d), value(%d)\n", 1, u8_2);

    END_TEST_MAP(head)
    
    fprintf(stderr, "%s: END\n", __FUNCTION__);
}    

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// OBJECT ////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#define INIT_TEST_OBJECT(name)                             \
    binn_t name=binn_object();                              \
    if(name==BINN_INVALID)                                  \
        die("Unable to create binn ##name");                \
    fprintf(stderr, "binn %s created (%d)\n", #name, name);

#define END_TEST_OBJECT(name)                              \
    binn_free(name); 

static void test_object(void) {
    int8_t i8=-123, i8_2=0, i8_3=0;
    uint8_t u8=129, u8_2=0;
    
    fprintf(stderr, "\n\n%s: START\n", __FUNCTION__);
    
    INIT_TEST_OBJECT(head)

    fprintf(stderr, "\nget key (%s), no data\n", "int8");
    if(binn_object_get_int8(head, "int8", &i8_2))
        fprintf(stderr, "Unable to get int8 value (normal case)\n"); 
    else 
        die("should have failed searching non existent element");
    
    fprintf(stderr, "\ninsert key (%s)\n", "int8");
    if(binn_object_set_int8(head, "int8", i8))
        die("Unable to add int8 value");  

    fprintf(stderr, "\ninsert key (%s)\n", "uint8");
    if(binn_object_set_uint8(head, "uint8", u8))
        die("Unable to add uint8 value");  

    fprintf(stderr, "\ninsert key (%s), once again\n", "int8");
    if(binn_object_set_int8(head, "int8", i8))
        fprintf(stderr, "Unable to add int8 value (normal case)\n");  
    else die("Should have failed to add same key");
    
    fprintf(stderr, "\nget key (%s)\n", "int8");
    if(binn_object_get_int8(head, "int8", &i8_2))
        die("Unable to get int8 value");  
    fprintf(stderr, "result get key (%s), value(%d)\n", "int8", i8_2);
    
    fprintf(stderr, "\nget key (%s)\n", "int16");
    if(binn_object_get_int8(head, "int16", &i8_3))
        fprintf(stderr, "result get key (%s), value(%d) (fails normal)\n", "int8", i8_3);
    else die("Should have failed to get unknown key");
   
    fprintf(stderr, "\nget key (%s)\n", "uint8");
    if(binn_object_get_uint8(head, "uint8", &u8_2))
        die("Unable to get uint8 value");  
    fprintf(stderr, "result get key (%s), value(%d)\n", "uint8", u8_2);


    END_TEST_OBJECT(head)
    
    fprintf(stderr, "%s: END\n", __FUNCTION__);
}    
    
int main(int ac, char** av) {
    (void)ac;
    (void)av;
    
    test_list();
    test_map();
    test_object();
    
    fprintf(stderr, "%s: SUCCESS\n", __FUNCTION__);
    return 0;
}