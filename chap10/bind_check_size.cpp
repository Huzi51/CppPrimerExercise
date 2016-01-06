#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz);

int main()
{
    vector<string> words{"nothing", "is", "impossible,", "hahah", "coolvim"};
    auto cnt = count_if(words.begin(), words.end(),
                     bind(check_size, _1, 3));
    cout << cnt << " words "
         << " of length " << 3 << " or longer. " << endl;
}