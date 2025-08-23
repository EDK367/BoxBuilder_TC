#include "fifo.h"

FIFO::FIFO() : front(nullptr), end(nullptr)
{}

FIFO::~FIFO() {
    while (!isEmpty()) {
        NodeFIFO *temp = front;
        front = front->getNext();
        delete temp;
    }
}


void FIFO::enqueue(Players *player)
{
    NodeFIFO *newNodeFIFO = new NodeFIFO();

    newNodeFIFO->setPlayer(player);
    newNodeFIFO->setNext(nullptr);

    if (isEmpty())
    {
        front = newNodeFIFO;
    } else {
        end->setNext(newNodeFIFO);
    }

    end = newNodeFIFO;
}

bool FIFO::isEmpty()
{
    return !front;
}

void FIFO::dequeue()
{

    NodeFIFO *aux = front;
    Players *player = front->getPlayer();
    if (front == end)
    {
        front = nullptr;
        end = nullptr;
    } else {
        front = front->getNext();
        enqueue(player);
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

Players *FIFO::peakEnd()
{
    if (!isEmpty())
    {
        return end->getPlayer();
    }
    return nullptr;
}

NodeFIFO *FIFO::getEnd()
{
    return end;
}

NodeFIFO *FIFO::getFront()
{
    return front;
}
