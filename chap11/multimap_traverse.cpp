#include <iostream>
#include <map>

using std::multimap;
using std::cout;
using std::endl;

int main()
{
    multimap<string, string> authers;
    auto beg = authers.begin();
    while (beg != authers.end()) {
        auto end_range = authers.upper_bound(beg->first);
        cout << "beg->first : " << endl;
        while (beg != end_range) {
            cout << beg->second << " ";
            beg++;
        }
    }
}