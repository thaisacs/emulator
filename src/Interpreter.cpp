#include "Interpreter.hpp"

using namespace Emulator;

Interpreter::Interpreter(Machine &M) {
    this->M = M;    
}

void Interpreter::ADD(int reg1, int reg2) {
    int v1 = M.getRValue(reg1);
    int v2 = M.getRValue(reg2);;
    M.setRValue(reg1, v1 + v2);
}

void Interpreter::SUB(int reg1, int reg2) {
    int v1 = M.getRValue(reg1);
    int v2 = M.getRValue(reg2);;
    M.setRValue(reg1, v1 - v2);
}

void Interpreter::DIV(int reg1, int reg2) {
    int v1 = M.getRValue(reg1);
    int v2 = M.getRValue(reg2);;
    M.setRValue(reg1, v1 / v2);
}

void Interpreter::MUL(int reg1, int reg2) {
    int v1 = M.getRValue(reg1);
    int v2 = M.getRValue(reg2);;
    M.setRValue(reg1, v1 * v2);
}

void Interpreter::BRZ(int reg, int d) {
    if(M.getRValue(reg) == 0) {
        M.setRValue(PC, M.getRValue(PC)+d-1);       
    }
}

void Interpreter::BRNZ(int reg, int d) {
    if(M.getRValue(reg) != 0) {
        M.setRValue(PC, M.getRValue(PC)+d-1); 
    }
}

void Interpreter::IBRZ(int reg, int a) {
    if(M.getRValue(reg) == 0) {
        M.setRValue(PC, a);       
    }
}

void Interpreter::BLZ(int reg, int d) {
    if(M.getRValue(reg) < 0) {
        M.setRValue(PC, M.getRValue(PC)+d-1);       
    }
}

void Interpreter::LOADM(int reg, int a) {
    M.setRValue(reg, M.load(a));
}

void Interpreter::STOREM(int reg, int a) {
    M.store(M.getRValue(reg), a);
}

void Interpreter::MOV(int reg1, int reg2) {
    int v2 = M.getRValue(reg2);;
    M.setRValue(reg1, v2);
}

void Interpreter::LOADI(int reg, int Imm) {
    M.setRValue(reg, Imm);
}

void Interpreter::WRITE(int reg) {
    std::cout << M.getRValue(reg) << "\n";
}

void Interpreter::READ(int reg) {
    int val;
    std::cin >> val;
    M.setRValue(reg, val);
}

bool Interpreter::execute(Decoder::Inst *i) {
    switch(i->Type) {
        case Decoder::InstType::ADD:
            ADD(i->A, i->B);
            break;
        case Decoder::InstType::SUB:
            SUB(i->A, i->B);
            break;
        case Decoder::InstType::DIV:
            DIV(i->A, i->B);
            break;
        case Decoder::InstType::MUL:
            MUL(i->A, i->B);
            break;
        case Decoder::InstType::BRZ:
            BRZ(i->A, i->Imm);
            break;
        case Decoder::InstType::BRNZ:
            BRNZ(i->A, i->Imm);
            break;
        case Decoder::InstType::IBRZ:
            IBRZ(i->A, i->Addrs);
            break;
        case Decoder::InstType::BLZ:
            BLZ(i->A, i->Imm);
            break;
        case Decoder::InstType::MOV:
            MOV(i->A, i->B);
            break;
        case Decoder::InstType::LOADM:
            LOADM(i->A, i->Addrs);
            break;
        case Decoder::InstType::STOREM:
            STOREM(i->A, i->Addrs);
            break;
        case Decoder::InstType::LOADI:
            LOADI(i->A, i->Imm); 
            break;
        case Decoder::InstType::WRITE:
            WRITE(i->A);
            break;
        case Decoder::InstType::READ:
            READ(i->A);
            break;
        case Decoder::InstType::EXIT:
            return false;
    }
    return true;
}

void Interpreter::executeAll() {
    bool cont = true;
    while(cont) {
        Decoder::Inst *i = M.fetch();
        cont = execute(i);
    }
    //M.printCodeMem();
    //M.printDataMem();
}
