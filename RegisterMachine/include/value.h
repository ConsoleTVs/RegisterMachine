#ifndef RM_VALUE_H
#define RM_VALUE_H

#include <stdio.h>
#include <stdint.h>

typedef enum {
    VAL_INT, VAL_FLOAT, VAL_STRING
} RMValueType;

typedef struct {
    RMValueType type;
    union {
        int64_t int_val;
        float float_val;
        char *string_val;
    };
} RMValue;

void rm_value_create_int(RMValue *value, int64_t int_val);
void rm_value_create_float(RMValue *value, float float_val);
void rm_value_create_string(RMValue *value, char *string_val);
void rm_value_print(RMValue *value);

#endif
