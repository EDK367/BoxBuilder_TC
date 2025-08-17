#include "nodelifo.h"

NodeLIFO::NodeLIFO() : power(nullptr), next(nullptr)
{}

NodeLIFO::~NodeLIFO() {}

PowerManager::PowerEnum *NodeLIFO::getPower() const
{
    return power;
}

NodeLIFO *NodeLIFO::getNext() const
{
    return next;
}

void NodeLIFO::setPower(PowerManager::PowerEnum *power)
{
    this->power = power;
}

void NodeLIFO::setNext(NodeLIFO *next)
{
    this->next = next;
}
