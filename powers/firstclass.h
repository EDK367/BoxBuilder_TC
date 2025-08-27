#ifndef FIRSTCLASS_H
#define FIRSTCLASS_H
#include "../rules/gamerules.h"
#include "../models/nodeboard.h"
#include "../models/nodelinked.h"
#include "../models/enum/powermanager.h"
#include "../models/nodeinfo.h"
#include "../methods/nodevector.h"
#include "../models/players.h"
#include "../utils/clickgraphics.h"

// primera clase de podres, clase A
class FirstClass
{

private:
    PowerManager::PowerEnum newPower = PowerManager::PowerEnum::NONE;

public:
    FirstClass();

    bool getPowerBL(GameRules &gameRules, NodeBoard *board, Players *playerCurrent);
    bool getPowerES(PowerManager::PowerEnum power);

    void resetPowerBL(GameRules &gameRules);
};

#endif // FIRSTCLASS_H
