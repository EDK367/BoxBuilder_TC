#ifndef GAMERULES_H
#define GAMERULES_H
#include "../models/players.h"
#include "../methods/fifo.h"

class GameRules
{
private:
    static GameRules *instance;
    FIFO playersQueue;

    // variables
    int sizePlayers = 0;
    Players *arrayPlayers = nullptr;
    int rows = 0;
    int columns = 0;

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

    // operacion de cola
    void enqueuePlayer(Players *player);
    void dequeuePlayer();
    Players *peekPlayer();
    NodoFIFO *getFront();

    // getter and setter
    int getRows() const;
    int getColumns() const;
    void setRows(int rows);
    void setColumns(int columns);
};

#endif // GAMERULES_H
