#ifndef SORTARRAYPLAYERS_H
#define SORTARRAYPLAYERS_H
#include "../models/players.h"

class SortArrayPlayers
{
private:
    void merge(Players playersArray[], int start, int middle, int end);

public:
    SortArrayPlayers();
    void mergeSortPlayers(Players playersArray[], int start, int end);

};

#endif // SORTARRAYPLAYERS_H
