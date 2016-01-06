#include <iostream>
#include <string>
#include <cctype>
using std::string;

int main()
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, blankCnt = 0, tabCnt = 0, newlineCnt = 0;
    unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;
    char ch;
    string s;
    while (std::cin >> ch) {
        s += ch;
        switch (tolower(ch)) {
        case 'a':
            ++aCnt;
            break;
        case 'e':
            ++eCnt;
            break;
        case 'o':
            ++oCnt;
            break;
        case 'u':
            ++uCnt;
            break;
        case ' ':
            ++blankCnt;
            break;
        case '\t':
            ++tabCnt;
            break;
        case '\n':
            ++newlineCnt;
            break;
        case 'f':
            if(s == "ff") { // count ff
                ++ffCnt;
                s = "";
            }
            break;
        case 'l':
            if(s == "fl") { // coutn fl
                ++flCnt;
                s = "";
            }
            break;
        case 'i':
            if (s == "fi") {
                ++fiCnt;
                s = "";
            }
            ++iCnt;
            break;
        }
    }
    std::cout << "Number of vowel a: \t" << aCnt << '\n'
              << "Number of vowel e: \t" << eCnt << '\n'
              << "Number of vowel i: \t" << iCnt << '\n'
              << "Number of vowel o: \t" << oCnt << '\n'
              << "Number of vowel u: \t" << uCnt << '\n'
              << "Number of vowel blank: \t" << blankCnt << '\n'
              << "Number of vowel ff: \t" << ffCnt << '\n'
              << "Number of vowel fl: \t" << flCnt << '\n'
              << "Number of vowel fi: \t" << fiCnt << '\n'
              << "Number of vowel tab: \t" << tabCnt << '\n'
              << "Number of vowel newline: \t" << newlineCnt << std::endl;

    return 0;
}