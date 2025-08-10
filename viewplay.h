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
    void chargeGameRules();


protected:
    void closeEvent(QCloseEvent *event) override;
    void showEvent(QShowEvent *event) override;

private slots:

};

#endif // VIEWPLAY_H
