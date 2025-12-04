#ifndef CPUTEST_H
#define CPUTEST_H

#include "gtest/gtest.h"
#include "cpu.h"
#include "memory.h"
#include "constants.h"

class CPU_Test : public ::testing::Test {
protected:
    virtual void SetUp() override {
        cpu.reset(mem);
    }
    virtual void TearDown() override {}
    public:
        Memory mem;
        CPU cpu;
};
#endif