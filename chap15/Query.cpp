#include "Query.hpp"
#include "TextQuery.h"

#include <memory>
using std::make_shared;

#include <set>
using std::set;

#include <algorithm>
using std::set_intersection;

#include <iterator>
using std::inserter;

#include <cstddef>
using std::size_t;

QueryResult
OrQuery::eval(const TextQuery &text) const {
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret_lines = make_shared<set<line_no> >(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());

    return QueryResult(rep(), ret_lines, left.get_file());
}

// AndQuery::eval
QueryResult
AndQuery::eval(const TextQuery &text) const {
    auto left = lhs.eval(text), right = rhs.eval(text);

    auto ret_lines = make_shared<set<line_no> >();

    set_intersection(left.begin(), left.end(),
                     right.begin(), right.end(),
                     inserter(*ret_lines, ret_lines->begin()));

    return QueryResult(rep(), ret_lines, left.get_file());
}

// OrQuery::eval
QueryResult
NotQuery::eval(const TextQuery &text) const {
    auto result = query.eval(text);
    auto ret_lines = make_shared<set<line_no> >();

    auto lines = make_shared<set<line_no> >(result.begin(), result.end());

    auto sz = result.get_file() -> size();

    for (size_t n = 0; n != sz; n++) {
        if (lines->find(n) == lines->end()) {
            ret_lines->insert(n);
        }
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}

std::ostream&
operator<<(std::ostream &os, const Query &query) {
    os << query.rep();
    return os;
}