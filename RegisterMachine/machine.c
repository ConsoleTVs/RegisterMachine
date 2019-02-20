#include "include/machine.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define READ_INSTRUCTION() (*rm->current++)

void rm_init(RM *rm)
{
    rm_program_init(&rm->program);
    rm->current = NULL;
    rm->registers = NULL;
}

void rm_run(RM *rm)
{
    // Allocate the space to allocate the registers.
    rm->registers = malloc(sizeof(RMValue) * (rm->program.registers + rm->program.max_temp_registers));
    // Set the first operation.
    rm->current = rm->program.opcodes;
    // Switch dispatch.
    for (;;) {
        switch (READ_INSTRUCTION()) {
            case OP_LOAD: {
                uint64_t dest = READ_INSTRUCTION();
                uint64_t constant = READ_INSTRUCTION();
                printf("Value loaded: %u\n", constant);
                rm_value_print(&rm->program.constants[constant]);
                printf("ok\n");
                rm->registers[dest] = rm->program.constants[constant];
                break;
            }
            case OP_ADD: {
                uint64_t dest = READ_INSTRUCTION();
                RMValue op1 = rm->registers[READ_INSTRUCTION()];
                RMValue op2 = rm->registers[READ_INSTRUCTION()];
                if (op1.type == VAL_INT && op2.type == VAL_INT) {
                    rm_value_create_int(rm->registers + dest, op1.int_val + op2.int_val);
                } else if (op1.type == VAL_FLOAT && op2.type == VAL_FLOAT) {
                    rm_value_create_int(rm->registers + dest, op1.float_val + op2.float_val);
                } else if (op1.type == VAL_STRING && op2.type == VAL_STRING) {
                    char *buffer = malloc(sizeof(RMValue) * (strlen(op1.string_val) + strlen(op2.string_val)) + 1);
                    strcpy(buffer, op1.string_val);
                    strcat(buffer, op2.string_val);
                    rm_value_create_string(rm->registers + dest, buffer);
                } else {
                    fprintf(stderr, "Invalid addition operation");
                    exit(EXIT_FAILURE);
                }
                break;
            }
            case OP_PRINT: {
                rm_value_print(&rm->registers[READ_INSTRUCTION()]);
                break;
            }
            case OP_HALT: { return; }
        }
    }
}
