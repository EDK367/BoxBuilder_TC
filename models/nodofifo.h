#ifndef NODOFIFO_H
#define NODOFIFO_H
#include "../models/players.h"

class NodoFIFO
{
private:
    Players *player;
    NodoFIFO *next;

public:
    NodoFIFO();

    Players *getPlayer();
    NodoFIFO *getNext();

    void setPlayer(Players *player);
    void setNext(NodoFIFO *next);
};

#endif // NODOFIFO_H
