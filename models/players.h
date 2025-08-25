#ifndef PLAYERS_H
#define PLAYERS_H
#include "../methods/lifo.h"
#include <string>

class Players {
private:
    char letter;
    std::string color;
    int points;
    int totalBox;
    int totalBoxRow;
    int totalBoxColumn;
    int totalPowers;
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
    int getTotalBox() const;
    int getTotalBoxRow() const;
    int getTotalBoxColumn() const;
    int getTotalPowers() const;
    LIFO &getPowerStack();


    // setters
    void setLetter(char letter);
    void setColor(const std::string& color);
    void setPoints(int point);
    void setTotalBox(int total);

    void setTotalBoxRow(int totalRow);
    void setTotalBoxColumn(int totalColumn);
    void setTotalPowers(int totalPower);
    // metodos
    void addPoints(int point);
    void addTotalBox(int total);
    void addTotalBoxRow(int totalRow);
    void addTotalBoxColumn(int totalColumn);
    void addTotalPowers(int totalPower);
    void addPower(PowerManager::PowerEnum power);
    PowerManager::PowerEnum usePower();
    bool isPowerStack() const;
};

#endif // PLAYERS_H
