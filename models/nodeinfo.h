#ifndef NODEINFO_H
#define NODEINFO_H
#include "../utils/boxgraphics.h"
#include "../models/enum/PowerManager.h"

class NodeInfo
{
private:
    bool isConnectedUp;
    bool isConnectedDown;
    bool isConnectedLeft;
    bool isConnectedRight;
    // si posee un poder
    PowerManager::PowerEnum *power;
    BoxGraphics *square;


public:
    NodeInfo();
    ~NodeInfo();


    // getter y setter
    bool getIsConnectedUp() const;
    bool getIsConnectedDown() const;
    bool getIsConnectedLeft() const;
    bool getIsConnectedRight() const;

    PowerManager::PowerEnum *getPower() const;
    BoxGraphics *getSquare() const;

    void setIsConnectedUp(bool value);
    void setIsConnectedDown(bool value);
    void setIsConnectedLeft(bool value);
    void setIsConnectedRight(bool value);

    void setPower(PowerManager::PowerEnum *power);
    void setSquare(BoxGraphics *square);
};

#endif // NODEINFO_H
