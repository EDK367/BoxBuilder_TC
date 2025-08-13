#ifndef RANDOMNATIVE_H
#define RANDOMNATIVE_H

class RandomNative
{

private:
    unsigned int seed;
    unsigned int limit;

public:
    RandomNative(unsigned int limit = 2);
    void setLimit(unsigned int newLimit);
    unsigned int operator()();
    static RandomNative generateRandom(unsigned int limit);
};

#endif // RANDOMNATIVE_H
