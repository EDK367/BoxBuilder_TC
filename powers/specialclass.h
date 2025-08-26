#ifndef SPECIALCLASS_H
#define SPECIALCLASS_H
#include "../models/nodeboard.h"
#include "../models/nodeinfo.h"
#include "../models/players.h"
#include "../utils/boxgraphics.h"
#include "../utils/clickgraphics.h"
#include "../rules/gamerules.h"

class SpecialClass
{
public:
    SpecialClass();
    bool getPowerEX(GameRules &gameRules, NodeBoard *board);
};

#endif // SPECIALCLASS_H
