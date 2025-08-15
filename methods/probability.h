#ifndef PROBABILITY_H
#define PROBABILITY_H
#include "randomnative.h"

class Probability
{
private:
    RandomNative random;

public:
    Probability();
    bool powerChance();
};

#endif // PROBABILITY_H
