#ifndef FIFO_H
#define FIFO_H
#include "../models/players.h"
#include "../models/nodefifo.h"

class FIFO
{
private:
    Players *players;
    // enlaces
    NodeFIFO *front;
    NodeFIFO *end;

public:
    // constructor
    FIFO();

    // destructor
    virtual ~FIFO();

    // metodos
    void enqueue(Players *player);
    bool isEmpty();
    void dequeue();
    Players *peak();
    Players *peakEnd();

    // get
    NodeFIFO *getFront();
    NodeFIFO *getEnd();
};

#endif // FIFO_H
