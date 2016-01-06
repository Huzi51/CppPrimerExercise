#include <iostream>
#include "Quote.hpp"
#include "Basket.hpp"

int main()
{
    Basket bkt;
    bkt.add_item(Quote("1-2-1", 40));
    bkt.add_item(Quote("1-2-1", 40));
    bkt.add_item(Bulk_quote("1-2-2", 40, 1, 0.2));
    bkt.total_receipt(std::cout);
}