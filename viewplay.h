#ifndef VIEWPLAY_H
#define VIEWPLAY_H
#include <QFrame>
#include <QObject>
#include <QCloseEvent>
#include "rules/gameRules.h"
#include "models/nodeboard.h"
#include "methods/randomnative.h"
#include "methods/probability.h"
#include "utils/clickgraphics.h"
#include "powers/fourthclass.h"
#include "powers/thirdclass.h"
#include "methods/controller/controllerVector.h"
#include "methods/sortarrayplayers.h"
#include "powers/secondclass.h"
#include "models/controller/controllerBL.h"
#include "powers/firstclass.h"

namespace Ui {
class viewPlay;
}

class viewPlay : public QFrame
{
    Q_OBJECT

public:
    explicit viewPlay(QWidget *parent = nullptr);
    ~viewPlay();

private:
    Ui::viewPlay *ui;
    GameRules &gameRules;
    RandomNative random;
    Probability probability;
    SortArrayPlayers sortPlayersByPoints;
    NodeBoard ***board;
    PowerManager::PowerEnum applyFirstPower;
    FourthClass classD;
    ThirdClass classC;
    SecondClass classB;
    FirstClass classA;
    int rows;
    int columns;
    bool isBlockade;
    void chargeGameRules();
    void chargeBoard();
    void displayAllPlayers();
    bool verifyBoxCompletion();
    bool finishGame();

protected:
    void closeEvent(QCloseEvent *event) override;
    void showEvent(QShowEvent *event) override;

private slots:
    void linkConnectorHorizontal(ClickGraphics *pointerConnector, int row, int column);
    void linkConnectorVertical(ClickGraphics *pointerConnector, int row, int column);
    void on_usePowerB_clicked();
    void on_activiteButton_clicked();
    void on_desactiveteButton_clicked();
    void on_pasePowerB_clicked();
};

#endif // VIEWPLAY_H
