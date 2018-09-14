#pragma once 

#include <cstdint>
#include <iostream>
#include <fstream>
#include <vector>
#include "Decoder.hpp"

#define DATA_MEM_SIZE 1024
#define CODE_MEM_SIZE 1024
#define PC            10

namespace Emulator {
	class Machine {
	private:
        int indexDataMem, indexCodeMem; 
        Decoder::Inst **CodeMem;
		int *DataMem;
        int R[R_SIZE];
    public:
	    Machine();
        void loadFile(const std::string filePath);
        Decoder::Inst *getCode(const std::string i);
        void printCodeMem();
        void printDataMem();
        Decoder::Inst *fetch();
        int getRValue(int reg);
        void setRValue(int reg, int value);
        void store(int val, int a);
        int load(int a);
    };
}
