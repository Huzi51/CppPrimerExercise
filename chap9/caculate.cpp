#include <stack>
#include <string>
#include <cctype>

int main()
{
    std::string expr = "1*2+3*4";
    std::stack<int> operand;
    std::stack<char> operator;
    operator.push('(');
    for (const auto &elem : expr) {
        if (isdigit(elem)) {
            operand.push(elem);
        } else {
            if (map[elem] <= map[operator.top()]) {
                int lhr = operand.top();
                operand.pop();
                int rhr = operand.top();
                operand.pop();
                operand.push(calcu(lhr, rhr, elem));
            } else {
                operator.push(elem);
            }
        }
    }
    char ope;
    while ( (ope = operator.top()) != '(') {
        int lh, rh;
        get_ophand(lh, rh);
        calcu(lh, rh, ope);
        operator.pop();
    }
    return operhand.top();
}

1 + 2 * 3 * 4
1 * 2 + 3 * 4
(+ 1 (* 2 3))

1 2 * 3 4 * +
(+ (* 1 2) (* 3 4))