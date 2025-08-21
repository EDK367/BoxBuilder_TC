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
private:
    PowerManager::PowerEnum newPower = PowerManager::PowerEnum::NONE;

public:
    SecondClass();
    bool getPowerTS(GameRules &gameRules, NodeBoard *board, Players *playerCurrent);
    bool getPowerUF(GameRules &gameRules, NodeBoard *board, Players *playerCurrent);
    bool getPowerAC(GameRules &gameRules, NodeBoard *board, Players *playerCurrent);

    void resetTurns(GameRules &gameRules, Players *playerLink);
};

#endif // SECONDCLASS_H
