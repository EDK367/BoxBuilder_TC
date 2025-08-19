#ifndef THIRDCLASS_H
#define THIRDCLASS_H
#include "../rules/gamerules.h"
#include "../models/enum/powermanager.h"

// tercera clase de poderes, clase C
class ThirdClass
{
public:
    ThirdClass();

    bool getThirdClass(GameRules &gameRules, PowerManager::PowerEnum power);
};

#endif // THIRDCLASS_H
