#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QIntValidator>
#include <QString>
#include <QDialog>
#include <QColorDialog>
#include <QPushButton>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QLabel>
#include <QLayoutItem>
#include <QMessageBox>
#include "utils/minBoardSize.h"
#include "models/players.h"
#include "rules/gamerules.h"
#include "viewplay.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    minRow(3),
    minColumn(3),
    rowAcept(false),
    columnAcept(false),
    numberPlayers(2)
{
    ui->setupUi(this);
    int maxNumber = std::numeric_limits<int>::max();

    ui->boardSize->setText("Faltan dos jugadores");

    // configuracion de tabla
    ui->tableWidget->setColumnCount(3);
    QStringList header;
    header << "Letra" << "Color" << "Opcion";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    // cambio de opt en widgets
    connect(ui->playB, &QPushButton::clicked, this, [=]() {
        ui->panelW->setCurrentWidget(ui->playW);
    });


    // validadores
    // jugadores
    ui->play->setEnabled(false);
    minBoard(2, minRow, minColumn);

    // filas
    ui->rowSize->setValidator(new QIntValidator(minRow, maxNumber));
    connect(ui->rowSize, &QLineEdit::textChanged, this, [this](const QString &text) {
        rowAcept = validationBoard(text.toInt(), minRow);
        int count = ui->tableWidget->rowCount();
        if (rowAcept && columnAcept && count > 1)
        {
            ui->play->setEnabled(true);
        } else {
            ui->play->setEnabled(false);
        }
    });

    // columnas
    ui->columnSize->setValidator(new QIntValidator(minColumn, maxNumber));
    connect(ui->columnSize, &QLineEdit::textChanged, this, [this](const QString &text) {
        columnAcept = validationBoard(text.toInt(), minColumn);
        int count = ui->tableWidget->rowCount();
        if (rowAcept && columnAcept && count > 1)
        {
            ui->play->setEnabled(true);
        } else {
            ui->play->setEnabled(false);
        }
    });
}


MainWindow::~MainWindow()
{
    delete ui;
}

// crear las reglas del juego
void MainWindow::on_play_clicked()
{
    int totalPlayers = ui->tableWidget->rowCount();
    QString rowValue = ui->rowSize->text();
    QString columnValue = ui->columnSize->text();
    bool okRow, okColumn;

    int row = rowValue.toInt(&okRow);
    int column = columnValue.toInt(&okColumn);

    if (!okRow || !validationBoard(row, minRow))
    {
        QMessageBox::warning(this, "Error", "El tamaño de fila no es valido ");
        return;
    }

    if (!okColumn || !validationBoard(column, minColumn))
    {
        QMessageBox::warning(this, "Error", "El tamaño de columna no es valido ");
        return;
    }

    GameRules &gameRules = GameRules::getInstance(totalPlayers);
    Players *players = gameRules.getPlayersArray();

    for (int i = 0; i < totalPlayers; ++i)
    {
        QString letter = ui->tableWidget->item(i, 0)->text();
        QString color = ui->tableWidget->item(i, 1)->text();
        std::string colorHex = color.toStdString();
        char charLetter = letter.at(0).toLatin1();

        players[i] = Players(charLetter, colorHex);
    }
    gameRules.setRows(row);
    gameRules.setColumns(column);

    // ventana del juego
    viewPlay *gameWindow = new viewPlay(this);
    gameWindow->setWindowFlags(Qt::Window);
    gameWindow->setAttribute(Qt::WA_DeleteOnClose);
    gameWindow->show();

    this->hide();

}

