#include "node.h"

Node::Node(int x, int y) : x(x), y(y)
{

}

NodePosition Node::getNodePosition() const
{
    return {getX(), getY()};
}

int Node::getX() const
{
    return x;
}

void Node::setX(int newX)
{
    x = newX;
}

int Node::getY() const
{
    return y;
}

void Node::setY(int newY)
{
    y = newY;
}
