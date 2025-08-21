#include "fourthclass.h"

FourthClass::FourthClass() {}

// poderes malditos cuarta clase
bool FourthClass::getFourthClass(PowerManager::PowerEnum power)
{
    switch (power) {
        // poder maldito clase D Duplicacion
    case PowerManager::PowerEnum::DL:
        return true;
        break;
    default:
        return false;
        break;
    }
}