void MainWindow::on_playersB_clicked()
{
    // creacion del popup
    QDialog dialog(this);
    dialog.setWindowTitle("Agregar nuevo jugador");

    QVBoxLayout *layout = new QVBoxLayout(&dialog);

    QLabel *labelLetter = new QLabel("Letra del jugador:", &dialog);
    QLineEdit *lineLetter = new QLineEdit(&dialog);

    QLabel *labelColor = new QLabel("Seleccione el color del jugador:", &dialog);
    QPushButton *buttonColor = new QPushButton("Color");

    // se agrega el form al popup
    layout->addWidget(labelLetter);
    layout->addWidget(lineLetter);
    layout->addWidget(labelColor);
    layout->addWidget(buttonColor);

    // validacion de la letra
    QRegularExpression regex("^[A-Za-z0-9]$");
    QValidator *validator = new QRegularExpressionValidator(regex, this);
    lineLetter->setValidator(validator);

    // dialogo de acpetar o rechazhar
    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &dialog);
    layout->addWidget(buttonBox);

    connect(buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    QColor selectedColor;

    // selecion del color
    connect(buttonColor, &QPushButton::clicked, this, [&](){
        QColor color = QColorDialog::getColor(Qt::white, this, tr("Selecciona un color"));
        if (color.isValid())
        {
            selectedColor = color;
            buttonColor->setStyleSheet("background-color: " + color.name() + ";");
        }
    });

    // ejecutar y aceptar el valor
    if (dialog.exec() == QDialog::Accepted)
    {
        QString letter = lineLetter->text();
        QString colorHex = selectedColor.name();

        // validaciones
        if (letter.isEmpty() || !selectedColor.isValid())
        {
            QMessageBox::warning(this, "Error", "No se ingreso el jugador, Faltan Datos");
            return;
        }

        if (isDuplicate(letter, colorHex))
        {
            QMessageBox::warning(this, "Error", "La letra o el color ya esta en uso.");
            return;
        }

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(letter));

        QTableWidgetItem *colorItem = new QTableWidgetItem(colorHex);
        colorItem->setBackground(QBrush(selectedColor));
        ui->tableWidget->setItem(row, 1, colorItem);

        QPushButton *deleteBtn = new QPushButton("Eliminar");
        ui->tableWidget->setCellWidget(row, 2, deleteBtn);

        connect(deleteBtn, &QPushButton::clicked, this, [this]() {

            QPushButton* btn = qobject_cast<QPushButton*>(sender());
            if (!btn) return;

            int index = -1;
            for (int i = 0; i < ui->tableWidget->rowCount(); ++i)
            {
                if (ui->tableWidget->cellWidget(i, 2) == btn)
                {
                    index = i;
                    break;
                }
            }

            // aca elimina
            if (index != -1)
            {
                ui->tableWidget->removeRow(index);
                updateBoardRequirements();
            }
        });

        // validacion del tablero
        updateBoardRequirements();
    }

}

bool MainWindow::isDuplicate(const QString& letterNew, const QString& colorNew)
{
    int rows = ui->tableWidget->rowCount();
    for (int i = 0; i < rows; ++i)
    {
        QString letter = ui->tableWidget->item(i, 0)->text();
        QString color = ui->tableWidget->item(i, 1)->text();

        if (letter.compare(letterNew, Qt::CaseSensitive) == 0
            || color.compare(colorNew, Qt::CaseSensitive) == 0)
        {
            return true;
        }
    }
    return false;
}

void MainWindow::updateBoardRequirements()
{

    numberPlayers = ui->tableWidget->rowCount();
    if (numberPlayers < 2)
    {
        ui->play->setEnabled(false);
        ui->boardSize->setText("Falta al menos un jugador");
    } else {
        ui->play->setEnabled(rowAcept && columnAcept);
        minBoard(numberPlayers, minRow, minColumn);
        ui->boardSize->setText(
            QString("Min: %1 filas, %2 columnas").arg(minRow).arg(minColumn)
            );
    }
}


