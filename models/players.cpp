#include "players.h"

// constructores
Players::Players()
    : letter(' '), color(""), points(0), totalBox(0) {}

Players::Players(char letter, const std::string& color)
    : letter(letter), color(color), points(0), totalBox(0) {}

Players::Players(char letter, const std::string& color, int points)
    : letter(letter), color(color), points(points), totalBox(0) {}


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

int Players::getTotalBox() const
{
    return totalBox;
}

int Players::getTotalBoxRow() const
{
    return totalBoxRow;
}

int Players::getTotalBoxColumn() const
{
    return totalBoxColumn;
}

int Players::getTotalPowers() const
{
    return totalPowers;
}

LIFO &Players::getPowerStack()
{
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

void Players::setTotalBox(int total)
{
    this->totalBox = total;
}

void Players::setTotalBoxRow(int totalRow)
{
    this->totalBoxRow = totalRow;
}

void Players::setTotalBoxColumn(int totalColumn)
{
    this->totalBoxColumn = totalColumn;
}

void Players::setTotalPowers(int totalPower)
{
    this->totalPowers = totalPower;
}

// otros metodos
void Players::addPoints(int point)
{
    this->points += point;
}

void Players::addTotalBox(int total)
{
    this->totalBox += total;
}

void Players::addTotalBoxRow(int totalRow)
{
    this->totalBoxRow += totalRow;
}

void Players::addTotalBoxColumn(int totalColumn)
{
    this->totalBoxColumn += totalColumn;
}

void Players::addTotalPowers(int totalPower)
{
    this->totalPowers += totalPower;
}

void Players::addPower(PowerManager::PowerEnum power)
{
    powerStack.push(power);
}

PowerManager::PowerEnum Players::usePower()
{
    return powerStack.pop();
}

bool Players::isPowerStack() const
{
    return !powerStack.isEmpty();
}
