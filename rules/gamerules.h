#ifndef GAMERULES_H
#define GAMERULES_H
#include "../models/players.h"
#include "../methods/fifo.h"
#include "../models/nodelinked.h"
#include "../methods/nodevector.h"
#include "../models/node.h"
#include "../models/enum/powermanager.h"
#include "../models/controller/controllerBL.h"
#include "../methods/controller/controllerVector.h"

class GameRules
{
private:
    static GameRules *instance;

    // metodos
    FIFO playersQueue;
    NodeVector nodeVectors;
    // variables
    int sizePlayers = 0;
    Players *arrayPlayers = nullptr;
    // manejador de los podres
    PowerManager powersList;
    // control de los bloqueos que pueden existir
    ControllerVector<ControllerBL> controllerVector;
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

    // uso de los vectores de poder
    void pushVector(ControllerBL *controllerBL);
    void popVector(int index);
    int getSizeVector() const;
    ControllerBL *getVectorElement(int index) const;

    // nodos enlazados
    NodeLinked *addNodeLinked(Node* start, Node* end, PowerManager::PowerEnum power, Players *player);
    void deleteNodeLinked(int index);
    void sortByStart();

    NodeLinked *getNodeLinked(int index) const;
    int getSizeNodeLinked() const;

    // operaciones de poder
    PowerManager::PowerEnum getPower(int numberPower) const;

    // operacion de cola
    void enqueuePlayer(Players *player);
    void dequeuePlayer();
    Players *peekPlayer();
    NodeFIFO *getFront();

    // getter and setter
    int getRows() const;
    int getColumns() const;
    void setRows(int rows);
    void setColumns(int columns);
};

#endif // GAMERULES_H
