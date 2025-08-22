#include "controllerBL.h"

ControllerBL::ControllerBL() : nodeLinkedController(nullptr), count(0)
{}

NodeLinked *ControllerBL::getNodeLinkedController() const
{
    return this->nodeLinkedController;
}

int ControllerBL::getCount() const
{
    return this->count;
}

void ControllerBL::setNodeLinkedController(NodeLinked *nodeLinked)
{
    this->nodeLinkedController = nodeLinked;
}

void ControllerBL::setCount(int count)
{
    this->count += count;
}
