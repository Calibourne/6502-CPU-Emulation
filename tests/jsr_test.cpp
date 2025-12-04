#include "cputest.h"
#include "opcodes.h"

class JSR_Test : public CPU_Test {};

// Test Jump to Subroutine
TEST_F(JSR_Test, JumpToSubroutine_Test) {
    // given
    mem[RESET_VECTOR] = OP_CODES::INS_JSR; // 6 cycles
    mem[RESET_VECTOR + 1] = 0x42; 
    mem[RESET_VECTOR + 2] = 0x84; // 0x8442
    mem[0x8442] = OP_CODES::INS_LDA_IM; // 2 cycles
    mem[0x8443] = 0x42;

    // when
    CPU copy = cpu;
    s32 cyclesExec = cpu.execute(8, mem);

    // then
    ASSERT_EQ(cyclesExec, 8);
    ASSERT_EQ(cpu.StkPtr, 0x00FE);
    ASSERT_EQ(cpu.Acc, 0x42);
    ASSERT_EQ(cpu.Z, 0);
    ASSERT_EQ(cpu.N, 0);
}