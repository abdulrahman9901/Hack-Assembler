#include <string>
#include "instruction.h"
#include "Sympol.h"

#ifndef CINSTRUCTION_H
#define CINSTRUCTION_H

class Cinstruction :public instruction {
    std::string op_code = "111";
    std::string dest;
    std::string comp;
    std::string jmp;
public:
    void parser(std::string command, Sympol obj) override ;
    std::string binary_instruction() override ;
};


#endif