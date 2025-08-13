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
#include "methods/randomnative.h"
#include "methods/arraymess.h"
#include "mainwindow.h"

viewPlay::viewPlay(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::viewPlay)
    , random(2)
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

        Players *firstPlayer = gameRules.peekPlayer();
        if (firstPlayer)
        {
            std::cout << firstPlayer << std::endl;
            std::cout << firstPlayer->getLetter() << std::endl;
        }

        displayAllPlayers();
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
                QGraphicsRectItem  *boxPoint = new QGraphicsRectItem(
                    j * (nodeSize + connectorNodeSize + spacing) + nodeSize + 7,
                    i * (nodeSize + connectorNodeSize + spacing) + nodeSize + 5,
                    70,
                    70
                    );
                boxPoint->setPen(QPen(Qt::black, 2));
                boxPoint->setBrush(Qt::white);
                sceneBoard->addItem(boxPoint);
            }
        }
    }
}

// mostrar todos los jugadores en cola
void viewPlay::displayAllPlayers()
{
    NodoFIFO *current = gameRules.getFront();
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
    qDebug() << "Nodo clickeado en horizontal - Fila:" << row << "Columna:" << column;
    Players *player = gameRules.peekPlayer();
    if (player)
    {
        std::string color = player->getColor();
        pointerConnector->setColor(color);
        pointerConnector->updateColor();
    }
    gameRules.dequeuePlayer();

}

void viewPlay::linkConnectorVertical(ClickGraphics *pointerConnector, int row, int column)
{
    qDebug() << "Nodo clickeado en vertical - Fila:" << row << "Columna:" << column;
    Players *player = gameRules.peekPlayer();
    if (player)
    {
        std::string color = player->getColor();
        pointerConnector->setColor(color);
        pointerConnector->updateColor();
    }
    gameRules.dequeuePlayer();
}

void viewPlay::on_pushButton_clicked()
{

    NodoFIFO *current = gameRules.getFront();

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
    std::cout << result << std::endl;
}

