#include <vector>
#include <string>
#include <iostream>
#include <iterator>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;

int main()
{
    istream_iterator<string> is_iter(cin), eof;
    vector<string> svec;
    while (is_iter != eof) {
        svec.push_back(*is_iter++);
    }

    ostream_iterator<string> out_iter(cout, " ");
    auto beg = svec.begin();
    while (beg != svec.end()) {
        *out_iter++ = *beg++;
    }
    cout << endl;
}