#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Sales_item.h"

using std::cin;
using std::cout;
using std::endl;

bool compareIsbn(const Sales_item &item1, const Sales_item &item2);

int main()
{
    std::istream_iterator<Sales_item> in(cin), eof;
    std::vector<Sales_item> trans(in, eof);

    sort(trans.begin(), trans.end(), compareIsbn);

    decltype(trans.begin()) sum_it = trans.begin();
    while ( sum_it != trans.end() ) {
        auto end = find_if (sum_it, trans.end(),
                            [sum_it](const Sales_item &item)
                            { return item.isbn() != sum_it->isbn(); });
        cout << "Total of book " << sum_it->isbn() << ": ";
        cout << accumulate(sum_it, end, Sales_item(sum_it->isbn())) << endl;
        sum_it = end;
    }
}