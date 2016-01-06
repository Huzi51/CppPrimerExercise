#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
    unsigned grade = 0;
    string letterGrade;
    vector<string> scores = {"F", "D","C", "B" ,"A", "A++"};
    while (cin >> grade) {
        if (grade > 100) {
            std::cout << "Please Input valid number: " << std::endl;
        } else {
            if (grade < 60) {
                letterGrade = scores[0];
            } else {
                letterGrade = scores[(grade - 50) / 10];
                if (grade != 100) {
                    if (grade % 10 >= 3) {
                        if (grade % 10 > 7) {
                            letterGrade += "+";
                        }
                    } else {
                        letterGrade += "-";
                    }
                }
            }
        }
        cout << "Your grade: " << letterGrade << endl;
    }
    return 0;
}