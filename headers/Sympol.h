#include<map>
#include<string>

#ifndef SYMPOL_H
#define SYMPOL_H

class Sympol {
    std::map <std::string, std::string> SympolTable = { {"R0","0"} ,{"R1","1"} ,{"R2","2"} ,{"R3","3"},{"R4","4"} ,{"R5","5"} ,{"R6","6"} ,{"R7","7"} ,{"R8","8"}
  ,{"R9","9"} ,{"R10","9"} ,{"R11","11"} ,{"R12","12"} ,{"R13","13"} ,{"R14","14"} ,{"R15","15"},{"SCREEN","16384"} ,{"KBD","24576"},{"SP","0"}
  ,{"LCL","1"},{"ARG","2"},{"THIS","3"},{"THAT","4"} };
    int var_pos = 16;
public:
    bool is_exist(std::string symbol) ;
    void add_label(std::string label, int count);
    void add_var(std::string var) ;
    std::string return_symbol_val(std::string sympol) ;  
    void label_tour(std::string name);  
};
#endif