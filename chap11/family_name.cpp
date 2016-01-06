#include <string>
#include <vector>
#include <utility>
#include <map>

using std::string;
using std::vector;
using std::map;
using std::pair;

int main()
{
    map<string, vector<pair<string, string> > > family_nm;
    string last_name = "hu";
    string children_nm = "zi";
    string birthday = "1990.5.01";
    family_nm[last_name].push_back({children_nm, birthday});

}
