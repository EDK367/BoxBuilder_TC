#ifndef LIFO_H
#define LIFO_H
#include "../models/enum/powermanager.h"
#include "../models/nodelifo.h"

class LIFO
{
private:
    PowerManager::PowerEnum power;
    NodeLIFO *top;

public:
    // constructor y destructor
    LIFO();
    ~LIFO();

    // metodos de fila
    void push(PowerManager::PowerEnum power);
    PowerManager::PowerEnum pop();
    PowerManager::PowerEnum peek() const;
    bool isEmpty() const;
};

#endif // LIFO_H
