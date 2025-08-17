#ifndef NODEFIFO_H
#define NODEFIFO_H
#include "../models/players.h"

class NodeFIFO
{
private:
    Players *player;
    NodeFIFO *next;

public:
    NodeFIFO();
    ~NodeFIFO() = default;

    Players *getPlayer() const;
    NodeFIFO *getNext() const;

    void setPlayer(Players *player);
    void setNext(NodeFIFO *next);
};

#endif // NODEFIFO_H
