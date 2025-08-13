#ifndef ARRAYMESS_H
#define ARRAYMESS_H
#include "../models/players.h"
#include "randomnative.h"

class ArrayMess
{

private:
    RandomNative random;

public:
    ArrayMess();
    void shufflePlayers(Players playersInput[], int size);
};

#endif // ARRAYMESS_H
