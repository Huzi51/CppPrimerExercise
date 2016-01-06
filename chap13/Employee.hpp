#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>
using std::string;
#include <cstddef>
using std::size_t;

class Employee {
    Employee(): identifier(serial++) { }
    Employee(const string &s): name(s), identifier(serial++) { }
    // copy-constructor
    Employee(const Employee &em): name(em.name), identifier(serial++) { }
    // copy-assignment
    Employee& operator=(const Employee &rhs) {
        name = rhs.name;
        identifier = serial++;
    }
private:
    string name;
    size_t identifier;
    static size_t serial;
};
#endif