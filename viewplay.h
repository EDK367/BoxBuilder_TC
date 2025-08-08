#ifndef VIEWPLAY_H
#define VIEWPLAY_H

#include <QFrame>

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
};

#endif // VIEWPLAY_H
