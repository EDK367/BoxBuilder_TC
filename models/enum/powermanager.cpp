#include "powermanager.h"

PowerManager::PowerManager() {}

std::string PowerManager::getPowerString(PowerEnum power)
{
    static const std::string powers[] = {
    "DL",   "TS",   "BL",   "PS",   "LS",
    "ES",   "UF",   "AC",   "NT",   "EX"
                                        };

    if(power == PowerEnum::NONE)
    {
        return "NONE";
    }

    int index = static_cast<int>(power);
    if (index >= 0 && index < 10)
    {
        return powers[index];
    }

    return "NONE";
}

PowerManager::PowerEnum PowerManager::getPowerEnum(int numberPower)
{
    if (numberPower < 0 || (numberPower > 9))
    {
        return PowerEnum::NONE;
    }
    return static_cast<PowerEnum>(numberPower);
}
