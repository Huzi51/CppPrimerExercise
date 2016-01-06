#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    std::vector<double> ivec{1.2, 2.3, 3.2, 4.1, 5.0, 6.7};
    double sum = accumulate(ivec.begin(), ivec.end(), 0.0);
    std::cout << sum << std::endl;

    std::vector<char*> roster1{"hello", "world"};
    std::vector<char*> roster2{"hello", "world"};
    if (equal(roster1.begin(), roster1.end(), roster2.begin()) ) {
        std::cout << "equal" << std::endl;
    }
    return 0;
}