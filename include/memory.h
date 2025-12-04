#ifndef MEMORY_H
#define MEMORY_H
#include "constants.h"

struct Memory {
  static constexpr u32 MAX_MEM = MEM_SIZE * KB;
  Byte Data[MAX_MEM];

  void initialize();
  Byte operator[](u32 address) const; // read 1 byte
  Byte& operator[](u32 address); // write 1 byte
  Word writeWord(s32& cycles, Word address, Word value);
};

#endif