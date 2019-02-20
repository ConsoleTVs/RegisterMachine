#ifndef RM_MACHINE_H
#define RM_MACHINE_H

#include "program.h"

typedef struct {
    // Stores the program to be executed.
    RMProgram program;
    // Stores the current address of the opcode.
    uint64_t *current;
    // Stores the registers used by the virtual machine.
    RMValue *registers;
} RM;

// Initializes the register machine.
void rm_init(RM *rm);
// Runs the virtual machine stored program.
void rm_run(RM *rm);

#endif
