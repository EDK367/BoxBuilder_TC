#ifndef VIEWPLAY_H
#define VIEWPLAY_H
#include <QFrame>
#include <QObject>
#include <QCloseEvent>
#include "rules/gameRules.h"
#include "models/nodeboard.h"
#include "methods/randomnative.h"
#include "utils/clickgraphics.h"

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
    NodeBoard ***board;
    int rows;
    int columns;
    void chargeGameRules();
    void chargeBoard();
    void displayAllPlayers();


protected:
    void closeEvent(QCloseEvent *event) override;
    void showEvent(QShowEvent *event) override;

private slots:
    void on_pushButton_clicked();
    void linkConnectorHorizontal(ClickGraphics *pointerConnector, int row, int column);
    void linkConnectorVertical(ClickGraphics *pointerConnector, int row, int column);
};

#endif // VIEWPLAY_H
