#ifndef _OPTIONS_H_
#define _OPTIONS_H_

#include <vector>
#include <string>


// singleton class which used to handle options parsing 
// `ParseOptions` : Iterate over CMD options and parse it
// `GetOptions` : Return vector of options
class Options
{
    public :
        static Options* GetOptionsObj();
        void ParseOptions(int argc, char** CMD);
        std::vector<std::string> GetOptions();
        bool IsExist(std::string opt);
    private:
        static Options* opt;
        std::vector<std::string> OptionsVector;
        int32_t Find(char* string, char* Token);
        void PrintHelpMsg();
        Options(const Options& obj) = delete;
        Options();
};

#endif // _OPTIONS_H_