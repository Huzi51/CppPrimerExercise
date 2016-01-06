#include <string>
#include <iostream>
#include <forward_list>

void flst_insert(std::forward_list<std::string> &flst,
                 const std::string &s, const std::string &s2)
{
    auto pre = flst.before_begin();
    auto curr = flst.begin();
    size_t cnt = 0;
    while (curr != flst.end()) {
        if (*curr == s) {
            curr = flst.insert_after(curr, s2);
            pre = curr++;
            cnt++;
        } else {
            pre = curr++;
        }
    }
    if (cnt == 0) {
        flst.insert_after(pre, s2);
    }
}

int main()
{
    std::forward_list<std::string> s_flst = {"this", "is", "test", "string"};
    flst_insert(s_flst, "a", "insert");
    for (const auto &elem : s_flst) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}