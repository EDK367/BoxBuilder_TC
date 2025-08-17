#ifndef POWERMANAGER_H
#define POWERMANAGER_H
#include <string>

class PowerManager {
public:
    PowerManager();
    enum class PowerEnum {
        DL = 0, // 0
        TS = 1, // 1
        BL = 2, // 2
        PS = 3, // 3
        LS = 4, // 4
        ES = 5, // 5
        UF = 6, // 6
        AC = 7, // 7
        NT = 8, // 8
        EX = 9  // 9
    };

    static PowerEnum *getPowerEnum(int numberPower);

    static std::string getPowerString(PowerEnum power);

};


#endif // POWERMANAGER_H
