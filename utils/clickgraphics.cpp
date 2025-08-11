#include "clickgraphics.h"

ClickGraphics::ClickGraphics(int row, int column, qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent) : QObject(),
    QGraphicsRectItem(x, y, w, h, parent),
    row(row), column(column)
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
        updateClick();
        setEnabled(false);
        emit clickNode(row, column);
        setAcceptHoverEvents(false);
    }

    Q_UNUSED(event);

}


void ClickGraphics::updateClick()
{
    setBrush(clicked ? Qt::red : Qt::black);
}
