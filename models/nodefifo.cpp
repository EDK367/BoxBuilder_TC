#include "nodefifo.h"

NodeFIFO::NodeFIFO() : player(nullptr), next(nullptr)
{}

Players *NodeFIFO::getPlayer() const
{
    return player;
}


NodeFIFO *NodeFIFO::getNext() const
{
    return next;
}

void NodeFIFO::setPlayer(Players *player)
{
    this->player = player;
}

void NodeFIFO::setNext(NodeFIFO *next)
{
    this->next = next;
}
