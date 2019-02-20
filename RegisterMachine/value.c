#include "include/value.h"
#include <string.h>
#include <stdlib.h>

void rm_value_create_int(RMValue *value, int64_t int_val)
{
    value->type = VAL_INT;
    value->int_val = int_val;
}

void rm_value_create_float(RMValue *value, float float_val)
{
    value->type = VAL_FLOAT;
    value->float_val = float_val;
}

void rm_value_create_string(RMValue *value, char *string_val)
{
    value->type = VAL_STRING;
    value->string_val = malloc(sizeof(char) * (strlen(string_val) + 1));
    strcpy(value->string_val, string_val);
}

void rm_value_print(RMValue *value)
{
    switch (value->type) {
        case VAL_INT: { printf("<%d>\n", value->int_val); break; }
        case VAL_FLOAT: { printf("<%f>\n", value->float_val); break; }
        case VAL_STRING: { printf("<%s>\n", value->string_val); break; }
    }
    printf("Type: %u\n", value->type);
}

void rm_value_delete(RMValue *value)
{
    switch (value->type) {
        case VAL_STRING: { free(value->string_val); break; }
        default: { break; }
    }

    free(value);
}
