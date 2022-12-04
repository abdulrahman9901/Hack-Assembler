#include "../headers/ccode.h"
#include <string>

std::string ccode::to_code(std::string field,std::string type) {
    if (type == "dest")
        return destination[field];
    else if(type == "comp")
        return compute[field];
    else if(type=="jmp")
        return jump[field];
}