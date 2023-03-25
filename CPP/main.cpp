#include <iostream>
#include <assert.h>
#include "Options/Options.h"
#include "UnitTests.h"
#include "BinaryTree.h"
#include "BST.h"

int main (int argc, char **argv) {
    Options* Opt = Options::GetOptionsObj();
    Opt->ParseOptions(argc,argv);
    
    if(Opt->IsExist("uTest") || Opt->IsExist("$u")) {
        RUN_UNIT_TESTS();
    }

    if(Opt->IsExist("iTest") || Opt->IsExist("$i")) {
        //RUN_INTEGRATION_TESTS();
    }

    if(Opt->IsExist("help")) {
        Opt->PrintHelpMsg();
    }
}