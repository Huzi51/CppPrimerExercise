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
void elimDups(vector<string> &svec);
std::string make_plural(size_t n, const std::string &word,
                        const std::string &ending);


void biggies2(vector<string> &svec,
              vector<string>::size_type sz)
{
    elimDups(svec);
    auto it = stable_partition(svec.begin(), svec.end(),
                               bind(check_size, _1, sz));
    auto cnt = svec.end() - it;
    cout << cnt << " " << make_plural(cnt, "word", "s")
         << " of length " << sz << " or longer." << endl;
    for_each(it, svec.end(),
             [](const string &s) { cout << s << " "; });
    cout << endl;
}