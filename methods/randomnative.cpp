#include "randomnative.h"
#include <ctime>

RandomNative::RandomNative(unsigned int limit) : limit(limit),
    seed(static_cast<unsigned int>(std::time(nullptr)))
{
    seed = static_cast<unsigned int>(std::time(nullptr));
}

void RandomNative::setLimit(unsigned int newLimit) {
    limit = newLimit;
}

unsigned int RandomNative::operator ()()
{
    seed = (1103515245 * seed + 12345) % 2147483648;
    return seed % limit;
}

RandomNative RandomNative::generateRandom(unsigned int limit)
{
    return RandomNative(limit);
}
