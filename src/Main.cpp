#include <iostream>
#include <cstring>
#include "Machine.hpp"
#include "Interpreter.hpp"

void error(const char *e) {
    if(e != nullptr)
        std::cout << "error: " << e << std::endl;
    exit(1);
}

void usage(int argc, char *argv[]) {
    if(argc < 2)
        error("invalid arguments");
    for(int i = 0; i < argc; i++) {
        if(!std::strcmp(argv[i], "-d")) {
            #define DEBUG_ON
        }
    }
}

int main(int argc, char *argv[]) {
    Emulator::Machine M;
    Emulator::Interpreter *I;
    usage(argc, argv);
    M.loadFile(argv[1]);
    I = new Emulator::Interpreter(M);
    I->executeAll();
    return 0;
}
