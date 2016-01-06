#include <fstream>
#include <iterator>

using std::istream_iterator;
using std::ostream_iterator;
using std::ifstream;
using std::ofstream;

int main(int argc, char **argv)
{
    ifstream ifile(argv[1]);
    ofstream ofile(argv[2]), ofile2(argv[3]);
    istream_iterator<int> in(ifile), eof;
    ostream_iterator<int> out(ofile, " "), out2(ofile2, " ");

    while (in != eof) {
        if (*in % 2) {
            *out++ = *in;
        } else {
            *out2++ = *in;
        }
        ++in;
    }
}