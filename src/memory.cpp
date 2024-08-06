#include "memory.h"

void Memory::initialize() {
  for (u32 i = 0; i < MAX_MEM; i++) {
    Data[i] = 0;
  }
}

Byte Memory::operator[](u32 address) const {
  assert (address < MAX_MEM);
  return Data[address];
}

Byte& Memory::operator[](u32 address) {
  assert (address < MAX_MEM);
  return Data[address];
}

Word Memory::writeWord(s32 &cycles, Word address, Word value)
{
  assert(address + 1 < MAX_MEM);
  Data[address] = value & 0xFF;
  Data[address + 1] = (value >> 8) & 0xFF;
  cycles -= 2;
  return address;
}
