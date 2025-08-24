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
#include "powers/fourthclass.h"
#include "models/nodeinfo.h"
#include "methods/controller/controllerVector.h"
#include "mainwindow.h"

viewPlay::viewPlay(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::viewPlay)
    , random(2)
    , probability()
    , gameRules(GameRules::getInstance())
    , rows(3)
    , columns(3)
    , isBlockade(false)
    , board(nullptr)
    , sortPlayersByPoints()
    , applyFirstPower()
    , classD()
    , classC()
    , classB()
    , classA()
{
    ui->setupUi(this);

    // llamada de clases auxiliares a poderes

    // creacion de la tabla
    ui->tablePlayers->setColumnCount(4);
    QStringList header;
    header << "Letra" << "Color" << "Puntos" <<  "Primer Poder";
    ui->tablePlayers->resizeColumnsToContents();

    ui->tablePlayers->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tablePlayers->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    ui->tablePlayers->setHorizontalHeaderLabels(header);
    ui->tablePlayers->horizontalHeader()->setStretchLastSection(true);
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

// funcion para cargar las reglas de juego
void viewPlay::chargeGameRules()
{
    ArrayMess arrayMess;
    try {

        // carga de los jugadores
        Players  *players = gameRules.getPlayersArray();
        int totalPlayers = gameRules.getTotalPlayers();
        arrayMess.shufflePlayers(players, totalPlayers);
        this->rows = gameRules.getRows();
        this->columns = gameRules.getColumns();
        for (int i = 0; i < totalPlayers; ++i)
        {
            gameRules.enqueuePlayer(&players[i]);
        }

        // enlaces total para que el juego termine
        int totalLinkeds = this->rows * (this->columns - 1) + (this->rows - 1) * this->columns;
        gameRules.setTotalLinked(totalLinkeds);

        // carga de jugadores y creacion del tablero
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
                    15, 85
                    );

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
                    85, 15
                    );

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
                    PowerManager::PowerEnum power = gameRules.getPower(numberPower); // aca se usa el poder akeatoriuo ahora esta en 0 para test
                    if (power != PowerManager::PowerEnum::NONE) {
                        std::string powerStr = PowerManager::getPowerString(power);
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
    // eliminar el puntero del poder al recargar jugadores
    this->applyFirstPower = PowerManager::PowerEnum::NONE;
    ui->tablePlayers->clearContents();
    ui->tablePlayers->setRowCount(0);
    NodeFIFO *currentFifo = gameRules.getFront();
    int row = 0;

    while (currentFifo)
    {
        Players *player = currentFifo->getPlayer();
        if (player)
        {
            PowerManager::PowerEnum power = player->getPowerStack().peek();
            // agregar para fila
            ui->tablePlayers->insertRow(row);
            QString color = QString::fromStdString(player->getColor());

            // ingreso de datos
            // letra
            ui->tablePlayers->setItem(row, 0, new QTableWidgetItem(QString(player->getLetter())));

            // color
            QTableWidgetItem *colorItem = new QTableWidgetItem(color);
            colorItem->setBackground(QBrush(QColor(color)));
            ui->tablePlayers->setItem(row, 1, colorItem);

            ui->tablePlayers->setItem(row, 2, new QTableWidgetItem(QString::number(player->getPoints())));

            if (power != PowerManager::PowerEnum::NONE)
            {
                std::string powerName = PowerManager::getPowerString(power);
                ui->tablePlayers->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(powerName)));
            }
            row++;
        }
        currentFifo = currentFifo->getNext();
    }
    if (finishGame())
    {
        QMessageBox::information(
            this,
            "Partida Finalizada",
            "Se ha terminado la partida"
            );
    }
}

