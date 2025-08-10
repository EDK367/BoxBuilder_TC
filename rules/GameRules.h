#ifndef GAMERULES_H
#define GAMERULES_H
#include "../models/players.h"

class GameRules
{
private:
    static GameRules *instance;

    // variables
    int sizePlayers = 0;
    Players *arrayPlayers = nullptr;
    int row = 0;
    int column = 0;
    // constructor
    GameRules(int sizePlayers);

public:

    // solo una instancia
    GameRules(const GameRules&) = delete;
    GameRules& operator = (const GameRules&) = delete;

    // obtencion de la instancia
    static GameRules& getInstance(int sizePlayers = 0);

    // eliminar instancia
    static void deleteInstance();

    // destructor
    ~GameRules();

    // metodos extras
    Players* getPlayersArray() const;
    int getTotalPlayers();

    // getter and setter
    int getRow() const;
    int getColumn() const;
    void setRow(int row);
    void setColumn(int column);
};

#endif // GAMERULES_H
