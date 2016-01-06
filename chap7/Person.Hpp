#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
    // construtor
public:
    Person() = default;
    Person(std::string &nm): name(nm) { }
    Person(std::string &nm, std::string &addr):
        name(nm), address(addr) { }
    Person(std::istream &is) {
        is >> name >> address;
    }
    // operation on object of Person
    std::string myname() const { return name }
    std::string myaddr() const { return address }
    // data member
private:
    std::string name;
    std::string address;
};
#endif