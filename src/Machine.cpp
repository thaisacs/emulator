#include "Machine.hpp"

using namespace Emulator;

Machine::Machine() {
    this->CodeMem = new Decoder::Inst*[CODE_MEM_SIZE];
    this->DataMem = new int32_t[DATA_MEM_SIZE];
    this->indexDataMem = 5;
    this->indexCodeMem = 0;
    for(int i = 0; i < R_SIZE; i++) {
        this->R[i] = 0;
    }
}

void Machine::loadFile(const std::string filePath) {
    uint32_t totalDataSize = 0;
    uint32_t addressOffset = 0;
    std::ifstream file;
    std::string inst;
    Decoder::Inst *current;

    file.open(filePath);
    
    if(!file.is_open()) {
        exit(1);
    }
    
    while(std::getline(file, inst)) {
        Decoder::Inst *i = Decoder::getCode(inst);
        this->CodeMem[this->indexCodeMem] = i;
        indexCodeMem++;
    }    
}

void Machine::printCodeMem() {
    std::cout << "###CODE MEM###\n";
    for(int i = 0; i < this->indexCodeMem; i++) {
        std::cout << this->CodeMem[i]->Type << " ";
        for(int j = 0; j < R_SIZE; j++) {
            //std::cout << this->CodeMem[i]->R[j];
        }
        std::cout << " " << this->CodeMem[i]->Imm << " ";
        std::cout << this->CodeMem[i]->Addrs << std::endl;
    }
    std::cout << "##############\n";
}

void Machine::printDataMem() {
    std::cout << "###DATA MEM###\n";
    for(int i = 0; i < this->indexDataMem; i++) {
        std::cout << this->DataMem[i] << std::endl;
    }
    std::cout << "##############\n";
}

Decoder::Inst *Machine::fetch() {
    Decoder::Inst *i = this->CodeMem[R[PC]];
    R[PC]++;
    return i;
}

int Machine::getRValue(int reg) {
    return R[reg];
}

void Machine::setRValue(int reg, int value) {
   R[reg] = value; 
}

void Machine::store(int val, int a) {
    DataMem[a] = val;
}

int Machine::load(int a) {
    return DataMem[a];
}
