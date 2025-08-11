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
#include "mainwindow.h"

viewPlay::viewPlay(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::viewPlay)
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

    MainWindow *mainW = new MainWindow();
    mainW->show();
    event->accept();
}

void viewPlay::chargeGameRules()
{
    try {

        Players  *players = gameRules.getPlayersArray();
        int totalPlayers = gameRules.getTotalPlayers();
        this->rows = gameRules.getRow();
        this->columns = gameRules.getColumn();
        std::cout << "Jugadores" << std::endl;
        for (int i = 0; i < totalPlayers; ++i) {
            std::cout << players[i].getLetter() << std::endl;
        }
        board = NodeBoard::createBoard(rows, columns);


        chargeBoard();

        std::cout << this->rows << " " << this->columns << std::endl;
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

            if (i < rows - 1)
            {
                ClickGraphics *verticalConnector = new ClickGraphics(
                    i, j,
                    j * (nodeSize + connectorNodeSize + spacing) + nodeSize / 2 - connectorNodeSize / 2,
                    i * (nodeSize + connectorNodeSize + spacing) + nodeSize,
                    10, 80
                    );
                verticalConnector->setBrush(Qt::blue);
                sceneBoard->addItem(verticalConnector);
                connect(verticalConnector, &ClickGraphics::clickNode, this, &viewPlay::linkNodeConnector);
            }

            if (j < columns - 1)
            {
                ClickGraphics *horizontalConnector = new ClickGraphics(
                    i, j,
                    j * (nodeSize + connectorNodeSize + spacing) + nodeSize,
                    i * (nodeSize + connectorNodeSize + spacing) + nodeSize / 2 - connectorNodeSize / 2,
                    80,
                    10
                    );
                horizontalConnector->setBrush(Qt::gray);
                sceneBoard->addItem(horizontalConnector);
                connect(horizontalConnector, &ClickGraphics::clickNode, this, &viewPlay::linkNodeConnector);
            }

            if (i < rows - 1 && j < columns - 1)
            {
                QGraphicsRectItem  *boxPoint = new QGraphicsRectItem(
                    j * (nodeSize + connectorNodeSize + spacing) + nodeSize + 2,
                    i * (nodeSize + connectorNodeSize + spacing) + nodeSize,
                    70,
                    70
                    );
                boxPoint->setBrush(Qt::darkGreen);
                sceneBoard->addItem(boxPoint);
            }
        }
    }
}

void viewPlay::linkNodeConnector(int row, int column)
{
    qDebug() << "Nodo clickeado - Fila:" << row << "Columna:" << column;
}

void viewPlay::on_pushButton_clicked()
{
    std::cout << "Entra" << std::endl;
    try
    {
        NodeBoard ***board = NodeBoard::createBoard(rows, columns);
        // test
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                std::cout << ". ";
            }
            std::cout << std::endl;
        }


        NodeBoard* node = board[2][2];
        if(!node) {
            std::cout << "Nodo nullptr" << std::endl;
            return;
        }

        std::cout << "Nodo actual: (" << node->getX() << ", " << node->getY() << ")\n";

        if(node->getUp()) {
            std::cout << "Arriba: (" << node->getUp()->getX() << ", "
                      << node->getUp()->getY() << ")\n";
        }

        if(node->getDown()) {
            std::cout << "Abajo: (" << node->getDown()->getX() << ", "
                      << node->getDown()->getY() << ")\n";
        }

        if(node->getLeft()) {
            std::cout << "Izquierda: (" << node->getLeft()->getX() << ", "
                      << node->getLeft()->getY() << ")\n";
        }

        if(node->getRight()) {
            std::cout << "Derecha: (" << node->getRight()->getX() << ", "
                      << node->getRight()->getY() << ")\n";
        }

        NodeBoard::deleteBoard(board, rows, columns);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", "Error en el tablero");
    }
}

