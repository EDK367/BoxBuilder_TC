#include "thirdclass.h"

ThirdClass::ThirdClass() {}

// poderes malditos tercera clase
bool ThirdClass::getThirdClass(GameRules &gameRules, PowerManager::PowerEnum power)
{
    switch (power) {
        // poder maldito Clase C Pase
    case PowerManager::PowerEnum::PS:
        gameRules.dequeuePlayer();
        return true;
        break;
    default:
        return false;
        break;
    }
}
