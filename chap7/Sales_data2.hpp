#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

// nonmember Sales_data interface functions
class Sales_data;

Sales_data add (const Sales_data&, const Sales_data&);
std::ostream &print (std::ostream&, const Sales_data&);
std::istream &read (std::istream&, const Sales_data&);

class Sales_data {
    // friends
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
public:
    // constructors
    Sales_data(std::string s, unsigned cnt, double price):
        bookNo(s), units_sold(cnt), revenue(cnt * price) {
        std::cout << "delegated-to" << std::endl; }
    Sales_data(): Sales_data(" ", 0, 0) {
        std::cout << "default" << std::endl; }
    Sales_data(std::string s): Sales_data(s, 0, 0) {
        std::cout << "only string arg" << std::endl;}
    Sales_data(std::istream &is): Sales_data() {
        std::cout << "only istream arg" << std::endl;
        read(is, *this); }
    // operations on Sales_data object
    std::string isbn() const { return bookNo;}
    Sales_data &combine(const Sales_data&);
private:
    double avg_price() const {
        return units_sold ? revenue / units_sold : 0;
    }
    // data member
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
// combine member, like += operator
Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// nonmeber interface functions definition
Sales_data add (const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
std::ostream &print (std::ostream &os, const Sales_data &item) { // const parameter
    os << item.bookNo << " "
       << item.units_sold << " "
       << item.revenue << " "
       << item.avg_price();
    return os;
}
std::istream &read (std::istream &is, Sales_data &item) { // nonconst parameter
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

#endif