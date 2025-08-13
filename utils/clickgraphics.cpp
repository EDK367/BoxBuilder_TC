#include "clickgraphics.h"

ClickGraphics::ClickGraphics(int row, int column, qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent) : QObject(),
    QGraphicsRectItem(x, y, w, h, parent),
    row(row), column(column), color("")
{
    setAcceptHoverEvents(true);
    setBrush(Qt::black);
    setPen(QPen(Qt::cyan, 2));
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

void ClickGraphics::updateColor()
{
    if (clicked)
    {
        QColor brushColor = QColor(QString::fromStdString(color));
        setBrush(brushColor);
    }
    else
    {
        setBrush(Qt::lightGray);
    }
}
