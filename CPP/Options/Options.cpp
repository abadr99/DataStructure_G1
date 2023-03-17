#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <Options.h>


Options::Options() 
{

}

Options* Options::opt = nullptr;

Options* Options::GetOptionsObj() {
    if(opt == nullptr) {
        opt = new Options;
    }
    return opt;
}

void Options::ParseOptions(int argc, char** CMD) {
    if(strcmp(CMD[1], "help")) {
        OptionsVector.push_back(CMD[1]);
        return;
    }
    for(int32_t iOptions = 1 ; iOptions < argc ; iOptions++) {
        if(!strcmp(CMD[iOptions],"uTest") || !strcmp(CMD[iOptions],"$u")) {
            OptionsVector.push_back(CMD[iOptions]);
        }
        else if(!strcmp(CMD[iOptions], "iTest") || !strcmp(CMD[iOptions], "$i")) {
            OptionsVector.push_back(CMD[iOptions]);
        }
        else {
            std::cout << "Error Option : " << CMD[iOptions]; 
            exit(EXIT_FAILURE);
        }
        
    }
}

std::vector<std::string> Options::GetOptions() {
    return OptionsVector;
}

bool Options::IsExist(std::string opt) {
    for (auto option : OptionsVector) {
        if (option == opt)
            return true;
    }
    return false;
}

void Options::PrintHelpMsg() {
    std::cout << "uTest | $u :      Run unit tests\n";
    std::cout << "iTest | $i :      Run integration tests\n";
}