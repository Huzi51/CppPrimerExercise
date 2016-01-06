#include <map>
#include <string>

using std::map;
using std::string;

const string &transform(const map<string, string> &trans_map, const string &word)
{
    auto it = trans_map.find(word);
    if (it == trans_map.end()) {
        return word;
    } else {
        return it->second;
    }
}