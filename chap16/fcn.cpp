#include <type_traits>
using std::remove_reference;

template <typename It>
auto fcn(It beg, It end) -> decltype(*beg)
{
    //

    return *beg;
}

template <typename It>
auto fcn2(It beg, It end) -> typename remove_reference<decltype(*beg)>::type
{

    return *beg;
}
int main()
{}