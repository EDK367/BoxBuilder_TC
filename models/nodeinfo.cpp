#include "nodeinfo.h"

NodeInfo::NodeInfo() : isConnectedUp(false), isConnectedDown(false),
    isConnectedLeft(false), isConnectedRight(false), square(nullptr),
    power(PowerManager::PowerEnum::NONE)
{}

// destructor
NodeInfo::~NodeInfo() {

}

// getter y setter
bool NodeInfo::getIsConnectedUp() const
{
    return isConnectedUp;
}

bool NodeInfo::getIsConnectedDown() const
{
    return isConnectedDown;
}

bool NodeInfo::getIsConnectedLeft() const
{
    return isConnectedLeft;

}
bool NodeInfo::getIsConnectedRight() const
{
    return isConnectedRight;
}

PowerManager::PowerEnum NodeInfo::getPower() const
{
    return power;
}

BoxGraphics *NodeInfo::getSquare() const
{
    return square;
}

void NodeInfo::setIsConnectedUp(bool value)
{
    this->isConnectedUp = value;
}

void NodeInfo::setIsConnectedDown(bool value)
{
    this->isConnectedDown = value;
}

void NodeInfo::setIsConnectedLeft(bool value)
{
    this->isConnectedLeft = value;
}

void NodeInfo::setIsConnectedRight(bool value)
{
    this->isConnectedRight = value;
}

void NodeInfo::setPower(PowerManager::PowerEnum power)
{
    this->power = power;
}

void NodeInfo::setSquare(BoxGraphics *square)
{
    this->square = square;
}
