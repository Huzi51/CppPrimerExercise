#include <fstream>
void word_transform(std::ifstream&, std::ifstream&);

int main(int argc, char **argv)
{
    std::ifstream mapFile(argv[1]);
    std::ifstream input(argv[2]);

    word_transform(mapFile, input);
}