#ifndef SECONDCLASS_H
#define SECONDCLASS_H
#include "../rules/gamerules.h"
#include "../models/nodeboard.h"
#include "../models/nodelinked.h"
#include "../models/enum/powermanager.h"
#include "../models/nodeinfo.h"
#include "../models/players.h"
#include "../utils/boxgraphics.h"
#include <iostream>

// segunda clase de poderes, classe B
class SecondClass
{
public:
    SecondClass();
    bool getPowerTS(GameRules &gameRules, NodeBoard *board, Players *playerCurrent);
};

#endif // SECONDCLASS_H
