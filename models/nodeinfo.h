#ifndef NODEINFO_H
#define NODEINFO_H
#include "../utils/boxgraphics.h"
#include "../models/enum/PowerManager.h"
#include "../models/players.h"
#include "nodelinked.h"

class NodeInfo
{
private:
    bool isConnectedUp;
    bool isConnectedDown;
    bool isConnectedLeft;
    bool isConnectedRight;
    Players *player;
    // si posee un poder
    PowerManager::PowerEnum power;
    BoxGraphics *square;

    // es el enlace a un nodo
    NodeLinked *linkUp;
    NodeLinked *linkDown;
    NodeLinked *linkLeft;
    NodeLinked *linkRight;

public:
    NodeInfo();
    ~NodeInfo();


    // getter y setter
    bool getIsConnectedUp() const;
    bool getIsConnectedDown() const;
    bool getIsConnectedLeft() const;
    bool getIsConnectedRight() const;

    Players *getPlayer() const;
    PowerManager::PowerEnum getPower() const;
    BoxGraphics *getSquare() const;
    NodeLinked *getLinkUp() const;
    NodeLinked *getLinkDown() const;
    NodeLinked *getLinkLeft() const;
    NodeLinked *getLinkRight() const;



    void setIsConnectedUp(bool value);
    void setIsConnectedDown(bool value);
    void setIsConnectedLeft(bool value);
    void setIsConnectedRight(bool value);

    void setPlayer(Players *player);

    void setPower(PowerManager::PowerEnum power);
    void setSquare(BoxGraphics *square);

    void setLinkUp(NodeLinked *linkUp);
    void setLinkDown(NodeLinked *linkDown);
    void setLinkLeft(NodeLinked *linkLeft);
    void setLinkRight(NodeLinked *linkRight);
};

#endif // NODEINFO_H
