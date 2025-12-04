#include "opcodes.h"
#include "cputest.h"

TEST_F(CPU_Test, Reset_CPU) {
    ASSERT_EQ(cpu.PC, RESET_VECTOR);
    ASSERT_EQ(cpu.StkPtr, STACK_START);
    ASSERT_EQ(cpu.Status, FLAGS_INIT);
}

TEST_F(CPU_Test, Exexute_None) {
    s32 cyclesExec = cpu.execute(0, mem);
    ASSERT_EQ(cyclesExec, 0);
}

TEST_F(CPU_Test, Execute_More_Than_Requested_If_Instruction_Takes_More_Cycles) {
    mem[RESET_VECTOR] = OP_CODES::INS_LDA_IM;
    mem[RESET_VECTOR + 1] = 0x42;
    
    s32 cyclesExec = cpu.execute(1, mem);
    ASSERT_EQ(cyclesExec, 2);
}

TEST_F(CPU_Test, Invalid_Opcode_Doesnt_Resault_In_Infinite_Loop) {
    constexpr Byte INVALID_OPCODE = 0xFF;
    constexpr s32 testCycles = 5;
    mem[RESET_VECTOR] = INVALID_OPCODE;
    s32 cyclesExec = cpu.execute(testCycles, mem);
    ASSERT_EQ(cyclesExec, testCycles);
}