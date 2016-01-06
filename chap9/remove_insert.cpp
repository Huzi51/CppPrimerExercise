#include <list>
#include <forward_list>

void remove_insert(std::list<int> &ilst)
{
    auto it = islt.begin();
    while (it != ilst.end()) {
        if (*it % 2) {
            ilst.insert(it, *it);
            it++;
        } else {
            it = ilst.erase(it);
        }
    }
}

void remove_insert2(std::forward_list<int> &flst)
{
    auto curr = flst.begin();

    while (curr != flst.end()) {
        if (*curr % 2) {
            curr = flst.insert_after(curr, *curr);
            ++curr;
        } else {
            curr = flst.erase_after(curr);
        }
    }
}