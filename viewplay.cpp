#include "viewplay.h"
#include "ui_viewplay.h"
#include <QMessageBox>
#include <QLabel>
#include <QGridLayout>
#include <QIntValidator>
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
    , classS()
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

            QString coordText = QString("(%1,%2)").arg(i).arg(j);
            QGraphicsTextItem *textItem = new QGraphicsTextItem(coordText, nodePointer);
            textItem->setDefaultTextColor(Qt::white);
            QFont font;
            font.setPointSize(8);
            font.setBold(true);
            textItem->setFont(font);

            QRectF rect = nodePointer->rect();
            QRectF textRect = textItem->boundingRect();
            qreal xPos = rect.left() + (rect.width() - textRect.width()) / 2;
            qreal yPos = rect.top() + (rect.height() - textRect.height()) / 2;
            textItem->setPos(xPos, yPos);


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
                    PowerManager::PowerEnum power = gameRules.getPower(numberPower);
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
    // eliminar el poder al recargar jugadores
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

        Players *playersArray = gameRules.getPlayersArray();
        int totalPlayers = gameRules.getTotalPlayers();

        ui->tablePlayers->setRowCount(totalPlayers);
        ui->tablePlayers->setColumnCount(7);

        QStringList header;
        header << "Letra" << "Color" << "Puntos" << "Cuadros" << "Filas" << "Columnas" << "Poderes";
        ui->tablePlayers->setHorizontalHeaderLabels(header);

        for (int row = 0; row < totalPlayers; ++row)
        {
            Players &player = playersArray[row];
            ui->tablePlayers->setItem(row, 0, new QTableWidgetItem(QString(player.getLetter())));
            QTableWidgetItem *colorItem = new QTableWidgetItem(QString::fromStdString(player.getColor()));
            colorItem->setBackground(QBrush(QColor(QString::fromStdString(player.getColor()))));
            ui->tablePlayers->setItem(row, 1, colorItem);
            ui->tablePlayers->setItem(row, 2, new QTableWidgetItem(QString::number(player.getPoints())));
            ui->tablePlayers->setItem(row, 3, new QTableWidgetItem(QString::number(player.getTotalBox())));
            ui->tablePlayers->setItem(row, 4, new QTableWidgetItem(QString::number(player.getTotalBoxRow())));
            ui->tablePlayers->setItem(row, 5, new QTableWidgetItem(QString::number(player.getTotalBoxColumn())));
            ui->tablePlayers->setItem(row, 6, new QTableWidgetItem(QString::number(player.getTotalPowers() - 77)));
        }
        ui->tablePlayers->resizeColumnsToContents();
        ui->tablePlayers->horizontalHeader()->setStretchLastSection(true);

    }
}

