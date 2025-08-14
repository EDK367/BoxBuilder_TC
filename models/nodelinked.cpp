#include "nodelinked.h"

NodeLinked::NodeLinked() {}


void NodeLinked::setLinked(Node *startLinked, Node *endLinked, bool power)
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
bool NodeLinked::getPower() const
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
bool NodeLinked::setPower(bool power)
{
    this->power = power;
}
