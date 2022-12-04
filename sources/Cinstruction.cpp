#include "../headers/Sympol.h"
#include "../headers/Cinstruction.h"
#include "../headers/ccode.h"

void Cinstruction::parser(std::string command, Sympol obj)  {
    auto equal = command.find('=');
    auto semicolon = command.find(';');
    auto comment = command.find("//");
    if (comment == std::string::npos) {
        if (equal == std::string::npos) {
            if (semicolon == std::string::npos) {
                dest = "null";
                jmp = "null";
                comp = command;
            }
            else {
                dest = "null";
                jmp = command.substr(semicolon + 1);
                comp = command.substr(0, semicolon);
            }
        }
        else {
            if (semicolon == std::string::npos) {
                dest = command.substr(0, equal);
                jmp = "null";
                comp = command.substr(equal + 1);
            }
            else {
                comp = command.substr(equal + 1, semicolon - equal);
                jmp = command.substr(semicolon + 1);
                dest = command.substr(0, equal);

            }
        }
    }else{
        if (equal == std::string::npos) {
            if (semicolon == std::string::npos) {
                dest = "null";
                jmp = "null";
                comp = command.substr(0,comment-2);
            }
            else {
                dest = "null";
                jmp = command.substr(semicolon + 1,comment-2);
                comp = command.substr(0, semicolon);
            }
        }
        else {
            if (semicolon == std::string::npos) {
                dest = command.substr(0, equal);
                jmp = "null";
                comp = command.substr(equal + 1,comment-2);
            }
            else {
                comp = command.substr(equal + 1, semicolon - equal);
                jmp = command.substr(semicolon + 1,comment-2);
                dest = command.substr(0, equal);

            }
        }
    }
        
};
std::string Cinstruction::binary_instruction()  {
    ccode obj;
    std::string cd = obj.to_code(dest,"dest");
    std::string cc = obj.to_code(comp, "comp");
    std::string cj = obj.to_code(jmp, "jmp");
    return (op_code + cc + cd + cj);
};