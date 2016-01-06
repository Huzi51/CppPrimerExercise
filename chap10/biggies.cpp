#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;

void elimDups(vector<string> &svec);
std::string make_plural(size_t n, const string &word,
                        const string &ending);

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);

    stable_sort(words.begin(), words.end(),
                [](const string &s1, const string &s2)
                { return s1.size() < s2.size(); });
    auto it = find_if (words.begin(), words.end(),
                       [sz](const string &a)
                       { return a.size() >= sz; });
    auto count = words.end() - it;
    cout << count << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;

    for_each(it, words.end(),
             [](const string &s)
             { cout << s << " "; });
    cout << endl;
}