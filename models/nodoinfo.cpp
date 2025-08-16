#include "nodoinfo.h"

NodoInfo::NodoInfo() : isConnectedUp(false), isConnectedDown(false),
    isConnectedLeft(false), isConnectedRight(false)
{}


// getter y setter
bool NodoInfo::getIsConnectedUp() const
{
    return isConnectedUp;
}
bool NodoInfo::getIsConnectedDown() const
{
    return isConnectedDown;
}
bool NodoInfo::getIsConnectedLeft() const
{
    return isConnectedLeft;

}
bool NodoInfo::getIsConnectedRight() const
{
    return isConnectedRight;
}

void NodoInfo::setIsConnectedUp(bool value)
{
    isConnectedUp = value;
}
void NodoInfo::setIsConnectedDown(bool value)
{
    isConnectedDown = value;
}
void NodoInfo::setIsConnectedLeft(bool value)
{
    isConnectedLeft = value;
}
void NodoInfo::setIsConnectedRight(bool value)
{
    this->isConnectedRight = value;
}
