#ifndef FIFO_H
#define FIFO_H
#include "../models/players.h"
#include "../models/nodofifo.h"

class FIFO
{
private:
    Players *players;
    // enlaces
    NodoFIFO *front;
    NodoFIFO *end;

    // elemento insertado
    int rear;
    // total de elementos
    int count;

public:
    // constructor
    FIFO();

    // destructor
    virtual ~FIFO();

    // metodos
    void enqueue(Players *player);
    bool isEmpty();
    void dequeue(Players *player);
    Players *peak();

    // get
    NodoFIFO *getFront();

};

#endif // FIFO_H
