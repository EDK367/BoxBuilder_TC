#include "nodofifo.h"

NodoFIFO::NodoFIFO() : player(nullptr), next(nullptr)
{}

Players *NodoFIFO::getPlayer()
{
    return player;
}


NodoFIFO *NodoFIFO::getNext()
{
    return next;
}

void NodoFIFO::setPlayer(Players *player)
{
    this->player = player;
}

void NodoFIFO::setNext(NodoFIFO *next)
{
    this->next = next;
}
