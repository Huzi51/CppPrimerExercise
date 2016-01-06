#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

void elimDups(std::vector<std::string> &svec);
bool isShorter(const std::string &s1, const std::string &s2);

int main()
{
    std::vector<std::string> svec = {"the", "quick", "red", "fox", "jumps", "over", "the",
                             "slow", "red", "turtle"};
    sort(svec.begin(), svec.end(), isShorter);
    copy(svec.begin(), svec.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

    elimDups(svec);

    stable_sort(svec.begin(), svec.end(),
                [](const std::string &a, const std::string &b) { return a.size() > b.size();});
    copy(svec.begin(), svec.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
}