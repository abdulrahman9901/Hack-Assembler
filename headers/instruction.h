#include <string>
#ifndef INSTRUCTION_H
#define INSTRUCTION_H

class instruction {
public:
    virtual std::string binary_instruction()=0;
    virtual void parser(std::string command, Sympol obj) {};
};

#endif