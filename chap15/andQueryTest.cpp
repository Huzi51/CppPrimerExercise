#include "Query.hpp"
#include "TextQuery.h"

#include <iostream>
#include <fstream>
using std::ifstream;

int main(int argc, char **argv)
{
    ifstream infile;
    infile.open(argv[1]);

    TextQuery text(infile);
    Query q = Query("fiery") & Query("bird") | Query("wind");
    auto ret = q.eval(text);
    print(std::cout, ret);
}