// enlaces de nodos
// enlace horizontal
void viewPlay::linkConnectorHorizontal(ClickGraphics *pointerConnector, int row, int column)
{

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
    // variables generales
    Players *playersArray = gameRules.getPlayersArray();
    int totalPossibleLinks = gameRules.getTotalLinked();
    int currentLinksCreated = gameRules.getSizeViewPower();
    int totalPlayers = gameRules.getTotalPlayers();
    // si ya estan todos los enlaces
    if (currentLinksCreated >= totalPossibleLinks)
    {
        /*
         * #SE VERIFICAN LOS PUNTOS GENRALES ESTO PARA LOS REPORTES
         */

        // variables de conteo
        int *rowWins = new int[totalPlayers]();
        int *colWins = new int[totalPlayers]();

        // para filas
        for (int i = 0; i < this->rows - 1; ++i)
        {
            int *boxCount = new int[totalPlayers]();

            for (int j = 0; j < this->columns - 1; ++j) {
                if (board[i][j] != nullptr && board[i][j]->getInfo()->getPlayer() != nullptr)
                {
                    char playerLetter = board[i][j]->getInfo()->getPlayer()->getLetter();
                    for (int k = 0; k < totalPlayers; ++k)
                    {
                        if (playersArray[k].getLetter() == playerLetter)
                        {
                            boxCount[k]++;
                            break;
                        }
                    }
                }
            }

            int maxBoxes = -1, winnerIndex = -1;
            bool isTie = false;

            for (int k = 0; k < totalPlayers; ++k)
            {
                if (boxCount[k] > maxBoxes)
                {
                    maxBoxes = boxCount[k];
                    winnerIndex = k;
                    isTie = false;
                } else if (boxCount[k] == maxBoxes)
                {
                    isTie = true;
                }
            }

            if (!isTie && winnerIndex != -1 && maxBoxes > 0)
            {
                rowWins[winnerIndex]++;
            }

            delete[] boxCount;
        }

        // para columnas
        for (int j = 0; j < this->columns - 1; ++j)
        {
            int *boxCount = new int[totalPlayers]();

            for (int i = 0; i < this->rows - 1; ++i)
            {
                if (board[i][j] != nullptr && board[i][j]->getInfo()->getPlayer() != nullptr)
                {
                    char playerLetter = board[i][j]->getInfo()->getPlayer()->getLetter();
                    for (int k = 0; k < totalPlayers; ++k)
                    {
                        if (playersArray[k].getLetter() == playerLetter)
                        {
                            boxCount[k]++;
                            break;
                        }
                    }
                }
            }

            int maxBoxes = -1, winnerIndex = -1;
            bool isTie = false;

            for (int k = 0; k < totalPlayers; ++k)
            {
                if (boxCount[k] > maxBoxes) {
                    maxBoxes = boxCount[k];
                    winnerIndex = k;
                    isTie = false;
                }
                else if (boxCount[k] == maxBoxes)
                {
                    isTie = true;
                }
            }

            if (!isTie && winnerIndex != -1 && maxBoxes > 0)
            {
                colWins[winnerIndex]++;
            }

            delete[] boxCount;
        }

        for (int i = 0; i < totalPlayers; ++i)
        {
            playersArray[i].setPoints(playersArray[i].getPoints());
            playersArray[i].setTotalBox(playersArray[i].getTotalBox());
            playersArray[i].setTotalBoxRow(rowWins[i]);
            playersArray[i].setTotalBoxColumn(colWins[i]);
        }

        // por puntos
        sortPlayersByPoints.mergeSortPlayers(playersArray, 0, totalPlayers - 1, 1);
        int firstPlayer =  playersArray[0].getPoints();
        int secondPlayer = playersArray[1].getPoints();
        if (firstPlayer != secondPlayer)
        {
            ui->winLabel->setText(QString("El ganador fue: %1 con %2 total de puntos")
                                      .arg(QChar(playersArray[0].getLetter()))
                                      .arg(playersArray[0].getPoints()));
            ui->winLabel->setVisible(true);
            return true;
        }

        // por cuadrados totales
        sortPlayersByPoints.mergeSortPlayers(playersArray, 0, totalPlayers - 1, 2);
        firstPlayer =  playersArray[0].getTotalBox();
        secondPlayer = playersArray[1].getTotalBox();
        if (firstPlayer != secondPlayer)
        {
            ui->winLabel->setText(QString("El ganador fue: %1 con %2 total de cuadros")
                                      .arg(QChar(playersArray[0].getLetter()))
                                      .arg(playersArray[0].getTotalBox()));
            ui->winLabel->setVisible(true);
            return true;
        }

        // por filas ganadas
        sortPlayersByPoints.mergeSortPlayers(playersArray, 0, totalPlayers - 1, 3);
        firstPlayer =  playersArray[0].getTotalBoxRow();
        secondPlayer = playersArray[1].getTotalBoxRow();
        if (firstPlayer != secondPlayer)
        {
            ui->winLabel->setText(QString("El ganador fue: %1 con %2 filas ganadas")
                                      .arg(QChar(playersArray[0].getLetter()))
                                      .arg(playersArray[0].getTotalBoxRow()));
            ui->winLabel->setVisible(true);
            return true;
        }

        // por columnas ganadas
        sortPlayersByPoints.mergeSortPlayers(playersArray, 0, totalPlayers - 1, 4);
        firstPlayer =  playersArray[0].getTotalBoxColumn();
        secondPlayer = playersArray[1].getTotalBoxColumn();
        if (firstPlayer != secondPlayer)
        {
            ui->winLabel->setText(QString("El ganador fue: %1 con %2 columnas ganadas")
                                      .arg(QChar(playersArray[0].getLetter()))
                                      .arg(playersArray[0].getTotalBoxColumn()));
            ui->winLabel->setVisible(true);
            return true;
        }

        // por total de podres usados
        sortPlayersByPoints.mergeSortPlayers(playersArray, 0, totalPlayers - 1, 5);
        firstPlayer =  playersArray[0].getTotalPowers();
        secondPlayer = playersArray[1].getTotalPowers();
        if (firstPlayer != secondPlayer)
        {
            ui->winLabel->setText(QString("El ganador fue: %1 con %2 poderes usados")
                                      .arg(QChar(playersArray[0].getLetter()))
                                      .arg(playersArray[0].getTotalPowers() - 77));
            ui->winLabel->setVisible(true);
            return true;
        }

        delete[] rowWins;
        delete[] colWins;

        ui->winLabel->setText("EMPATE TECNICO NADIE GANA");
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

            if (!boxWin->getState())
            {
                continue;
            }
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
                        nodeStart->getInfo()->setPlayer(player);
                        nodeStart->getInfo()->getPlayer()->addTotalBox(1);
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

    currentPlayer->addTotalPowers(1);
    if (classC.getThirdClass(gameRules, this->applyFirstPower))
    {
        displayAllPlayers();
    }
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

// mecanica extra donde se puede usar pase pero descontando un punto
void viewPlay::on_pasePowerB_clicked()
{
    Players *currentPlayer = gameRules.getFront()->getPlayer();

    if (currentPlayer)
    {
        this->applyFirstPower = PowerManager::PowerEnum::PS;
        currentPlayer->addPoints(-1);
        currentPlayer->addTotalPowers(1);
        if (classC.getThirdClass(gameRules, this->applyFirstPower))
        {
            displayAllPlayers();
        }
    }
}

void viewPlay::on_specialButton_clicked()
{
    // solo poder especial
    if ((this->applyFirstPower != PowerManager::PowerEnum::NT) && (this->applyFirstPower != PowerManager::PowerEnum::EX))
    {
        QMessageBox::warning(
            this,
            "Error",
            "ESTE BOTON SOLO PUEDE USARSE CON UN PODER DE CLASE ESPECIAL."
            );
        return;

    }

    QString xText = ui->xEdit->text();
    QString yText = ui->yEdit->text();

    // validaciones
    if (xText.isEmpty() || yText.isEmpty())
    {
        QMessageBox::warning(
            this,
            "Error",
            "Debe llenar todos los campos."
            );
        return;
    }

    QIntValidator validator(0, INT_MAX, this);
    int pos = 0;

    if (validator.validate(xText, pos) != QValidator::Acceptable)
    {
        QMessageBox::warning(
            this,
            "Error",
            "La posicion X debe ser un numero no negativo.");
        return;
    }

    pos = 0;
    if (validator.validate(yText, pos) != QValidator::Acceptable)
    {
        QMessageBox::warning(
            this,
            "Error",
            "La posicion Y debe ser un numero no negativo."
            );
        return;
    }
    int xPosition = xText.toInt();
    int yPosition = yText.toInt();

    NodeBoard* targetNode = this->board[xPosition][yPosition];
    if (targetNode && classS.getPowerEX(gameRules, targetNode))
    {

       QMessageBox::information(this, "Dominio", "Se ha destruido el dominio");
    }
    else
    {
        QMessageBox::warning(
            this,
            "Error",
            "No se pudo eliminar el nodo en la posición especificada."
            );
    }
}

