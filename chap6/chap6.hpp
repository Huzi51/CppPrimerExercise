#ifndef CHAP6_H
#define CHAP6_H
#include <string>
#include <initializer_list>
#include <vector>
#include <cassert>
int fact(int n);
int fact2();
int abs(int n);
int swap(int*, int*);
std::string::size_type find_char(const std::string &s, char c,
                            std::string::size_type &occurs);

bool is_sentence (const std::string &s);
bool is_empty (const std::string &s);
bool find_capital (const std::string &s);
int string_tolower (std::string &s);

//print function
void print(const char *cp);
void print (const int *beg, const int *end);
void print (const int *p, size_t sz);
void print2 (int (&arr)[10]); // must pass a array of size 10
// multi parameters
int sum_il (std::initializer_list<int> il);
bool str_subrange (const std::string &, const std::string &);
void print_vec (std::vector<int>::iterator beg, std::vector<int>::iterator end);
// make_plural
std::string make_plural (size_t ctr, const std::string &word,
                    const std::string &ending);
// inline shorterString
inline const std::string &
shorterString (const std::string &s1, const std::string &s2){
    return (s1.size() <= s2.size()) ? s1 : s2;
}
// inline isShorter
bool isShorter (const std::string &s1, const std::string &s2) {
    return s1.size() < s2.size();
}
// pointer to function type (test function)
inline int
add (int value, int value2) {
    return value + value2;
}
inline int
subtract (int value, int value2) {
    return value - value2;
}
inline int
multiply (int value, int value2) {
    return value * value2;
}
inline int
divide (int value,  int value2) {
    assert(value2);
    return value / value2;
}
#endif