#include "Decoder.hpp"

using namespace Emulator;

void Decoder::printInst(Decoder::Inst *X) {
    std::cout << "TYPE: " << X->Type << std::endl;
    std::cout << " REG: " << X->A << std::endl;
}

Decoder::Inst* Decoder::getCode(const std::string i) {
    int buff = 0;
    bool neg = false;
    Decoder::Inst *current = new Decoder::Inst();
    int index = 0;
    std::string op = "";
    while(i[index] != ' ') {
        op.push_back(i[index]);
        index++;
    }
    while(i[index] == ' ') {
        index++;
    }
    if(op == "ADD") {
        index++; //consome r
        buff = i[index] - 48;
        current->A = buff;
        index++;
        while(i[index] == ' ' || i[index] == ',') {
            index++;
        }
        index++; //consome r
        buff = i[index] - 48;
        current->B = buff;
        current->Type = Decoder::InstType::ADD;
    }else if(op == "SUB") {
        index++; //consome r
        buff = i[index] - 48;
        current->A = buff;
        index++;
        while(i[index] == ' ' || i[index] == ',') {
            index++;
        }
        index++; //consome r
        buff = i[index] - 48;
        current->B = buff;
        current->Type = Decoder::InstType::SUB;
    }else if(op == "DIV") {
        index++; //consome r
        buff = i[index] - 48;
        current->A = buff;
        index++;
        while(i[index] == ' ' || i[index] == ',') {
            index++;
        }
        index++; //consome r
        buff = i[index] - 48;
        current->B = buff;
        current->Type = Decoder::InstType::DIV;
    }else if(op == "MUL") {
        index++; //consome r
        buff = i[index] - 48;
        current->A = buff;
        index++;
        while(i[index] == ' ' || i[index] == ',') {
            index++;
        }
        index++; //consome r
        buff = i[index] - 48;
        current->B = buff;
        current->Type = Decoder::InstType::MUL;
    }else if(op == "BRZ") {
        index++; //consome r
        buff = i[index] - 48;
        current->A = buff;
        index++;
        while(i[index] == ' ' || i[index] == ',') {
            index++;
        }
        if(i[index] == '-') {
            neg = true;
            index++;
        }
        buff = 0;
        while(i[index] >= 48 && i[index] <= 57) {
            buff = buff*10 + i[index] - 48;
            index++;
        }
        if(neg) {
            buff *= -1;
            neg = false;
        }
        current->Imm = buff;
        current->Type = Decoder::InstType::BRZ;
    }else if(op == "BRNZ") {
        index++; //consome r
        buff = i[index] - 48;
        current->A = buff;
        index++;
        while(i[index] == ' ' || i[index] == ',') {
            index++;
        }
        if(i[index] == '-') {
            neg = true;
            index++;
        }
        buff = 0;
        while(i[index] >= 48 && i[index] <= 57) {
            buff = buff*10 + i[index] - 48;
            index++;
        }
        if(neg) {
            buff *= -1;
            neg = false;
        }
        current->Imm = buff;
        current->Type = Decoder::InstType::BRNZ;
    }else if(op == "IBRZ") {
        index++; //consome r
        buff = i[index] - 48;
        current->A = buff;
        index++;
        while(i[index] == ' ' || i[index] == ',') {
            index++;
        }
        buff = 0;
        while(i[index] >= 48 && i[index] <= 57) {
            buff = buff*10 + i[index] - 48;
            index++;
        }
        current->Addrs = buff;
        current->Type = Decoder::InstType::IBRZ;
    }else if(op == "BLZ") {
        index++; //consome r
        buff = i[index] - 48;
        current->A = buff;
        index++;
        while(i[index] == ' ' || i[index] == ',') {
            index++;
        }
        if(i[index] == '-') {
            neg = true;
            index++;
        }
        buff = 0;
        while(i[index] >= 48 && i[index] <= 57) {
            buff = buff*10 + i[index] - 48;
            index++;
        }
        if(neg) {
            buff *= -1;
            neg = false;
        }
        current->Imm = buff;
        current->Type = Decoder::InstType::BLZ;
    }else if(op == "MOV") {
        index++; //consome r
        buff = i[index] - 48;
        current->A = buff;
        index++;
        while(i[index] == ' ' || i[index] == ',') {
            index++;
        }
        index++; //consome r
        buff = i[index] - 48;
        current->B = buff;
        current->Type = Decoder::InstType::MOV;
    } else if(op == "LOADM") {
        index++; //consome r
        buff = i[index] - 48;
        current->A = buff;
        index++;
        while(i[index] == ' ' || i[index] == ',') {
            index++;
        }
        buff = 0;
        while(i[index] >= 48 && i[index] <= 57) {
            buff = buff*10 + i[index] - 48;
            index++;
        }
        current->Addrs = buff;
        current->Type = Decoder::InstType::LOADM;
    } else if(op == "STOREM") {
        index++; //consome r
        buff = i[index] - 48;
        current->A = buff;
        index++;
        while(i[index] == ' ' || i[index] == ',') {
            index++;
        }
        buff = 0;
        while(i[index] >= 48 && i[index] <= 57) {
            buff = buff*10 + i[index] - 48;
            index++;
        }
        current->Addrs = buff;
        current->Type = Decoder::InstType::STOREM;
    }else if(op == "LOADI") {
        index++; //consome r
        buff = i[index] - 48;
        current->A = buff;
        index++;
        while(i[index] == ' ' || i[index] == ',') {
            index++;
        }
        if(i[index] == '-') {
            index++;
            neg = true;
        }
        buff = 0;
        while(i[index] >= 48 && i[index] <= 57) {
            buff = buff*10 + i[index] - 48;
            index++;
        }
        if(neg) {
            buff *= -1;
            neg = false;
        }
        current->Imm = buff;
        current->Type = Decoder::InstType::LOADI;
    }else if(op == "WRITE") {
        index++; //consome r
        buff = i[index] - 48;
        current->A = buff;
        current->Type = Decoder::InstType::WRITE;
    }else if(op == "READ") {
        index++; //consome r
        buff = i[index] - 48;
        current->A = buff;
        current->Type = Decoder::InstType::READ;
    }else { //exit
        current->Type = Decoder::InstType::EXIT;
    }
    #ifdef DEBUG_ON
    printInst(current);
    #endif
    return current;
}
