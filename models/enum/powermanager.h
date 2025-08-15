#ifndef POWERMANAGER_H
#define POWERMANAGER_H
#include <string>

class PowerManager {
public:
    PowerManager();
    enum class PowerEnum {
        DL, // 0
        TS, // 1
        BL, // 2
        PS, // 3
        LS, // 4
        ES, // 5
        UF, // 6
        AC, // 7
        NT, // 8
        EX  // 9
    };
    static std::string getPower(int numberPower);
};


#endif // POWERMANAGER_H
