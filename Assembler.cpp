// Assembler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<map>
#include <iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include "./sources/Sympol.cpp"
#include "./sources/ccode.cpp"
#include "./sources/acode.cpp"
#include "./sources/Ainstruction.cpp"
#include "./sources/Cinstruction.cpp"


using namespace std;





int main(int argc , char ** argv)
{
    Sympol symp;
    for (int i = 1; i < argc; ++i){
    string name,line;
    name = argv[i];
    ifstream infile;
    string fileName = name.substr (0,name.find("."));      
    cout<<fileName<<endl;
    ofstream outfile((fileName + ".hack"));
    symp.label_tour(name);

        infile.open(name);
        line = "";
        while (getline(infile, line)) {
    
            if (line == "" || line[0] == '/')
                continue;
            else {
                line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
                if (line[0] == '@') {
                    if (!isdigit(line[1])) {
                        symp.add_var(line.substr(1));
                    }
                    Ainstruction obj;
                    obj.parser(line, symp);
                    outfile << obj.binary_instruction() << endl;

                }
                else if(line[0] != '('){
                    Cinstruction obj;
                    obj.parser(line, symp);
                    outfile << obj.binary_instruction() << endl;
                }

            }

        }
        infile.close();
        outfile.close();
    }
}
        



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
