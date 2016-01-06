#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ostream_iterator;

int main()
{
    vector<string> svec{"hello", "world", "zhegeshiji", "hahahahaha", "test string"};
    auto count = count_if(svec.begin(), svec.end(),
                          [](const string &s)
                          { return s.size() >= 6; });
    cout << count << " " << "words "
         << " of length " << 6 << " or longer." << endl;
}