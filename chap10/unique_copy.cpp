#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::back_inserter;

int main()
{
    vector<int> ivec{1,1,2,3,4,5,5,6,7};
    list<int> ilst;
    unique_copy(ivec.begin(), ivec.end(),
                back_inserter(ilst));
    copy(ilst.begin(), ilst.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}
