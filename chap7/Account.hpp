#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
class Account {
public:
    void calculate() { amount += amoutn * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double);
private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();
    static constexpr int period = 30;
    double daily_tbl[period]
};
// rate
static Account::rate(double newRate) {
    interestRate = newRate;
}
// define and initialize a static class member
double Account::interestRate = initRate();
#endif