#include "nodeinfo.h"

NodeInfo::NodeInfo() : isConnectedUp(false), isConnectedDown(false),
    isConnectedLeft(false), isConnectedRight(false), player(nullptr), square(nullptr),
    power(PowerManager::PowerEnum::NONE),
    linkUp(nullptr), linkDown(nullptr), linkLeft(nullptr), linkRight(nullptr)
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

Players *NodeInfo::getPlayer() const
{
    return player;
}

PowerManager::PowerEnum NodeInfo::getPower() const
{
    return power;
}

BoxGraphics *NodeInfo::getSquare() const
{
    return square;
}

NodeLinked *NodeInfo::getLinkUp() const
{
    return linkUp;
}

NodeLinked *NodeInfo::getLinkDown() const
{
    return linkDown;
}

NodeLinked *NodeInfo::getLinkLeft() const
{
    return linkLeft;
}

NodeLinked *NodeInfo::getLinkRight() const
{
    return linkRight;
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

void NodeInfo::setPlayer(Players *player)
{
    this->player = player;
}

void NodeInfo::setPower(PowerManager::PowerEnum power)
{
    this->power = power;
}

void NodeInfo::setSquare(BoxGraphics *square)
{
    this->square = square;
}

void NodeInfo::setLinkUp(NodeLinked *linkUp)
{
    this->linkUp = linkUp;
}

void NodeInfo::setLinkDown(NodeLinked *linkDown)
{
    this->linkDown = linkDown;
}

void NodeInfo::setLinkLeft(NodeLinked *linkLeft)
{
    this->linkLeft = linkLeft;
}

void NodeInfo::setLinkRight(NodeLinked *linkRight)
{
    this->linkRight = linkRight;
}
