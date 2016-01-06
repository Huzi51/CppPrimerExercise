#include <random>
using std::default_random_engine;
using std::uniform_int_distribution;

unsigned rand_unif(unsigned min, unsigned max, unsigned seed = 0)
{
    default_random_engine e(seed);
    uniform_int_distirbution u(min, max);
    return u(e);
}