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

LIFO &Players::getPowerStack() {
    return powerStack;
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

void Players::addPower(PowerManager::PowerEnum *power)
{
    powerStack.push(power);
}

PowerManager::PowerEnum *Players::usePower()
{
    powerStack.pop();
}

bool Players::isPowerStack() const
{
    return !powerStack.isEmpty();
}
