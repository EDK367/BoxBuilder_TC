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

protected:
    void closeEvent(QCloseEvent *event) override;
    void showEvent(QShowEvent *event) override;

private slots:
    void on_pushButton_clicked();
    void linkConnectorHorizontal(ClickGraphics *pointerConnector, int row, int column);
    void linkConnectorVertical(ClickGraphics *pointerConnector, int row, int column);
    void on_usePowerB_clicked();
};

#endif // VIEWPLAY_H
