#include <vector>
#include <string>
using std::vector;
using std::string;

void biggies2(vector<string> &words, vector<string>::size_type sz);

int main()
{
    std::vector<std::string> svec = {"the", "quick", "red", "fox", "jumps", "over", "the",
                             "slow", "red", "turtle"};
    biggies2(svec, 3);
}