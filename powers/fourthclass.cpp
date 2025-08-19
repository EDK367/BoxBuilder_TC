#include "fourthclass.h"

FourthClass::FourthClass() {}

bool FourthClass::getFourthClass(PowerManager::PowerEnum power)
{
    switch (power) {
    case PowerManager::PowerEnum::DL:
        return true;
        break;
    default:
        return false;
        break;
    }
}
