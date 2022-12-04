#include <string>
#include "instruction.h"
#include "Sympol.h"
#ifndef AINSTRUCTION_H
#define AINSTRUCTION_H

class Ainstruction :public instruction {
    std::string op_code = "0";
    int address;
public:
     void parser(std::string command,Sympol obj) override ;
     std::string binary_instruction() override;
    
};


#endif