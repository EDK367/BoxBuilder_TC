#include "nodelinked.h"

NodeLinked::NodeLinked() : power(PowerManager::PowerEnum::NONE)
{}


void NodeLinked::setLinked(Node *startLinked, Node *endLinked, PowerManager::PowerEnum power)
{
    this->startLinked = startLinked;
    this->endLinked = endLinked;
    this->power = power;
}

// getter y setter
Node *NodeLinked::getStartLinked() const
{
    return startLinked;
}

Node *NodeLinked::getEndLinked() const
{
    return endLinked;
}

PowerManager::PowerEnum NodeLinked::getPower() const
{
    return power;
}

void NodeLinked::setStartLinked(Node *startLinked)
{
    this->startLinked = startLinked;
}

void NodeLinked::seEndLinked(Node *endLinked)
{
    this->endLinked = endLinked;
}

void NodeLinked::setPower(PowerManager::PowerEnum power)
{
    this->power = power;
}
