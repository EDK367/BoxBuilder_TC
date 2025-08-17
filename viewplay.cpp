#include "viewplay.h"
#include "ui_viewplay.h"
#include <QMessageBox>
#include <QLabel>
#include <QGridLayout>
#include <QRadioButton>
#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "rules/gameRules.h"
#include "models/nodeboard.h"
#include "utils/clickgraphics.h"
#include "utils/boxgraphics.h"
#include "methods/randomnative.h"
#include "methods/probability.h"
#include "methods/arraymess.h"
#include "mainwindow.h"

viewPlay::viewPlay(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::viewPlay)
    , random(2)
    , probability()
    , gameRules(GameRules::getInstance())
    , rows(3)
    , columns(3)
    , board(nullptr)
{
    ui->setupUi(this);
}

viewPlay::~viewPlay()
{
    delete ui;
}

// evento para inicio
void viewPlay::showEvent(QShowEvent *event)
{
    QFrame::showEvent(event);
    chargeGameRules();
}
// regresar a la ventana principal
void viewPlay::closeEvent(QCloseEvent *event) {
    gameRules.deleteInstance();
    MainWindow *mainW = new MainWindow();
    mainW->show();
    event->accept();
}

void viewPlay::chargeGameRules()
{
    ArrayMess arrayMess;
    try {

        Players  *players = gameRules.getPlayersArray();
        int totalPlayers = gameRules.getTotalPlayers();
        arrayMess.shufflePlayers(players, totalPlayers);
        this->rows = gameRules.getRows();
        this->columns = gameRules.getColumns();
        std::cout << "Jugadores" << std::endl;

        for (int i = 0; i < totalPlayers; ++i)
        {
            gameRules.enqueuePlayer(&players[i]);
        }


        //displayAllPlayers();
        board = NodeBoard::createBoard(rows, columns);
        chargeBoard();

    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", "Error en la carga de las reglas de juego");
    }
}

// carga del tablero en la parte visual
void viewPlay::chargeBoard()
{
    QGraphicsScene *sceneBoard = new QGraphicsScene(this);
    QGraphicsView *viewBoard = new QGraphicsView(sceneBoard);
    ui->scrollBoard->setWidget(viewBoard);

    const int nodeSize = 40;
    const int connectorNodeSize = 10;
    const int spacing = 75;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            QGraphicsRectItem  *nodePointer = new QGraphicsRectItem (
                j * (nodeSize + connectorNodeSize + spacing),
                i * (nodeSize + connectorNodeSize + spacing),
                nodeSize, nodeSize
                );

            nodePointer->setBrush(Qt::black);
            nodePointer->setPen(QPen(Qt::cyan, 2));
            sceneBoard->addItem(nodePointer);

            // conexion de nodo en vertical
            if (i < rows - 1)
            {
                ClickGraphics *verticalConnector = new ClickGraphics(
                    i, j,
                    j * (nodeSize + connectorNodeSize + spacing) + nodeSize / 2 - connectorNodeSize / 2,
                    i * (nodeSize + connectorNodeSize + spacing) + nodeSize,
                    15, 82
                    );
                verticalConnector->setBrush(Qt::lightGray);
                sceneBoard->addItem(verticalConnector);
                connect(verticalConnector, &ClickGraphics::clickNode, this, &viewPlay::linkConnectorVertical);
            }

            // conexiones de nodo en horizontal
            if (j < columns - 1)
            {
                ClickGraphics *horizontalConnector = new ClickGraphics(
                    i, j,
                    j * (nodeSize + connectorNodeSize + spacing) + nodeSize + 1,
                    i * (nodeSize + connectorNodeSize + spacing) + nodeSize / 2 - connectorNodeSize / 2,
                    82, 15
                    );
                horizontalConnector->setBrush(Qt::lightGray);
                sceneBoard->addItem(horizontalConnector);
                connect(horizontalConnector, &ClickGraphics::clickNode, this, &viewPlay::linkConnectorHorizontal);
            }

            // nodo donde se almacenara los poderes
            if (i < rows - 1 && j < columns - 1)
            {
                BoxGraphics  *boxPoint = new BoxGraphics(
                    j * (nodeSize + connectorNodeSize + spacing) + nodeSize + 7,
                    i * (nodeSize + connectorNodeSize + spacing) + nodeSize + 5,
                    70,
                    70
                    );

                if (probability.powerChance())
                {
                    random.setLimit(10);
                    unsigned int numberPower = random();
                    PowerManager::PowerEnum *power = gameRules.getPower(numberPower);
                    if (power != nullptr) {
                        std::string powerStr = PowerManager::getPowerString(*power);
                        boxPoint->insertPower(powerStr);
                        board[i][j]->getInfo()->setPower(power);
                    }
                }
                sceneBoard->addItem(boxPoint);
                board[i][j]->getInfo()->setSquare(boxPoint);
            }
        }
    }
}

// mostrar todos los jugadores en cola
void viewPlay::displayAllPlayers()
{
    NodeFIFO *current = gameRules.getFront();
    while (current)
    {
        Players *player = current->getPlayer();
        if (player)
        {
            std::cout << player->getLetter() << std::endl;
        }
        current = current->getNext();
    }
}

