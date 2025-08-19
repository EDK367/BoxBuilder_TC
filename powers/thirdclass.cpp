#include "thirdclass.h"

ThirdClass::ThirdClass() {}

bool ThirdClass::getThirdClass(GameRules &gameRules, PowerManager::PowerEnum power)
{
    switch (power) {
    case PowerManager::PowerEnum::PS:
        gameRules.dequeuePlayer();
        return true;
        break;
    default:
        return false;
        break;
    }
}
