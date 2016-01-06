#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using std::placeholders::_1;
using std::bind;

int main()
{
    std::vector<int> ivec{1, 2, 3, 6};
    int val = 6;

    auto itr = find_if(ivec.begin(), ivec.end(),
                       [val](int i)
                       { return bind(std::modulus<int>(), val, _1) (i) != 0;} );
    if (itr == ivec.end()) {
        std::cout << "divisable" << std::endl;
    }
}