// enlaces de nodos
// enlace horizontal
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

        NodeLinked *nodeLink = gameRules.addNodeLinked(nodeStart, nodeEnd, this->applyFirstPower, player);

        // enlazar con el vector de poder de dibujo
        PowerController *powerController = PowerController::createController(
            this->applyFirstPower,
            player,
            pointerConnector
            );
        gameRules.pushViewPower(powerController);


        if (this->applyFirstPower == PowerManager::PowerEnum::BL)
        {
            ControllerBL *controller = new ControllerBL;;
            controller->setNodeLinkedController(nodeLink);
            controller->setCount(gameRules.getTotalPlayers());

            gameRules.pushVector(controller);
        }

        nodeS->getInfo()->setIsConnectedRight(true);
        nodeS->getInfo()->setLinkRight(nodeLink);

        nodeE->getInfo()->setIsConnectedLeft(true);
        nodeE->getInfo()->setLinkLeft(nodeLink);

        if (verifyBoxCompletion())
        {
            if (this->isBlockade)
            {
                nodeS->getInfo()->setIsConnectedRight(false);
                nodeS->getInfo()->setLinkRight(nullptr);

                nodeE->getInfo()->setIsConnectedLeft(false);
                nodeE->getInfo()->setLinkLeft(nullptr);

                gameRules.deleteNodeLinked(gameRules.getSizeNodeLinked() - 1);
                gameRules.popViewPower(gameRules.getSizeViewPower() - 1);
                pointerConnector->resetClick();
                this->isBlockade = false;
                displayAllPlayers();
                return;
            }
            displayAllPlayers();
            return;
        }
    }
    gameRules.dequeuePlayer();
    displayAllPlayers();

}

// enlace vertical
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
        NodeBoard* nodeE = board[row + 1][column];
        Node *nodeEnd = nodeE;

        NodeLinked *nodeLink = gameRules.addNodeLinked(nodeStart, nodeEnd, this->applyFirstPower, player);

        // enlazar con el vector de poder de dibujo
        PowerController *powerController = PowerController::createController(
            this->applyFirstPower,
            player,
            pointerConnector
            );
        gameRules.pushViewPower(powerController);

        if (this->applyFirstPower == PowerManager::PowerEnum::BL)
        {
            ControllerBL *controller = new ControllerBL;;
            controller->setNodeLinkedController(nodeLink);
            controller->setCount(gameRules.getTotalPlayers());

            gameRules.pushVector(controller);
        }

        nodeS->getInfo()->setIsConnectedDown(true);
        nodeS->getInfo()->setLinkDown(nodeLink);

        nodeE->getInfo()->setIsConnectedUp(true);
        nodeE->getInfo()->setLinkUp(nodeLink);

        if (verifyBoxCompletion())
        {
            if (this->isBlockade)
            {
                nodeS->getInfo()->setIsConnectedDown(false);
                nodeS->getInfo()->setLinkDown(nullptr);

                nodeE->getInfo()->setIsConnectedUp(false);
                nodeE->getInfo()->setLinkUp(nullptr);

                gameRules.deleteNodeLinked(gameRules.getSizeNodeLinked() - 1);
                gameRules.popViewPower(gameRules.getSizeViewPower() - 1);
                pointerConnector->resetClick();
                this->isBlockade = false;
                displayAllPlayers();
                return;
            }
            displayAllPlayers();
            return;
        }
    }
    gameRules.dequeuePlayer();
    displayAllPlayers();
}

