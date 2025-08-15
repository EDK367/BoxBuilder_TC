#ifndef BOXGRAPHICS_H
#define BOXGRAPHICS_H
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QTextItem>
#include <QBrush>
#include <QObject>
#include <QPen>
#include <QDebug>

class BoxGraphics : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

private:
    QGraphicsTextItem *textItem;
    void updateTextPosition();
public:
    BoxGraphics(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = nullptr);
    void insertPower(const std::string &text);
    void insertPlayer();
};

#endif // BOXGRAPHICS_H
