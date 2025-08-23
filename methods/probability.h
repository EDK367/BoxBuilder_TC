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
    bool evasiveChance();
};

#endif // PROBABILITY_H