// verificar si ya se termino el juego
bool viewPlay::finishGame()
{
    int totalPossibleLinks = gameRules.getTotalLinked();
    int currentLinksCreated = gameRules.getSizeViewPower();
    Players *playersArray = gameRules.getPlayersArray();
    int totalPlayers = gameRules.getTotalPlayers();

    std::cout << "Enlaces posibles: " << totalPossibleLinks << std::endl;
    std::cout << "Enlaces creados: " << currentLinksCreated << std::endl;

    if (currentLinksCreated >= totalPossibleLinks) {
        sortPlayersByPoints.mergeSortPlayers(playersArray, 0, totalPlayers - 1);

        ui->winLabel->setText(QString("El ganador fue: %1 con %2 puntos")
                                  .arg(QChar(playersArray[0].getLetter()))
                                  .arg(playersArray[0].getPoints()));
        ui->winLabel->setVisible(true);
        return true;
    }
    return false;
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
        if (!(startLinked->getX() + 1 > this->rows - 1)) {
            nodeFinal = board[startLinked->getX() + 1][startLinked->getY() + 1];
        }

        if (nodeFinal && nodeStart->isConnectedRightAndDown() && nodeFinal->isConnectedLeftAndUp())
        {
            nodeDelete[deleteCount++] = i;
            lastFoundNode = startLinked;

            // poderes y puntos
            BoxGraphics *boxWin = nodeStart->getInfo()->getSquare();
            Players *player = gameRules.peekPlayer();

            // verificacion de bloqueo
            if (!classB.getPowerLS(this->applyFirstPower))
            {
                if (classA.getPowerBL(gameRules, nodeStart, player))
                {
                    this->isBlockade = true;
                    break;
                }
            }
            if (!this->isBlockade) {
                if (nodeStart->getInfo()->getPower() != PowerManager::PowerEnum::NONE)
                {
                    if (player)
                    {
                        PowerManager::PowerEnum power = nodeStart->getInfo()->getPower();
                        player->addPower(power);
                    }
                }

                bool evasiveTS = classB.getPowerTS(gameRules, nodeStart, player, this->applyFirstPower);
                if(!evasiveTS)
                {
                    if (!classB.getPowerUF(gameRules, nodeStart, player) && !classB.getPowerAC(gameRules, nodeStart, player))
                    {
                        boxWin->insertPlayer(player->getLetter(), player->getColor());
                        player->addPoints(1);
                    }
                }
                if (deleteCount >= 4)
                {
                    break;
                }
            }
        }
    }

    if (this->isBlockade)
    {
        QMessageBox::warning(
            this,
            "Turno Bloqueado",
            "Oh no, intentaste completar en un bloqueo"
            );
        return true;
    }

    // llamada a poderes de cuarta clase "D"
    if(deleteCount == 0 && classD.getFourthClass(this->applyFirstPower))
    {
        return true;
    }

    for (int i = deleteCount - 1; i >= 0; i--)
    {
        if (nodeDelete[i] != -1)
            gameRules.deleteNodeLinked(nodeDelete[i]);
    }

    classA.resetPowerBL(gameRules);

    return deleteCount > 0;
}

// boton de uso de poderes
void viewPlay::on_usePowerB_clicked()
{
    Players *currentPlayer = gameRules.getFront()->getPlayer();

    if (!currentPlayer)
    {
        return;
    }
    PowerManager::PowerEnum firstPower = currentPlayer->getPowerStack().pop();

    if (firstPower == PowerManager::PowerEnum::NONE)
    {
        return;
    }

    this->applyFirstPower = firstPower;

    if (classC.getThirdClass(gameRules, this->applyFirstPower))
    {
        displayAllPlayers();
    }
}

void viewPlay::on_pushButton_clicked()
{
    Players *pl = gameRules.getPlayersArray();

    for (int i = 0; i < gameRules.getTotalPlayers(); ++i) {
        qDebug() << pl[i].getLetter();

    }
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

            qDebug() << "Conexion";
            qDebug() << "  Desde: (" << start->getX() << "," << start->getY() << ")";
            qDebug() << "  Hasta: (" << end->getX() << "," << end->getY() << ")";
            std::string powerName = PowerManager::getPowerString(link->getPower());
            qDebug() << " PODER ( " <<  powerName;
            qDebug() << "  indice: " << i;
        }
    }*/

    //NodeLinked *link = gameRules.getNodeLinked(0);
    //Node* start = link->getStartLinked();
    //Node* end = link->getEndLinked();
    //bool power = link->getPower();

    //NodeBoard *node = board[start->getX()][end->getY()];

}

void viewPlay::on_activiteButton_clicked()
{
    for (int i = 0; i < gameRules.getSizeViewPower(); ++i) {

        PowerController *controller = gameRules.getElementPower(i);
        ClickGraphics *clickPointer = controller->getPointerClick();

        PowerManager::PowerEnum power = controller->getPower();
        std::string colorPower = PowerManager::getPowerColor(power);

        clickPointer->setColor(colorPower);
        clickPointer->revealPower();
    }
}


void viewPlay::on_desactiveteButton_clicked()
{
    for (int i = 0; i < gameRules.getSizeViewPower(); ++i) {

        PowerController *controller = gameRules.getElementPower(i);
        ClickGraphics *clickPointer = controller->getPointerClick();
        Players *player = controller->getPlayerLink();
        std::string color = player->getColor();

        clickPointer->setColor(color);
        clickPointer->updateColor();
    }
}

