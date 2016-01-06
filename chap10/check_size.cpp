#include <string>
using std::string;

bool check_size(const string &s, string::size_type sz)
{
    return s.size() <= sz;
}