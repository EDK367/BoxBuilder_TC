#ifndef VIEWPLAY_H
#define VIEWPLAY_H
#include <QFrame>
#include <QCloseEvent>
#include "rules/gameRules.h"

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
    int rows;
    int columns;
    void chargeGameRules();


protected:
    void closeEvent(QCloseEvent *event) override;
    void showEvent(QShowEvent *event) override;

private slots:

    void on_pushButton_clicked();
};

#endif // VIEWPLAY_H
