#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>
#include <utility>
#include <functional>

class Sales_data;
// nonmember Sales_data interface functions
Sales_data operator+ (const Sales_data &lhs, const Sales_data &rhs);
std::ostream& operator<< (std::ostream&, const Sales_data&);
std::istream& operator>> (std::istream&, Sales_data&);
bool operator== (const Sales_data &lhs, const Sales_data &rhs);
bool operator!= (const Sales_data &lhs, const Sales_data &rhs);


class Sales_data {
    friend Sales_data operator+ (const Sales_data &lhs, const Sales_data &rhs);
    friend std::ostream& operator<< (std::ostream&, const Sales_data&);
    friend std::istream& operator>> (std::istream&, Sales_data&);
    friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
    friend bool operator!=(const Sales_data &lhs, const Sales_data &rhs);

    friend class std::hash<Sales_data>;

   // constructors
public:
    Sales_data() { }
    // defines the default constructor as well as one that take a string argument
    Sales_data(const std::string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(n * p) { }
    Sales_data(const std::string &s): bookNo(s) { }
    explicit Sales_data(std::istream &);

    // operations on Sales_data object
    std::string isbn() const { return bookNo;}
    Sales_data& operator+=(const Sales_data &rhs);

    Sales_data& operator=(const std::string &s);

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
inline Sales_data&
Sales_data::operator+=(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// nonmeber interface functions definition
Sales_data operator+ (const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data ret = lhs;
    ret += rhs;
    return ret;
}
std::ostream& operator<< (std::ostream &os, const Sales_data &item) { // const parameter
    os << item.bookNo << " "
       << item.units_sold << " "
       << item.revenue << " "
       << item.avg_price();
    return os;
}
std::istream& operator>> (std::istream &is, Sales_data &item) { // nonconst parameter
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    if (is) {
        item.revenue = item.units_sold * price;
    } else {
        item = Sales_data();
    }
    return is;
}
// operator==
bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.bookNo == rhs.bookNo &&
           lhs.units_sold == rhs.units_sold&&
           lhs.revenue == rhs.revenue;
}
// operator!=
bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
    return !(lhs == rhs);
}

// defining a constructor outsize of the calss
Sales_data::Sales_data(std::istream &is) {
    is >> *this;
}
// assignment
inline Sales_data&
Sales_data::operator=(const std::string &s) {
    *this = Sales_data(s);
    return *this;
}

// std::hash<Sales_data>
namespace std {
    template <>
    class hash<Sales_data> {
    public:
        typedef size_t result_type;
        typedef Sales_data argument_type;

        size_t operator()(const Sales_data &s) const;
    };
    size_t
    hash<Sales_data>::operator()(const Sales_data &s) const {
        return hash<string>()(s.bookNo) ^
               hash<unsigned>()(s.units_sold) ^
               hash<double>()(s.revenue);
    }
}

bool compareISBN(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}
#endif