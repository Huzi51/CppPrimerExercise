#include <iostream>
#include <string>

int main()
{
    int dup_cnt = 0, max_dup = 0;
    std::string word, currWord, dup_word;

    if (std::cin >> currWord) {
        dup_cnt++; // count current word
        while (std::cin >> word) {
            if (word == currWord) {
                dup_cnt++;
            } else {
                if (dup_cnt > max_dup) {
                    max_dup = dup_cnt;
                    dup_word = currWord;
                }
                dup_cnt = 1;
                currWord = word;
            }
        }
        std::cout << "maxinum number of duplicates is " << max_dup << " times " << dup_word << std::endl;
    }
    return 0;
}