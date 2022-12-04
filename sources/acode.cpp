#include "../headers/acode.h"
#include <string>
std::string acode::toBinary(int n)
 {
    std::string r ,complete_16="";
    int count;
    while (n != 0) { r = (n % 2 == 0 ? "0" : "1") + r; n /= 2; }
    count = r.size();
    while (count < r.capacity()) {
        count++;
        complete_16 += '0';
    }
    return (complete_16+r);
}

std::string acode::to_code(int add){
            return toBinary(add);
}   