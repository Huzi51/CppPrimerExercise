#ifndef QUOTE_HPP
#define QUOTE_HPP

#include <iostream>
#include <string>
#include <cstddef>
#include <utility>

class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price):
        bookNo(book), price(sales_price) { }

    Quote(const Quote &rhs): bookNo(rhs.bookNo), price(rhs.price) {

        // std::cout << "Quote copy-constr. " << std::endl;
    }
    Quote(const Quote &&rhs):
        bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price)) {

        // std::cout << "Quote move-constr. " << std::endl;
    }

    Quote& operator=(const Quote &rhs) {
        bookNo = rhs.bookNo;
        price = rhs.price;

        // std::cout << "Quote copy-assign. " << std::endl;
        return *this;
    }
    Quote& operator=(const Quote &&rhs) {
        bookNo = std::move(rhs.bookNo);
        price = std::move(rhs.price);

        // std::cout << "Quote move-assign. " << std::endl;
        return *this;
    }

    ~Quote() {
        // std::cout << "Quote destructor. " << std::endl;
    }

    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const {
        return n * price;
    }

    virtual Quote* clone() const & { return new Quote(*this); }
    virtual Quote* clone() && { return new Quote(std::move(*this)); }

private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Bulk_item: public Quote {
public:
    Bulk_item() = default;
    Bulk_item(const std::string &s, double sales_price,
              std::size_t qty, double discnt):
        Quote(s, sales_price), min_qty(qty), discount(discnt) {

        std::cout << "Bulk_item constructor." << std::endl;
    }

    Bulk_item(const Bulk_item &rhs):
        Quote(rhs), min_qty(rhs.min_qty), discount(rhs.discount) {

        std::cout << "Bulk_item copy_constructor. " << std::endl;
    }
    Bulk_item(const Bulk_item &&rhs):
        Quote(std::move(rhs)),
        min_qty(std::move(rhs.min_qty)),
        discount(std::move(rhs.discount)) {

        std::cout << "Bulk_item move_constructor. " << std::endl;
    }

    Bulk_item& operator=(const Bulk_item &rhs) {
        Quote::operator=(rhs);
        min_qty = rhs.min_qty;
        price = rhs.price;

        std::cout << "Bulk_item copy-assign. " << std::endl;
        return *this;
    }
    Bulk_item& operator=(const Bulk_item &&rhs) {
        Quote::operator=(std::move(rhs));
        min_qty = std::move(rhs.min_qty);
        price = std::move(rhs.price);
        std::cout << "Bulk_item move_assign. " << std::endl;
        return *this;
    }

    ~Bulk_item() {
        std::cout << "Bulk_item distructor. " << std::endl;
    }

    double net_price(std::size_t) const override;

private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

// abstract base class
class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string &s, double sales_price,
               std::size_t qty, double disc):
        Quote(s, sales_price),
        min_qty(qty), discount(disc) { }

    double net_price(std::size_t) const = 0;

    std::pair<size_t, double> discount_policy() const
        { return { min_qty, discount}; }
protected:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
    // Bulk_quote() = default;
    // Bulk_quote(const std::string &s, double sales_price,
    //            std::size_t qty, double disc):
    //     Disc_quote(s, sales_price, qty, disc) { }

    // inherited constructors
    using Disc_quote::Disc_quote;
    double net_price(std::size_t) const;
    Bulk_quote* clone() const & { return new Bulk_quote(*this); }
    Bulk_quote* clone() && { return new Bulk_quote(std::move(*this)); }
};

// calculate and print the price for the given numbers of copies, applying any discounts
double print_total(std::ostream &os,
                   const Quote &item, std::size_t n);
#endif