void viewPlay::linkConnectorHorizontal(ClickGraphics *pointerConnector, int row, int column)
{
    //qDebug() << "Nodo clickeado en horizontal - Fila:" << row << "Columna:" << column;
    Players *player = gameRules.peekPlayer();
    if (player)
    {
        std::string color = player->getColor();
        pointerConnector->setColor(color);
        pointerConnector->updateColor();

        // creacion de enlaces
        NodeBoard *nodeS = board[row][column];
        Node *nodeStart = nodeS;
        NodeBoard* nodeE = board[row][column + 1];
        Node *nodeEnd = nodeE;

        gameRules.addNodeLinked(nodeStart, nodeEnd, true);

        nodeS->getInfo()->setIsConnectedRight(true);
        nodeE->getInfo()->setIsConnectedLeft(true);
        if (verifyBoxCompletion())
        {
            return;
        }
    }
    gameRules.dequeuePlayer(); 
}

void viewPlay::linkConnectorVertical(ClickGraphics *pointerConnector, int row, int column)
{
    //qDebug() << "Nodo clickeado en vertical - Fila:" << row << "Columna:" << column;
    Players *player = gameRules.peekPlayer();
    if (player)
    {
        std::string color = player->getColor();
        pointerConnector->setColor(color);
        pointerConnector->updateColor();

        // creacion de enlaces
        NodeBoard *nodeS = board[row][column];
        Node *nodeStart = nodeS;
        NodeBoard* nodeF = board[row + 1][column];
        Node *nodeEnd = nodeF;

        gameRules.addNodeLinked(nodeStart, nodeEnd, true);
        nodeS->getInfo()->setIsConnectedDown(true);
        nodeF->getInfo()->setIsConnectedUp(true);

        if (verifyBoxCompletion())
        {
            return;
        }
    }
    gameRules.dequeuePlayer();
}

// verificacion si se obtuvo un win en un enlace
bool viewPlay::verifyBoxCompletion()
{
    gameRules.sortByStart();
    int nodeDelete[4] = {-1, -1, -1, -1};
    int deleteCount = 0;
    Node *lastFoundNode = nullptr;

    for (int i = 0; i < gameRules.getSizeNodeLinked(); ++i)
    {
        // validaciones
        NodeLinked *links = gameRules.getNodeLinked(i);
        if (!links) {
            nodeDelete[deleteCount++] = i;
            continue;
        }
        Node *startLinked = links->getStartLinked();
        if (!startLinked) {
            nodeDelete[deleteCount++] = i;
            continue;
        }

        // validacion del ultimo nodo si es igual al anterior
        if (lastFoundNode &&
            lastFoundNode->getX() == startLinked->getX() &&
            lastFoundNode->getY() == startLinked->getY())
        {
            nodeDelete[deleteCount++] = i;
            continue;
        }

        // creacion de nodos para los enlaces
        NodeBoard *nodeStart = board[startLinked->getX()][startLinked->getY()];
        NodeBoard *nodeFinal = nullptr;
        // si no es mayor a su fila
        if (!(startLinked->getX() + 1 > this->rows - 1)) {
            nodeFinal = board[startLinked->getX() + 1][startLinked->getY() + 1];
        }

        if (nodeFinal && nodeStart->isConnectedRightAndDown() && nodeFinal->isConnectedLeftAndUp())
        {
            nodeDelete[deleteCount++] = i;
            lastFoundNode = startLinked;

            BoxGraphics *boxWin = nodeStart->getInfo()->getSquare();
            boxWin->insertPlayer(gameRules.peekPlayer()->getLetter(), gameRules.peekPlayer()->getColor());

            // poderes
            if (nodeStart->getInfo()->getPower())
            {
                Players *player = gameRules.peekPlayer();
                if (player)
                {
                    PowerManager::PowerEnum *power = nodeStart->getInfo()->getPower();
                    player->addPower(power);
                }
            }

            if (deleteCount >= 4)
            {
                break;
            }
        }
    }

    for (int i = deleteCount - 1; i >= 0; i--)
    {
        if (nodeDelete[i] != -1)
            gameRules.deleteNodeLinked(nodeDelete[i]);
    }

    return deleteCount > 0;

}

void viewPlay::on_pushButton_clicked()
{

   /*NodeFIFO *current = gameRules.getFront();

    while (current)
    {
        Players *player = current->getPlayer();
        if (player)
        {
             std::cout << player->getLetter() << std::endl;
        }
        current = current->getNext();
    }

    random.setLimit(11);
    unsigned int result = random();
    //std::cout << result << std::endl;


    // vista de nodods enlazados
    for (int i = 0; i < gameRules.getSizeNodeLinked(); ++i) {
        NodeLinked* link = gameRules.getNodeLinked(i);
        if (link) {
            Node* start = link->getStartLinked();
            Node* end = link->getEndLinked();
            bool power = link->getPower();

            qDebug() << "Conexion";
            qDebug() << "  Desde: (" << start->getX() << "," << start->getY() << ")";
            qDebug() << "  Hasta: (" << end->getX() << "," << end->getY() << ")";
            qDebug() << "  indice: " << i;
        }
    }*/

    //NodeLinked *link = gameRules.getNodeLinked(0);
    //Node* start = link->getStartLinked();
    //Node* end = link->getEndLinked();
    //bool power = link->getPower();

    //NodeBoard *node = board[start->getX()][end->getY()];

}

