#ifndef RM_PROGRAM_H
#define RM_PROGRAM_H

#include "value.h"
#include "opcode.h"
#include <stdint.h>

#define RM_OPCODE_BLOCK 20
#define RM_CONSTANT_BLOCK 20

typedef struct {
    // Determines the opcodes.
    uint64_t *opcodes;
    // Determines the number of opcodes in the program and the current capacity.
    size_t op_count, op_capacity;
    // Determines the constants to load.
    RMValue *constants;
    // Determines the number of constants in the program and the current capacity.
    size_t const_count, const_capacity;
    // Determines the registers in use.
    uint64_t registers, temp_registers, max_temp_registers;
} RMProgram;

// Initializes the program.
void rm_program_init(RMProgram *program);
// Adds a new opcode to the program.
void rm_program_add_opcode(RMProgram *program, uint64_t opcode);
// Adds a constant + the opcode index to the program.
void rm_program_add_constant_int(RMProgram *program, int64_t value);
// Add a new register & opcode to the VM and returns the ID.
uint64_t rm_program_add_register(RMProgram *program);
// Only adds the register but not the opcode.
uint64_t rm_program_make_register(RMProgram *program);
// Adds a new temp register but not the opcode.
uint64_t rm_program_make_temp_register(RMProgram *program);
// Only adds the register but not the opcode.
uint64_t rm_program_add_temp_register(RMProgram *program);
// Only adds n registers but not the opcodes. Returns the ID of the first available.
uint64_t rm_program_make_n_temp_registers(RMProgram *program, uint16_t n);
// Pops a temp register.
void rm_program_pop_temp_register(RMProgram *program);
// Pops n temp register.
void rm_program_pop_n_temp_registers(RMProgram *program, uint16_t n);
// Debugs the program.
void rm_program_debug(RMProgram *program);

#endif
