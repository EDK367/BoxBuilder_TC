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

std::string PowerManager::getPowerColor(PowerEnum power)
{
    static const std::string colors[] = {
        "#808080", // gris
        "#FF0000", // rojo
        "#0000FF", // azul
        "#00FF00", // verde
        "#00FFFF", // cyan
        "#98FB98", // verde claro
        "#800080", // morado
        "#FF69B4", // rosa
        "#8A2BE2", // azul violeta
        "#FF4500", // rojo naranja
    };
    if(power == PowerEnum::NONE)
    {
        return "#000000";
    }

    int index = static_cast<int>(power);
    if (index >= 0 && index < 10)
    {
        return colors[index];
    }

    return "#000000";
}

PowerManager::PowerEnum PowerManager::getPowerEnum(int numberPower)
{
    if (numberPower < 0 || (numberPower > 9))
    {
        return PowerEnum::NONE;
    }
    return static_cast<PowerEnum>(numberPower);
}
