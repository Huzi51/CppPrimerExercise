#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <algorithm>
#include <iterator>

using std::vector;
using std::list;
using std::forward_list;
using std::deque;
using std::cout;
using std::endl;
using std::back_inserter;
using std::front_inserter;
using std::inserter;
using std::ostream_iterator;

int main()
{
    vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};

    list<int> ilst;
    copy(ivec.begin(), ivec.end(), inserter(ilst, ilst.begin()));
    copy(ilst.begin(), ilst.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    forward_list<int> flst;
    copy(ivec.begin(), ivec.end(), front_inserter(flst));
    copy(flst.begin(), flst.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    deque<int> ique;
    copy(ivec.begin(), ivec.end(), back_inserter(ique));
    copy(ique.begin(), ique.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

