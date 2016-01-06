#ifndef TEXTQUERY_HPP
#define TEXTQUERY_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <new>

class QueryResult;
class TextQuery {
public:
    typedef std::vector<std::string> >::size_type line_no;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
private:
    std::shared_ptr<std::vector<std::string> > file;
    std::map<std::string,
             std::shared_ptr<std::set<line_no> > >  data;
};
// TextQuery constructors
inline
TextQuery::TextQuery(std::ifstream &input):
    file(new std::vector<std::string>) {
    std::string line;
    while (getline(input, line)) {
        file->push_back(line);
        line_no n = file->size() - 1;
        std::istringstream in(line);
        std::string word;
        while (in >> word) {
            auto &sp = data[word];
            if (!sp) {
                sp.reset(new std::set<line_no>);
            }
            sp->insert(n);
        }
    }
}

std::ostream &print(std::ostream&, const QueryResult&);

// class QueryResult
class QueryResult {
    friend std::ostream &print(std::ostream&, const QueryResult&);
public:
    typedef std::vector<std::string>::size_type line_no;
    typedef std::set<line_no>::const_iterator line_it;
    QueryResult(std::string w,
                std::shared_ptr<std::set<line_no> > ln,
                std::shared_ptr<std::vector<std::string> > f):
        word(w), lnum(ln), fl(f) { }
    line_it begin() const { return lnum->cbegin(); }
    line_it end() const { return lnum->cend(); }
    std::shared_ptr<std::vector<std::string> > get_file() { return fl; }
private:
    std::string word;
    std::shared_ptr<std::set<line_no> > lnum;
    std::shared_ptr<std::vector<std::string> > fl;
};
// TextQuery::query
QueryResult
TextQuery::query(const std::string &s) const {
    std::shared_ptr<std::set<line_no> > nodata(new std::set<line_no>);
    auto it = data.find(s);
    if (it != data.end()) {
        return QueryResult(s, it->second, file);
    } else {
        return QueryResult(s, nodata, file);
    }
}
std::ostream &print (std::ostream &os, const QueryResult &result) {
    os << result.word << " occurs " << result.lnum->size()
       << ( (result.lnum->size() > 1) ? " times " : " time ")
       << std::endl;
    for (auto num : *result.lnum) {
        os << "\t(line " << num + 1 << ")" << (*result.fl)[num] << std::endl;
    }
    return os;
}
#endif