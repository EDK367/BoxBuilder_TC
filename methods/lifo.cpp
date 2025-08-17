#include "lifo.h"

LIFO::LIFO() : top(nullptr)
{}

LIFO::~LIFO() {
    while (!isEmpty()) {
        pop();
    }
}

// insertar datos
void LIFO::push(PowerManager::PowerEnum *power)
{
    NodeLIFO *newNode = new NodeLIFO();
    newNode->setPower(power);
    newNode->setNext(top);
    top = newNode;
}

// eliminar el princio de la pila
PowerManager::PowerEnum *LIFO::pop()
{
    if (isEmpty())
    {
        return nullptr;
    }
    NodeLIFO *temp = top;
    PowerManager::PowerEnum *power = temp->getPower();
    top = top->getNext();
    return power;
}

bool LIFO::isEmpty() const
{
    return top == nullptr;
}
