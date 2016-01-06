#include <vector>
#include <new>
#include <iostream>

std::vector<int> *newVector()
{
    return new std::vector<int>;
}

void readVector(std::vector<int> *vec_p)
{
    int i;
    while (std::cin >> i) {
        vec_p->push_back(i);
    }
}

void printVector(std::vector<int> *p)
{
    for (const auto &i : *p) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> *vec_p = newVector();
    readVector(vec_p);
    printVector(vec_p);
    delete vec_p;
}
