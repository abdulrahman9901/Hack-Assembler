#include "../headers/Sympol.h"
#include "../headers/Ainstruction.h"
#include "../headers/acode.h"

#include <string>

void Ainstruction::parser(std::string command,Sympol obj)  {
    if (obj.is_exist(command.substr(1)))
        Ainstruction::address = stoi(obj.return_symbol_val(command.substr(1)));
    else
        Ainstruction::address = stoi(command.substr(1));
};

std::string Ainstruction::binary_instruction() {
    acode obj;
    std::string add = obj.to_code(Ainstruction::address);
    return op_code + add;
};

    

