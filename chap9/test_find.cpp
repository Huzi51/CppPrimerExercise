#include <vector>
#include <iostream>

bool find (std::vector<int>::iterator beg,
           std::vector<int>::iterator end, int n);

int main()
{
    std::vector<int> svec{1,2,3,4,5,6};
    if (find (svec.begin(), svec.end(), 4)) {
        std::cout << "succeed" << std::endl;
    }
    return 0;
}