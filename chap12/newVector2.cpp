#include <iostream>
#include <memory>
#include <vector>

using std::vector;
using std::shared_ptr;

shared_ptr<vector<int> > newVec()
{
    return std::make_shared<vector<int> >();
}

void readVec(shared_ptr<vector<int> > pv)
{
    int i;
    while (std::cin >> i) {
        pv->push_back(i);
    }
}
void printVec(shared_ptr<vector<int> > pv)
{
    for (const auto &i : *pv) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    shared_ptr<vector<int> > pv = newVec();
    readVec(pv);
    printVec(pv);
}