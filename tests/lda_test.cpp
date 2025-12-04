#include "cputest.h"
#include "opcodes.h"

class LDA_Test : public CPU_Test {};
#define MASK 0x3C // 0011 1100

void assertLDAExecution(CPU& cpu, Memory& mem, s32 cyclesExec, s32 expectedCycles ,Byte expectedAcc, bool expectedZ, bool expectedN, Byte expectedStatus) {
    ASSERT_EQ(cyclesExec, expectedCycles);
    ASSERT_EQ(cpu.Acc, expectedAcc);
    ASSERT_EQ(cpu.Z, expectedZ);
    ASSERT_EQ(cpu.N, expectedN);
    ASSERT_EQ(cpu.Status & MASK, expectedStatus & MASK); // assert the other 6 flags are not affected
}

// Test LDA Immediate
TEST_F(LDA_Test, Load_Accumulator_Immediate_Mode) {
    // given
    mem[RESET_VECTOR] = OP_CODES::INS_LDA_IM;
    mem[RESET_VECTOR + 1] = 0x42;
    
    // when
    CPU copy = cpu;
    s32 cyclesExec = cpu.execute(2, mem);

    // then
    assertLDAExecution(cpu, mem, cyclesExec, 2, 0x42, false, false, copy.Status);
}

// Test LDA ZeroPage
TEST_F(LDA_Test, Load_Accumulator_ZeroPage) {
    // given
    mem[RESET_VECTOR] = OP_CODES::INS_LDA_ZP;
    mem[RESET_VECTOR + 1] = 0x42;
    mem[0x42] = 0x84;
    
    // when
    CPU copy = cpu;
    s32 cyclesExec = cpu.execute(3, mem);

    // then
    assertLDAExecution(cpu, mem, cyclesExec, 3, 0x84, false, true, copy.Status);

}

// Test LDA ZeroPage X no wrap
TEST_F(LDA_Test, Load_Accumulator_ZeroPageX_NoWrap) {
    // given
    cpu.X = 5;

    mem[RESET_VECTOR] = OP_CODES::INS_LDA_ZPX;
    mem[RESET_VECTOR + 1] = 0x42;
    mem[0x0042 + 5] = 0x7;
    
    // when
    CPU copy = cpu;
    s32 cyclesExec = cpu.execute(4, mem);

    // then
    assertLDAExecution(cpu, mem, cyclesExec, 4, 0x7, false, false, copy.Status);
}

// Test LDA ZeroPage X wrap
TEST_F(LDA_Test, Load_Accumulator_ZeroPageX_Wrap) {
    // given
    cpu.X = 0xFF; // set X register
    mem[RESET_VECTOR] = OP_CODES::INS_LDA_ZPX;
    mem[RESET_VECTOR + 1] = 0x80;
    mem[0x007F] = 0x37;

    // when
    CPU copy = cpu;
    s32 cyclesExec = cpu.execute(4, mem);

    // then
    assertLDAExecution(cpu, mem, cyclesExec, 4, 0x37, false, false, copy.Status);
}

TEST_F(LDA_Test, Load_Accumulator_Absolute) {
    // given
    mem[RESET_VECTOR] = OP_CODES::INS_LDA_ABS;
    mem[RESET_VECTOR + 1] = 0x80;
    mem[RESET_VECTOR + 2] = 0x44; // 0x4480
    mem[0x4480] = 0x84;

    // when
    CPU copy = cpu;
    s32 cyclesExec = cpu.execute(4, mem);

    // then
    assertLDAExecution(cpu, mem, cyclesExec, 4, 0x84, false, true, copy.Status);
}

TEST_F(LDA_Test, Load_Accumulator_AbsoluteX) {
    // given
    cpu.X = 0x5;
    mem[RESET_VECTOR] = OP_CODES::INS_LDA_ABX;
    mem[RESET_VECTOR + 1] = 0x80;
    mem[RESET_VECTOR + 2] = 0x44; // 0x4480
    mem[0x4485] = 0x84;

    // when
    CPU copy = cpu;
    s32 cyclesExec = cpu.execute(4, mem);

    // then
    assertLDAExecution(cpu, mem, cyclesExec, 4, 0x84, false, true, copy.Status);
}

TEST_F(LDA_Test, Load_Accumulator_AbsoluteY) {
    // given
    cpu.Y = 0x5;
    mem[RESET_VECTOR] = OP_CODES::INS_LDA_ABY;
    mem[RESET_VECTOR + 1] = 0x80;
    mem[RESET_VECTOR + 2] = 0x44; // 0x4480
    mem[0x4485] = 0x84;

    // when
    CPU copy = cpu;
    s32 cyclesExec = cpu.execute(4, mem);

    // then
    assertLDAExecution(cpu, mem, cyclesExec, 4, 0x84, false, true, copy.Status);
}

TEST_F(LDA_Test, Load_Accumulator_IndirectX) {
    // given
    cpu.X = 0x5;
    mem[RESET_VECTOR] = OP_CODES::INS_LDA_INX;
    mem[RESET_VECTOR + 1] = 0x42;
    mem[0x47] = 0x80;
    mem[0x48] = 0x44; // 0x4480
    mem[0x4485] = 0x84;

    // when
    CPU copy = cpu;
    s32 cyclesExec = cpu.execute(6, mem);

    // then
    assertLDAExecution(cpu, mem, cyclesExec, 6, 0x84, false, true, copy.Status);
}

TEST_F(LDA_Test, Load_Accumulator_IndirectY) {
    // given
    cpu.Y = 0x5;
    mem[RESET_VECTOR] = OP_CODES::INS_LDA_INY;
    mem[RESET_VECTOR + 1] = 0x42;
    mem[0x42] = 0x80;
    mem[0x43] = 0x44; // 0x4480
    mem[0x4485] = 0x84;

    // when
    CPU copy = cpu;
    s32 cyclesExec = cpu.execute(5, mem);

    // then
    assertLDAExecution(cpu, mem, cyclesExec, 5, 0x84, false, true, copy.Status);
}

TEST_F(LDA_Test, Load_Accumulator_IndirectY_Wrap) {
    // given
    cpu.Y = 0xFF;
    mem[RESET_VECTOR] = OP_CODES::INS_LDA_INY;
    mem[RESET_VECTOR + 1] = 0x42;
    mem[0x42] = 0x80;
    mem[0x43] = 0x44; // 0x4480
    mem[0x457F] = 0x84;

    // when
    CPU copy = cpu;
    s32 cyclesExec = cpu.execute(5, mem);

    // then
    assertLDAExecution(cpu, mem, cyclesExec, 5, 0x84, false, true, copy.Status);
}

TEST_F(LDA_Test, Load_Accumulator_IndirectY_No_Wrap) {
    // given
    cpu.Y = 0x5;
    mem[RESET_VECTOR] = OP_CODES::INS_LDA_INY;
    mem[RESET_VECTOR + 1] = 0x42;
    mem[0x42] = 0x80;
    mem[0x43] = 0x44; // 0x4480
    mem[0x4485] = 0x84;

    // when
    CPU copy = cpu;
    s32 cyclesExec = cpu.execute(5, mem);

    // then
    assertLDAExecution(cpu, mem, cyclesExec, 5, 0x84, false, true, copy.Status);
}