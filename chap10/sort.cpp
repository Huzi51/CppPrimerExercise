#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

int main()
{
    std::list<int> ilst{1, 6, 3, 4, 5, 2};
    std::list<int> ilst2{2, 1, 5, 4, 5};
    //ilst.sort();
    //ilst2.sort();
    copy(ilst.begin(), ilst.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    //ilst.merge(ilst2);
    copy(ilst.begin(), ilst.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    //ilst.unique();
    copy(ilst.begin(), ilst.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    //ilst.splice(++ilst.begin(), ilst2);
    copy(ilst.begin(), ilst.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    ilst.splice(++ilst.begin(), ilst2, ++ilst2.begin());
    copy(ilst.begin(), ilst.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    copy(ilst2.begin(), ilst2.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}