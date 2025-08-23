#include "clickgraphics.h"

ClickGraphics::ClickGraphics(int row, int column, qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent) : QObject(),
    QGraphicsRectItem(x, y, w, h, parent),
    row(row), column(column), color("")
{
    setAcceptHoverEvents(true);
    setPen(QPen(Qt::gray, 1));
}

void ClickGraphics::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if (!clicked)
    {
        clicked = true;
        updateColor();
        setEnabled(false);
        emit clickNode(this, row, column);
        setAcceptHoverEvents(false);
    }
    this->color = "";
    Q_UNUSED(event);

}


void ClickGraphics::setColor(std::string color)
{
    this->color = color;
}

void ClickGraphics::resetClick()
{
    if (clicked)
    {
        clicked = false;
        setEnabled(true);
        emit clickNode(this, row, column);
        setAcceptHoverEvents(true);

        setBrush(Qt::NoBrush);
        setPen(QPen(Qt::gray, 1));
    }
}

void ClickGraphics::updateColor()
{
    if (clicked)
    {
        QColor brushColor = QColor(QString::fromStdString(color));
        setBrush(brushColor);
        setPen(QPen(Qt::white, 4));
    }
    else
    {
        setBrush(Qt::lightGray);
    }
}

void ClickGraphics::revealPower()
{
    if (!clicked) return;

    setBrush(QColor(QString::fromStdString(color)));

    QLinearGradient penGradient(0, 0, boundingRect().width(), 0);
    penGradient.setColorAt(0.0, QColor("#FFD700"));
    penGradient.setColorAt(0.5, QColor("#FFC300"));
    penGradient.setColorAt(1.0, QColor("#FFA500"));

    QPen pen(QBrush(penGradient), 2);
    pen.setJoinStyle(Qt::RoundJoin);
    pen.setCapStyle(Qt::RoundCap);

    setPen(pen);
}
