#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

void elimDups(std::vector<std::string> &svec)
{
    sort(svec.begin(), svec.end());
    copy(svec.begin(), svec.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

    auto end_uniq = unique(svec.begin(), svec.end());
    copy(svec.begin(), svec.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

    svec.erase(end_uniq, svec.end());
    copy(svec.begin(), svec.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

}