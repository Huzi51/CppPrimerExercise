#include <vector>
using std::vector;

#include <string>
using std::string;

#include <tuple>
using std::tuple;
using std::make_tuple;
using std::get;

#include <algorithm>
using std::equal_range;
using std::accumulate;

#include <iostream>
using std::istream; using std::ostream;
using std::cout; using std::endl;
using std::cin;

#include <fstream>
using std::ifstream;

#include <cassert>

#include "../chap7/Sales_data.hpp"

typedef tuple<vector<Sales_data>::size_type,
              vector<Sales_data>::const_iterator,
              vector<Sales_data>::const_iterator> matches;

vector<matches>
findBook(const vector<vector<Sales_data> > &files, const string &book)
{
    vector<matches> ret;

    for(auto beg = files.cbegin(); beg != files.cend(); beg++)
    {
        auto result = equal_range(beg->cbegin(), beg->cend(), book, compareISBN);
        if (result.first != result.second)
        {
            ret.push_back(make_tuple(beg - files.cbegin(), result.first, result.second));
        }
    }
    return ret;
}

// reportResult
void reportResults(istream &in, ostream &out,
                   const vector<vector<Sales_data> > &files)
{
    string book;
    while (in >> book)
    {
        auto trans = findBook(files, book);
        if (trans.empty())
        {
            cout << "not found in any stores." << endl;;
            continue;
        }
        for (const auto &store : trans)
        {
            out << "store: " << get<0>(store) << " sales: "
                << accumulate(get<1>(store), get<2>(store), Sales_data(book))
                << endl;
        }
    }
}

// build_store
vector<Sales_data> build_store(const string &s)
{
    vector<Sales_data> ret;
    ifstream is(s);
    Sales_data item;

    while (is >> item) {
        ret.push_back(item);
    }
    sort(ret.begin(), ret.end(), compareISBN);
    return ret;
}

int main(int argc, char ** argv)
{
    vector<vector<Sales_data> > files;

    for (int cnt = 1; cnt != argc; ++cnt)
    {
        files.push_back(build_store(argv[cnt]));
    }

    reportResults(cin, cout, files);

    return 0;
}