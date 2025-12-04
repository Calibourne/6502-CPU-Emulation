#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

using Byte = unsigned char;
using Word = unsigned short;
using u32 = unsigned int;
using s32 = signed int;

#define KB 1024
#define MEM_SIZE 64
#define little_endian "little"
#define big_endian "big"

#define RESET_VECTOR 0xFFFC
#define STACK_START 0x0100
#define FLAGS_INIT 0x00

// Check endianness at compile time
#if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    #define IS_LITTLE_ENDIAN 1
#elif defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
    #define IS_LITTLE_ENDIAN 0
#else
    #include <endian.h>
    #if __BYTE_ORDER == __LITTLE_ENDIAN
        #define IS_LITTLE_ENDIAN 1
    #elif __BYTE_ORDER == __BIG_ENDIAN
        #define IS_LITTLE_ENDIAN 0
    #else
        #error "Cannot determine endianness"
    #endif
#endif

#define endianness() (IS_LITTLE_ENDIAN)

#endif