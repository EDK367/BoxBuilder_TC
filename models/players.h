#ifndef PLAYERS_H
#define PLAYERS_H

#include <string>

class Players {
private:
    char letter;
    std::string color;
    int points;

public:
    // consturctores
    Players();
    Players(char letter, const std::string& color);
    Players(char letter, const std::string& color, int points);


    // getters
    char getLetter() const;
    std::string getColor() const;
    int getPoints() const;

    // setters
    void setLetter(char letter);
    void setColor(const std::string& color);
    void setPoints(int point);

    // metodos
    void addPoints(int point);
};

#endif // PLAYERS_H
