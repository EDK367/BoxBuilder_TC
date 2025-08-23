#include "gamerules.h"
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
        arrayPlayers = nullptr;
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

// uso de arreglo de enlace
NodeLinked *GameRules::addNodeLinked(Node *start, Node *end, PowerManager::PowerEnum power, Players *player)
{
    NodeLinked *newLink = new NodeLinked();
    newLink->setLinked(start, end, power, player);
    nodeVectors.push(newLink);
    return newLink;
}

void GameRules::deleteNodeLinked(int index)
{
    nodeVectors.pop(index);
}

void GameRules::sortByStart()
{
    nodeVectors.sortByStart();
}

// uso del vector para el Bloqueo
void GameRules::pushVector(ControllerBL *controllerBL)
{
    controllerVector.push(controllerBL);
}

void GameRules::popVector(int index)
{
    controllerVector.pop(index);
}

int GameRules::getSizeVector() const
{
    return controllerVector.getSize();
}

ControllerBL *GameRules::getVectorElement(int index) const
{
    return controllerVector.getElement(index);
}

// uso del vector para pintar los podres
void GameRules::pushViewPower(PowerController *powerController)
{
    controllerPower.push(powerController);
}

void GameRules::popViewPower(int index)
{
    controllerPower.pop(index);
}

int GameRules::getSizeViewPower() const
{
    return controllerPower.getSize();
}

PowerController *GameRules::getElementPower(int index) const
{
    return controllerPower.getElement(index);
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

// poderes
PowerManager::PowerEnum GameRules::getPower(int numberPower) const
{
    return powersList.getPowerEnum(numberPower);
}


// implementacion de la cola para turnos
void GameRules::enqueuePlayer(Players *player)
{
    playersQueue.enqueue(player);
}

void GameRules::dequeuePlayer()
{
    playersQueue.dequeue();
}

Players *GameRules::peekPlayer()
{
    Players *temp = playersQueue.peak();
    if (temp)
    {
        return temp;
    }
    return nullptr;
}

NodeFIFO *GameRules::getFront()
{
    return playersQueue.getFront();
}

// getter y setter de nodeLinked
NodeLinked *GameRules::getNodeLinked(int index) const
{
    return nodeVectors.getNode(index);
}

int GameRules::getSizeNodeLinked() const
{
    return nodeVectors.getSize();
}
// getter and setter de rows and columns
int GameRules::getRows() const
{
    return rows;
}

int GameRules::getColumns() const
{
    return columns;
}

void GameRules::setRows(int rows)
{
    this->rows = rows;
}

void GameRules::setColumns(int columns)
{
    this->columns = columns;
}





