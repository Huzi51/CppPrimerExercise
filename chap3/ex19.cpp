#include <iostream>
#include <vector>

using std::vector;

int main()
{
    vector<int > ivec{42, 42, 42, 42};
    vector<int > ivec = {42, 42, 42};
    vector<int> ivec(10, 42);
}