#include "viewplay.h"
#include "ui_viewplay.h"
#include <QMessageBox>
#include <iostream>
#include "rules/gameRules.h"
#include "mainwindow.h"

viewPlay::viewPlay(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::viewPlay)
    , gameRules(GameRules::getInstance())
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
        std::cout << "Jugadores" << std::endl;
        for (int i = 0; i < totalPlayers; ++i) {
            std::cout << players[i].getLetter() << std::endl;
        }

    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", "Error en la carga de las reglas de juego");
    }
}
