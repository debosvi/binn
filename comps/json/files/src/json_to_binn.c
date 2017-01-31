
#include "private/json_p.h"

///////////////////////////////////////////////////////////////////////////////
binn_t json_obj_to_binn(json_t *base) {
    binn_t head=BINN_INVALID;
    json_t  *value=0;

    switch (json_typeof(base)) {
        case JSON_OBJECT:
        {
            const char *key=0;
            head = binn_object();
            json_object_foreach(base, key, value) {
                if(binn_object_add_item(head, key, json_obj_to_binn(value))) break;
            }
        }
            break;

        case JSON_ARRAY:
        {
            unsigned int i=0;
            size_t  count=json_array_size(base);
            head = binn_list();
            for (i = 0; i < (unsigned int)count; i++) {
                value = json_array_get(base, i);
                if(binn_list_add_item(head, json_obj_to_binn(value))) break;
            }
        }
            break;

        case JSON_STRING:
            head = binn_string(json_string_value(base));
            break;

        case JSON_INTEGER:
            head = binn_int64(json_integer_value(base));
            break;

        case JSON_REAL:
            head = binn_double(json_real_value(base));
            break;

        case JSON_TRUE:
            head = binn_bool(1);
            break;

        case JSON_FALSE:
            head = binn_bool(0);
            break;

        // case JSON_NULL:
            // return binn_null();
            // break;

        default:
            BINN_PRINT_ERROR("%s: JSON type not yet managed (%d)\n", __FUNCTION__, json_typeof(base));
            break;
    }

    return head;
}

///////////////////////////////////////////////////////////////////////////////
binn_t json_to_binn(const char const *json) {
    json_t *base=0;
    binn_t head=BINN_INVALID;

    base = json_loads(json, 0, NULL);
    if(!base) return BINN_INVALID;

    head = json_obj_to_binn(base);

    json_decref(base);
    return head;
}