#include "constants.h"
#include "opcodes.h"
#include "memory.h"
#include "cpu.h"

#include <stdio.h>

int main() {
  printf("machine endianess: %s\n", endianness() ? little_endian : big_endian);
  
  Memory mem;
  CPU cpu;

  #pragma region Test LDA_IM Instruction
  printf("Testing LDA_IM Instruction\n");
  cpu.reset(mem);
  mem[RESET_VECTOR + 0] = OP_CODES::INS_LDA_IM;
  mem[RESET_VECTOR + 1] = 0x42;
  cpu.execute(2, mem);
  assert(cpu.Acc == 0x42);
  assert(cpu.Z == 0);
  assert(cpu.N == 0);
  printf("Passed\n");
  #pragma endregion

  #pragma region Test LDA_ZP Instruction
  printf("Testing LDA_ZP Instruction\n");
  cpu.reset(mem);
  mem[RESET_VECTOR + 0] = OP_CODES::INS_LDA_ZP;
  mem[RESET_VECTOR + 1] = 0x42;
  mem[0x42] = 0x84;
  cpu.execute(3, mem);
  assert(cpu.Acc == 0x84);
  assert(cpu.Z == 0);
  assert(cpu.N == 1);
  printf("Passed\n");
  #pragma endregion

  #pragma region Test LDA_ZPX Instruction
  printf("Testing LDA_ZPX Instruction\n");
  cpu.reset(mem);
  mem[RESET_VECTOR + 0] = OP_CODES::INS_LDA_ZPX;
  mem[RESET_VECTOR + 1] = 0x42;
  mem[0x42] = 0x84;
  cpu.X = 0x02; // 0x42 + 0x02 = 0x44
  mem[0x44] = 0x44;
  cpu.execute(4, mem); // 4 cycles because we need to read the X register
  assert(cpu.Acc == 0x44); // 0x44
  assert(cpu.Z == 0);
  assert(cpu.N == 0);
  printf("Passed\n");
  #pragma endregion
  #pragma region Test JSR Instruction
  printf("Testing JSR Instruction\n");
  cpu.reset(mem);
  mem[RESET_VECTOR + 0] = OP_CODES::INS_JSR;
  mem[RESET_VECTOR + 1] = 0x00;
  mem[RESET_VECTOR + 2] = 0x42; // 6 cycles for JSR
  mem[0x4200] = OP_CODES::INS_LDA_IM;
  mem[0x4201] = 0x84; // 2 cycles for LDA_IM
  cpu.execute(8, mem); // 8 cycles overall
  assert(cpu.Acc == 0x84); // 0x84
  assert(cpu.Z == 0);
  assert(cpu.N == 1);
  printf("Passed\n");
  #pragma endregion
  
  printf("All tests passed!\n");
  return 0;
}
