#include <memory>
#include <new>

int main()
{
    std::unique_ptr<int> p(new int(20));
    std::unique_ptr<int> p2(p);
    std::unique_ptr<int> p3;
    p3 = p;
}