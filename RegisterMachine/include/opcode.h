#ifndef RM_OPCODE_H
#define RM_OPCODE_H

#include <stdint.h>

typedef enum {
    OP_LOAD, // OP_LOAD <Rdest> <constant>
    OP_ADD, // OP_ADD <Rdest> <Rop> <Rop>
    OP_PRINT, // OP_PRINT <Rop>
    OP_HALT // OP_HALT
} RMOpcode;

#endif
