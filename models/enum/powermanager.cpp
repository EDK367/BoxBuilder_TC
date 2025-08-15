#include "powermanager.h"

PowerManager::PowerManager() {}

std::string PowerManager::getPower(int numberPower)
{
    static const std::string powers[] = {"DL",
                                         "TS",
                                         "BL",
                                         "PS",
                                         "LS",
                                         "ES",
                                         "UF",
                                         "AC",
                                         "NT",
                                         "EX"};


    if(numberPower < 0 && (numberPower > 9))
    {
        return "";
    }

    return powers[numberPower];
}
