#ifndef PLAYERS_H
#define PLAYERS_H
#include "../methods/lifo.h"
#include <string>

class Players {
private:
    char letter;
    std::string color;
    int points;
    LIFO powerStack;


public:
    // consturctores
    Players();
    Players(char letter, const std::string& color);
    Players(char letter, const std::string& color, int points);


    // getters
    char getLetter() const;
    std::string getColor() const;
    int getPoints() const;
    LIFO &getPowerStack();

    // setters
    void setLetter(char letter);
    void setColor(const std::string& color);
    void setPoints(int point);

    // metodos
    void addPoints(int point);
    void addPower(PowerManager::PowerEnum* power);
    PowerManager::PowerEnum* usePower();
    bool isPowerStack() const;
};

#endif // PLAYERS_H
