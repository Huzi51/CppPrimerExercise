#include <string>

std::string make_plural(size_t n, const std::string &word,
                        const std::string &ending)
{
    return (n > 1) ? word + ending : word;