/*
ESTE METODO ES TEMPORAL, SE HIZO SOLO PARA
PODER HACER TEST RAPIDOS SIN ESTAR INGRESANDO
DATOS.
SE ELIMINARA EN UN FUTURO
att: EDK367
*/
void MainWindow::on_pushButton_clicked()
{
    // Jugador A
    {
        QString letter = "A";
        QColor color = Qt::white;
        QString colorHex = color.name();

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(letter));

        QTableWidgetItem *colorItem = new QTableWidgetItem(colorHex);
        colorItem->setBackground(QBrush(color));
        ui->tableWidget->setItem(row, 1, colorItem);

        QPushButton *deleteBtn = new QPushButton("Eliminar");
        ui->tableWidget->setCellWidget(row, 2, deleteBtn);

        connect(deleteBtn, &QPushButton::clicked, this, [this]() {
            QPushButton* btn = qobject_cast<QPushButton*>(sender());
            if (!btn) return;

            int index = -1;
            for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
                if (ui->tableWidget->cellWidget(i, 2) == btn) {
                    index = i;
                    break;
                }
            }

            if (index != -1) {
                ui->tableWidget->removeRow(index);
                updateBoardRequirements();
            }
        });
    }

    // Jugador B
    {
        QString letter = "B";
        QColor color = Qt::black;
        QString colorHex = color.name();

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(letter));

        QTableWidgetItem *colorItem = new QTableWidgetItem(colorHex);
        colorItem->setBackground(QBrush(color));
        ui->tableWidget->setItem(row, 1, colorItem);

        QPushButton *deleteBtn = new QPushButton("Eliminar");
        ui->tableWidget->setCellWidget(row, 2, deleteBtn);

        connect(deleteBtn, &QPushButton::clicked, this, [this]() {
            QPushButton* btn = qobject_cast<QPushButton*>(sender());
            if (!btn) return;

            int index = -1;
            for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
                if (ui->tableWidget->cellWidget(i, 2) == btn) {
                    index = i;
                    break;
                }
            }

            if (index != -1) {
                ui->tableWidget->removeRow(index);
                updateBoardRequirements();
            }
        });
    }

    // Jugador C
    {
        QString letter = "C";
        QColor color = Qt::red;  // Color rojo
        QString colorHex = color.name();

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(letter));

        QTableWidgetItem *colorItem = new QTableWidgetItem(colorHex);
        colorItem->setBackground(QBrush(color));
        ui->tableWidget->setItem(row, 1, colorItem);

        QPushButton *deleteBtn = new QPushButton("Eliminar");
        ui->tableWidget->setCellWidget(row, 2, deleteBtn);

        connect(deleteBtn, &QPushButton::clicked, this, [this]() {
            QPushButton* btn = qobject_cast<QPushButton*>(sender());
            if (!btn) return;

            int index = -1;
            for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
                if (ui->tableWidget->cellWidget(i, 2) == btn) {
                    index = i;
                    break;
                }
            }

            if (index != -1) {
                ui->tableWidget->removeRow(index);
                updateBoardRequirements();
            }
        });
    }

    // Jugador D
    {
        QString letter = "D";
        QColor color = Qt::blue;  // Color azul
        QString colorHex = color.name();

        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(letter));

        QTableWidgetItem *colorItem = new QTableWidgetItem(colorHex);
        colorItem->setBackground(QBrush(color));
        ui->tableWidget->setItem(row, 1, colorItem);

        QPushButton *deleteBtn = new QPushButton("Eliminar");
        ui->tableWidget->setCellWidget(row, 2, deleteBtn);

        connect(deleteBtn, &QPushButton::clicked, this, [this]() {
            QPushButton* btn = qobject_cast<QPushButton*>(sender());
            if (!btn) return;

            int index = -1;
            for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
                if (ui->tableWidget->cellWidget(i, 2) == btn) {
                    index = i;
                    break;
                }
            }

            if (index != -1) {
                ui->tableWidget->removeRow(index);
                updateBoardRequirements();
            }
        });
    }

    updateBoardRequirements();

    ui->rowSize->setText("5");
    ui->columnSize->setText("5");
}

