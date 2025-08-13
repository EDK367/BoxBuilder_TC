#include "fifo.h"

FIFO::FIFO() : front(nullptr), end(nullptr)
{}

FIFO::~FIFO() {
    while (!isEmpty()) {
        NodoFIFO *temp = front;
        front = front->getNext();
        delete temp;
    }
}


void FIFO::enqueue(Players *player)
{
    NodoFIFO *newNodoFIFO = new NodoFIFO();

    newNodoFIFO->setPlayer(player);
    newNodoFIFO->setNext(nullptr);

    if (isEmpty())
    {
        front = newNodoFIFO;
    } else {
        end->setNext(newNodoFIFO);
    }

    end = newNodoFIFO;
}

bool FIFO::isEmpty()
{
    return !front;
}

void FIFO::dequeue(Players *player)
{
    player = front->getPlayer();
    NodoFIFO *aux = front;

    if (front == end)
    {
        front = nullptr;
        end = nullptr;
    } else {
        front = front->getNext();
        enqueue(aux->getPlayer());
    }

    delete aux;
}

Players *FIFO::peak()
{
    if (!isEmpty())
    {
        return front->getPlayer();
    }
    return nullptr;
}

NodoFIFO *FIFO::getFront()
{
    return front;
}
