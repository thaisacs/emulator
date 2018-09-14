#pragma once

#include "Machine.hpp"

namespace Emulator {
    class Interpreter {
        private:
            Machine M;
            void ADD(int reg1, int reg2);
            void SUB(int reg1, int reg2); 
            void LOADI(int reg, int Imm); 
            void WRITE(int reg); 
            void DIV(int reg1, int reg2); 
            void MUL(int reg1, int reg2); 
            void READ(int reg); 
            void MOV(int reg1, int reg2); 
            void BRZ(int reg, int d); 
            void IBRZ(int reg, int a); 
            void BRNZ(int reg, int d); 
            void BLZ(int reg, int d); 
            void LOADM(int reg, int a);
            void STOREM(int reg, int a);
        public:
            Interpreter(Machine &M);
            void executeAll();
            bool execute(Decoder::Inst *i); 
    };
}
