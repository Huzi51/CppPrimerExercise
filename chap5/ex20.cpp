#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;

int main()
{
    string word, currWord;
    unsigned cnt = 0;
    if (cin >> currWord){
        cnt++;
        while (cin >> word) {
            if (word == currWord) {
                cnt++;
                if (cnt == 2) {
                    cout << currWord << endl;
                    break;
                }
            } else {
                cnt = 1;
                currWord = word;
            }
        }
        if (cnt != 2) {
            cout << "no word is repeated!" << endl;
        }
    }
    return 0;
}