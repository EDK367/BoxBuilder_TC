#include "viewplay.h"
#include "ui_viewplay.h"
#include <QMessageBox>
#include <iostream>
#include "rules/gameRules.h"
#include "models/nodeboard.h"
#include "mainwindow.h"

viewPlay::viewPlay(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::viewPlay)
    , gameRules(GameRules::getInstance())
    , rows(3)
    , columns(3)
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

        std::cout << this->rows << " " << this->columns << std::endl;
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", "Error en la carga de las reglas de juego");
    }
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

