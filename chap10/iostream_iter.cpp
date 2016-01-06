#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;

int main()
{
    istream_iterator<int> in(cin), eof;
    vector<int> ivec(in, eof);
    sort(ivec.begin(), ivec.end());

    ostream_iterator<int> out(cout, " ");
    unique_copy(ivec.begin(), ivec.end(), out);
    cout << endl;
}