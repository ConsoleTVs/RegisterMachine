#include "include/program.h"

#include <stdio.h>
#include <stdlib.h>

static char *opcode_string[] = {
    "LOAD", "ADD", "PRINT", "HALT"
};

void rm_program_init(RMProgram *program)
{
    program->opcodes = NULL;
    program->op_capacity = 0;
    program->op_count = 0;
    program->constants = NULL;
    program->const_capacity = 0;
    program->const_count = 0;
    program->registers = 0;
    program->temp_registers = 0;
}

void rm_program_add_opcode(RMProgram *program, uint64_t opcode)
{
    // Allocate or reallocate the space if neeeded.
    if (program->opcodes == NULL) {
        // Allocate the first block of space.
        program->opcodes = malloc(sizeof(RMOpcode) * (program->op_capacity = RM_OPCODE_BLOCK));
    } else if (program->op_count == program->op_capacity) {
        // Reallocate space to allow more opcodes.
        program->opcodes = realloc(program->opcodes, sizeof(RMOpcode) * (program->op_capacity += RM_OPCODE_BLOCK));
    }
    // Add the opcode to the opcode list.
    program->opcodes[program->op_count++] = opcode;
}

void rm_program_add_constant_int(RMProgram *program, int64_t value)
{
    // Allocate or reallocate the space if neeeded.
    if (program->constants == NULL) {
        // Allocate the first block of space.
        program->constants = malloc(sizeof(RMValue) * (program->const_capacity = RM_CONSTANT_BLOCK));
    } else if (program->const_count == program->const_capacity) {
        // Reallocate space to allow more constants.
        program->constants = realloc(program->constants, sizeof(RMValue) * (program->const_capacity += RM_CONSTANT_BLOCK));
    }
    // Add the constant to the constant list.
    rm_value_create_int(program->constants + program->const_count, value);
    // Add the opcode.
    rm_program_add_opcode(program, program->const_count++);
}

uint64_t rm_program_add_register(RMProgram *program)
{
    rm_program_add_opcode(program, rm_program_make_register(program));

    return program->registers - 1;
}

uint64_t rm_program_make_register(RMProgram *program)
{
    return program->registers++;
}

uint64_t rm_program_add_temp_register(RMProgram *program)
{
    rm_program_add_opcode(program, rm_program_make_temp_register(program));

    return program->temp_registers - 1;
}

uint64_t rm_program_make_temp_register(RMProgram *program)
{
    return rm_program_make_n_temp_registers(program, 1);
}

uint64_t rm_program_make_n_temp_registers(RMProgram *program, uint16_t n)
{
    program->temp_registers += n;

    if (program->temp_registers > program->max_temp_registers) {
        program->max_temp_registers = program->temp_registers;
    }

    return program->temp_registers - n;
}

void rm_program_pop_temp_register(RMProgram *program)
{
    rm_program_pop_n_temp_registers(program, 1);
}

void rm_program_pop_n_temp_registers(RMProgram *program, uint16_t n)
{
    program->temp_registers -= n;
}

void rm_program_debug(RMProgram *program)
{
    for (size_t i = 0; i < program->op_count; i++) {
        printf("%6llu -> %s ", i, opcode_string[program->opcodes[i]]);
        switch (program->opcodes[i]) {
            case OP_LOAD: {
                printf("R%llu ", program->opcodes[++i]);
                printf("C%llu\n", program->opcodes[++i]);
                break;
            }
            case OP_ADD: {
                printf("R%llu ", program->opcodes[++i]);
                printf("R%llu ", program->opcodes[++i]);
                printf("R%llu\n", program->opcodes[++i]);
                break;
            }
            case OP_PRINT: {
                printf("R%llu\n", program->opcodes[++i]);
                break;
            }
            default: { puts("\n"); break; }
        }
    }
}
