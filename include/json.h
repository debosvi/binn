
#ifndef BINN_JSON_H
#define BINN_JSON_H

#include <binn/binn.h>
#include <jansson.h>

char* binn_to_javascript(binn_t node);

char* binn_to_json(binn_t node);
binn_t json_to_binn(const char const *json);

json_t* binn_to_json_obj(binn_t node);
binn_t json_obj_to_binn(json_t *base);

#endif // BINN_JSON_H
