#include "RegisterMachine/include/machine.h"

int main()
{
    // Initiate the register machine.
    RM rm;
    rm_init(&rm);

    // Add some opcodes to the program.
    // LOAD R1 10
    rm_program_add_opcode(&rm.program, OP_LOAD);
    uint64_t r1 = rm_program_add_register(&rm.program);
    rm_program_add_constant_int(&rm.program, 10);
    // LOAD R2 20
    rm_program_add_opcode(&rm.program, OP_LOAD);
    uint64_t r2 = rm_program_add_register(&rm.program);
    rm_program_add_constant_int(&rm.program, 20);
    printf("-\n");
    printf("%p\n", &rm.program.constants);
    rm_value_print(&rm.program.constants[0]);
    rm_value_print(&rm.program.constants[1]);
    printf("-\n");
    // ADD R3 R1 R2 (R3 = R1 + R2)
    rm_program_add_opcode(&rm.program, OP_ADD);
    uint64_t r3 = rm_program_add_register(&rm.program);
    rm_program_add_opcode(&rm.program, r1);
    rm_program_add_opcode(&rm.program, r2);
    printf("--\n");
    printf("%p\n", &rm.program.constants);
    rm_value_print(&rm.program.constants[0]);
    rm_value_print(&rm.program.constants[1]);
    printf("--\n");
    // PRINT R3
    rm_program_add_opcode(&rm.program, OP_PRINT);
    rm_program_add_opcode(&rm.program, r3);
    printf("---\n");
    printf("%p\n", &rm.program.constants);
    rm_value_print(&rm.program.constants[0]);
    rm_value_print(&rm.program.constants[1]);
    printf("---\n");
    // HALT
    rm_program_add_opcode(&rm.program, OP_HALT);
    printf("----\n");
    printf("%p\n", &rm.program.constants);
    rm_value_print(&rm.program.constants[0]);
    rm_value_print(&rm.program.constants[1]);
    printf("----\n");
    // Debug the program
    rm_program_debug(&rm.program);

    // Run the program
    rm_run(&rm);
}
