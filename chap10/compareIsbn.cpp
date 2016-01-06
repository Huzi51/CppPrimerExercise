#include "Sales_item.h"

bool compareIsbn(const Sales_item &item1, const Sales_item &item2)
{
    return item1.isbn() <= item2.isbn();
}