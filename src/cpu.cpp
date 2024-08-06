#include "cpu.h"
#include "memory.h"
#include "constants.h"
#include "opcodes.h"


void CPU::reset(Memory& memory) {
    PC = RESET_VECTOR;
    StkPtr = STACK_START;
    Status = FLAGS_INIT;

    memory.initialize();
}

s32 CPU::execute(s32 cycles, Memory& memory) {
    u32 requeted = cycles;
    while (cycles > 0) {
        Byte ins = fetchByte(cycles, memory);
        switch (ins) {
            #pragma region LDA Instructions
            case OP_CODES::INS_LDA_IM: {
                Byte value = fetchByte(cycles, memory);
                
                setStatusLDA(value);
                break;
            }
            case OP_CODES::INS_LDA_ZP: {
                Byte zeroPageAddress = fetchByte(cycles, memory);
                
                Byte value = readByte(cycles, zeroPageAddress, memory);
                
                setStatusLDA(value);
                break;
            }
            case OP_CODES::INS_LDA_ZPX: {
                Byte zeroPageAddress = fetchByte(cycles, memory);
                
                zeroPageAddress += X;
                cycles--;
                
                Byte value = readByte(cycles, zeroPageAddress, memory);
                
                setStatusLDA(value);
                break;
            }
            #pragma endregion
            #pragma region jump instructions
            case OP_CODES::INS_JSR: {
                Word subAddress = fetchWord(cycles, memory);
                memory.writeWord(cycles, StkPtr, PC - 1);
                StkPtr -= 2;
                PC = subAddress;
                cycles--;
                break;
            }
            #pragma endregion
            default: {
                printf("Instruction not handled %d\n", ins);
                break;
            }
        }
    }
    
    s32 executed = requeted - cycles;
    return executed;
}

void CPU::setStatusLDA(Byte value) {
    Acc = value;
    Z = Acc == 0;
    N = (Acc & (1 << 7)) > 0;
}

Byte CPU::fetchByte(s32& cycles, Memory& memory) {
    Byte data = memory[PC];
    PC++;
    cycles--;
    return data;
}

Word CPU::fetchWord(s32& cycles, Memory& memory) {
    Word chunk1 = memory[PC];
    Word chunk2 = memory[PC + 1];
    Word data = endianness() ? (chunk2 << 8) | chunk1 : (chunk1 << 8) | chunk2;

    PC += 2;
    cycles -= 2;
    return data;
}

Byte CPU::readByte(s32& cycles, Byte address, Memory& memory) {
    Byte data = memory[address];
    cycles--;
    return data;
}