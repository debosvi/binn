
#include "priv/binn.h"

/*************************************************************************************/
binn_t binn_string(const char const *value) {
    return binn_new(BINN_TYPE_STRING, value, strlen(value));
}