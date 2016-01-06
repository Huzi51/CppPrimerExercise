#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>

using namespace std::placeholders;

int main()
{
    // exercise 14.42
    std::vector<int> ivec{1025, 1024, 1023, 1088};
    auto cnt = std::count_if(ivec.begin(), ivec.end(),
                             std::bind(std::greater<int>(), _1, 1024) );
    std::cout << "have " << cnt << " value greater than 1024" << std::endl;

    std::string s = "pooh";
    std::vector<std::string> svec{"pooh", "pooh", "poh"};
    auto p = std::find_if(svec.begin(), svec.begin(),
                          std::bind(std::not_equal_to<std::string>(), _1, std::ref(s)) );
    std::cout << "The first word that not is pooh is: " << *p << std::endl;

    std::vector<int> ivec2{2, 4, 6, 8, 10};
    std::for_each(ivec2.begin(), ivec2.end(),
                  [](int &i)
                  { i = std::bind(std::multiplies<int>(), _1, 2)(i); });
    std::for_each(ivec2.begin(),ivec2.end(),
                  [](int i)
                  { std::cout << i << " "; });
    std::cout << std::endl;
}