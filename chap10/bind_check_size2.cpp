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
    vector<int> ivec{1, 2, 2, 4, 5, 6};
    string s = "hah";
    auto it = find_if(ivec.begin(), ivec.end(),
                      bind(check_size, s, _1));
    cout << *it << endl;
    cout << "length of string: " << s.size() << endl;
    return 0;
}