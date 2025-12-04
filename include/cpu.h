#ifndef CPU_H
#define CPU_H

/**   
                  6502 CPU Architecture
         =======================================

         +-------------------------------------+
         |                CPU                  |
         +--------------+----------------------+
         |   StkPtr     |         PC           |
         | (Stack Ptr)  |  (Program Counter)   |
         |--------------+----------------------+
         |                 Acc                 |
         |            (Accumulator)            |
         +------------------+------------------+
         |        X         |        Y         |
         |    (Register)    |    (Register)    |
         +------------------+------------------+
         |            Status Flags             |
         |  +---+---+---+---+---+---+---+---+  |
         |  | C | Z | I | D | B | U | V | N |  |
         |  +---+---+---+---+---+---+---+---+  |
         |  |0/1|0/1|0/1|0/1|0/1|N/A|0/1|0/1|  |
         +-------------------------------------+

                C: Carry Flag
                Z: Zero Flag
                I: Interrupt Disable
                D: Decimal Mode
                B: Break Command
                U: Unused
                V: Overflow Flag
                N: Negative Flag
**/

#include "constants.h"
#include "memory.h"

struct CPU {
  Word StkPtr; // Stack Pointer
  Word PC;     // Program Counter

  Byte Acc;  // Accumulator
  Byte X, Y; // Registers

  /* Status Flags */
  union {
    struct {
      Byte C : 1; // Carry Flag
      Byte Z : 1; // Zero Flag
      Byte I : 1; // Interrupt Disable
      Byte D : 1; // Decimal Mode
      Byte B : 1; // Break Command
      Byte U : 1; // Unused
      Byte V : 1; // Overflow Flag
      Byte N : 1; // Negative Flag
    };
    Byte Status;  // Access all flags at once
  };

  void reset( Memory& memory );
  s32 execute(s32 cycles, Memory& memory); 
  void setStatusLDA(Byte value);
  Byte fetchByte(s32& cycles, Memory& memory);
  Word fetchWord(s32& cycles, Memory& memory);
  Byte readByte(s32& cycles, Byte address, Memory& memory);
};

#endif