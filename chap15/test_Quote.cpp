#include <iostream>
#include "Quote.hpp"

int main()
{
    Quote book("1-2-3", 50);
    Bulk_quote bi("1-2-3", 50, 5, 0.2);

    // Disc_quote dq;

    print_total(std::cout, book, 5);
    print_total(std::cout, bi, 5);
}