#include "GameRules.h"
// para test
#include <iostream>

// instancia
GameRules *GameRules::instance = nullptr;

// constructor
GameRules::GameRules(int sizePlayers) : sizePlayers(sizePlayers)
{
    std::cout << "Creacion de game rules" << std::endl;
    arrayPlayers = new Players[sizePlayers];
}

// destructor
GameRules::~GameRules()
{
    if (arrayPlayers != nullptr)
    {
        delete[] arrayPlayers;
        arrayPlayers = nullptr;;
    }

}

// obtener instancia
GameRules &GameRules::getInstance(int sizePlayers)
{
    if (!instance)
    {
        if (sizePlayers < 1)
        {
            throw std::runtime_error("Tamaño invalido");
        }
        instance = new GameRules(sizePlayers);
    }
    return *instance;
}

// liberar memoria por puntero
void GameRules::deleteInstance()
{
    if (instance)
    {
        delete instance;
        instance = nullptr;
    }
}


// metodos del juego
Players *GameRules::getPlayersArray() const
{
    return arrayPlayers;
}

int GameRules::getTotalPlayers()
{
    return sizePlayers;
}


// getter and setter de row and column
int GameRules::getRow() const
{
    return row;
}

int GameRules::getColumn() const
{
    return column;
}

void GameRules::setRow(int row)
{
    this->row = row;
}

void GameRules::setColumn(int column)
{
    this->column = column;
}





