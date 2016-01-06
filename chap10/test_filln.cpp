#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<int> ivec(10);
    fill_n(ivec.begin(), 8, -1);
    std::copy(ivec.begin(), ivec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}