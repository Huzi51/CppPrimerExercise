#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using std::vector;
using std::cout;
using std::endl;
using std::ostream_iterator;

int main()
{
    vector<int> ivec{1, -1, 2, -3, 5, -7};
    transform(ivec.begin(), ivec.end(), ivec.begin(),
              [](int i) -> int
              { if(i < 0) return -i; return i; });
    copy(ivec.begin(), ivec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}