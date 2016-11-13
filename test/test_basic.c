
#include <stdlib.h>
#include <stdio.h>

#include "test_binn.h"

static void die(const char const *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

///////////////////////////////////////////////////////////////////////////////
#define INIT_TEST_BASIC(name,type,value)           			\
    const type v_##name=value;								\
	type r_##name=0;										\
	binn_t b_##name=binn_##name(value);                     \
    if(b_##name==BINN_INVALID)                              \
        die("Unable to create binn type ##type");           \
    fprintf(stderr, "binn type %s created\n", #type);		\
	if(binn_to_##name(b_##name, &r_##name))					\
		die("Get value fails for type ##type");           	\
	if(r_##name!=v_##name)									\
		fprintf(stderr, "Value differs for type %s, values(%016x,%016x)\n", #type, r_##name, v_##name);           	\
    fprintf(stderr, "binn values match for type %s\n", #type);	

#define END_TEST_BASIC(name)	                            \
    binn_free(b_##name);                            

///////////////////////////////////////////////////////////////////////////////
#define INIT_TEST_COMPLEX(name)                             \
    binn_t name=binn_##name();                              \
    if(name==BINN_INVALID)                                  \
        die("Unable to create binn ##name");                \
    fprintf(stderr, "binn %s created (%d)\n", #name, name);

#define END_TEST_COMPLEX(name)                              \
    binn_free(name);                            
    
///////////////////////////////////////////////////////////////////////////////
int main(int ac, char** av) {
    (void)ac;
    (void)av;
	
	INIT_TEST_BASIC(int8, int8_t, 123)
	INIT_TEST_BASIC(int16, int16_t, 456)
	INIT_TEST_BASIC(int32, int32_t, 123456789)
	INIT_TEST_BASIC(int64, int64_t, 0x123456789012345)
	INIT_TEST_BASIC(uint8, uint8_t, 123)
	INIT_TEST_BASIC(uint16, uint16_t, 123)
	INIT_TEST_BASIC(uint32, uint32_t, 123)
	INIT_TEST_BASIC(uint64, uint64_t, 123)
	INIT_TEST_BASIC(float, float, 123)
	INIT_TEST_BASIC(double, double, 123)
	INIT_TEST_BASIC(bool, char, 1)
    END_TEST_BASIC(int8)
    END_TEST_BASIC(int16)
    END_TEST_BASIC(int32)
    END_TEST_BASIC(int64)
    END_TEST_BASIC(uint8)
    END_TEST_BASIC(uint16)
    END_TEST_BASIC(uint32)
    END_TEST_BASIC(uint64)
    END_TEST_BASIC(float)
    END_TEST_BASIC(double)
    END_TEST_BASIC(bool)
    
    INIT_TEST_COMPLEX(list)
    INIT_TEST_COMPLEX(map)
    INIT_TEST_COMPLEX(object)
    
    END_TEST_COMPLEX(list)
    END_TEST_COMPLEX(map)
    END_TEST_COMPLEX(object)
    
    return 0;
}