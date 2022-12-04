#include "../headers/Sympol.h"
#include<map>
#include<string>
#include<fstream>
#include<sstream>

bool Sympol::is_exist(std::string symbol) {
    return(Sympol::SympolTable.find(symbol) != Sympol::SympolTable.end());
}
void Sympol::add_label(std::string label, int count) {
    Sympol::SympolTable.insert(std::pair<std::string, std::string>(label, std::to_string(count)));
}
void Sympol::add_var(std::string var) {
    if (!is_exist(var)) {
        Sympol::SympolTable.insert(std::pair<std::string, std::string>(var, std::to_string(Sympol::var_pos)));
        Sympol::var_pos++;
    }
    return;
}
std::string Sympol::return_symbol_val(std::string sympol) {
    return Sympol::SympolTable[sympol];
}
void Sympol::label_tour(std::string name) {
        int count = 0;
        std::string line;
        std::ifstream infile;
        infile.open(name + ".asm");
        if (infile.is_open()) {
            while (getline(infile, line)) {
                if (line == "" || line[0] == '/')
                    continue;
                else {
                    line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
                    if (line[0] == '(') {
                        add_label(line.substr(1, line.size() - 2), count);
                        continue;
                    }
                    count++;
                    }
                }
            }
    }
