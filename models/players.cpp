#include "players.h"

// constructores
Players::Players()
    : letter(' '), color(""), points(0) {}

Players::Players(char letter, const std::string& color)
    : letter(letter), color(color), points(0) {}

Players::Players(char letter, const std::string& color, int points)
    : letter(letter), color(color), points(points) {}


// getters
char Players::getLetter() const
{
    return letter;
}

std::string Players::getColor() const
{
    return color;
}

int Players::getPoints() const
{
    return points;
}

// setters
void Players::setLetter(char letter)
{
    this->letter = letter;
}

void Players::setColor(const std::string& color)
{
    this->color = color;
}

void Players::setPoints(int point)
{
    this->points = point;
}


// otros metodos
void Players::addPoints(int point)
{
    this->points += point;
}
