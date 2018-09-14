#pragma once

#include <cstdint>
#include <iostream>

#define R_SIZE 11

namespace Emulator {
    namespace Decoder {
        enum InstType {
            ADD, SUB, DIV, MUL, BRZ, BRNZ, IBRZ, BLZ,
            MOV, LOADM, STOREM, LOADI, WRITE, READ, EXIT
        };

        struct Inst {
            InstType Type;
            int A, B;
            int Imm;
            int Addrs;
        };
        
        Inst* getCode(const std::string i); 
        void printInst(Inst *X); 
    }
} 
