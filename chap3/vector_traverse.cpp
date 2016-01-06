#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;

int main()
{
    vector<int> svec, svec2;
    for (decltype(svec.size()) index = 0;
         index < 10; index++) {
        svec.push_back(index);
    }
    svec2 = svec;
}