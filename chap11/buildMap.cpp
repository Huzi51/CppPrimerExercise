#include <fstream>
#include <map>
#include <stdexcept>

using std::ifstream;
using std::string;
using std::map;

map<string, string> buildMap(ifstream &map_file)

    map<string, string> trans_map;
    string key, value;
    while (map_file >> key && getline(map_file, value)) {
        if (value.size() > 1) {
            trans_map[key] = value.substr(1);
        } else {
            throw std::runtime_error("no fule for" + key);
        }
    }
    return trans_map;
}
