#include <set>
#include "Sales_data.hpp"

using std::set;

bool compareIsbn(const Sales_data&, const Sales_data&);

int main()
{
    //
    using op = (const Slaes_data &lhs, const Sales_data &rhs) -> bool;
    typedef bool op(const Sales_data &lhs, const Sales_data &rhs);
    map<Sales_data, op> bookStore(compareIsbn);
}