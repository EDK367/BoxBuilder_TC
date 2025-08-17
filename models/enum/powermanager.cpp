#include "powermanager.h"

PowerManager::PowerManager() {}

std::string PowerManager::getPowerString(PowerEnum power)
{
    static const std::string powers[] = {
    "DL",   "TS",   "BL",   "PS",   "LS",
    "ES",   "UF",   "AC",   "NT",   "EX"
                                        };


    return powers[static_cast<int>(power)];
}

PowerManager::PowerEnum *PowerManager::getPowerEnum(int numberPower)
{
    if (numberPower < 0 || (numberPower > 9))
    {
        return 0;
    }
    return new PowerEnum(static_cast<PowerEnum>(numberPower));
}
