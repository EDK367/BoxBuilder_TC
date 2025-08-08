#include "viewplay.h"
#include "ui_viewplay.h"

viewPlay::viewPlay(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::viewPlay)
{
    ui->setupUi(this);
}

viewPlay::~viewPlay()
{
    delete ui;
}
