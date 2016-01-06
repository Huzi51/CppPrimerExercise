#include <tuple>
#include <string>
#include <vector>

int main()
{
    std::tuple<int, int, int> itup(1, 2, 3);

    std::tuple<std::string,
               std::vector<std::string>,
               std::pair<std::string, int>
               > stup("hello", {"fuck", "gfw"}, {"tools", 4});
}