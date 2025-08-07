#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QIntValidator>
#include <QString>
#include <QMessageBox>
#include "utils/minBoardSize.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    minRow(3),
    minColumn(3),
    rowAcept(false),
    columnAcept(false)
{
    ui->setupUi(this);

    int maxNumber = std::numeric_limits<int>::max();

    ui->playersB->setEnabled(false);

    // cambio de opt en widgets
    connect(ui->playB, &QPushButton::clicked, this, [=]() {
        ui->panelW->setCurrentWidget(ui->playW);
    });


    // validadores
    // jugadores
    ui->playersSize->setValidator(new QIntValidator(2, maxNumber));
    connect(ui->playersSize, &QLineEdit::textChanged, this, [this](const QString &text) {
        int players = text.toInt();
        minBoard(players, minRow, minColumn);
        ui->playersB->setEnabled(false);
        rowAcept = false;
        columnAcept = false;
        if (!text.isEmpty() && minRow != 2) {
            ui->boardSize->setText("Minimo de: " + QString::number(minRow) + " x " + QString::number(minColumn));
        } else {
            ui->boardSize->setText("");
        }
    });


    // filas
    ui->rowSize->setValidator(new QIntValidator(minRow, maxNumber));
    connect(ui->rowSize, &QLineEdit::textChanged, this, [this](const QString &text) {
        rowAcept = validationBoard(text.toInt(), minRow);
        if (rowAcept && columnAcept) {
            ui->playersB->setEnabled(true);
        } else {
            ui->playersB->setEnabled(false);
        }
    });

    // columnas
    ui->columnSize->setValidator(new QIntValidator(minColumn, maxNumber));
    connect(ui->columnSize, &QLineEdit::textChanged, this, [this](const QString &text) {
        columnAcept = validationBoard(text.toInt(), minColumn);
        if (rowAcept && columnAcept) {
            ui->playersB->setEnabled(true);
        } else {
            ui->playersB->setEnabled(false);
        }
    });

    // boton y validaciones extras

}


MainWindow::~MainWindow()
{
    delete ui;
}
