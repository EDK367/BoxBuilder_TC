#ifndef CLICKGRAPHICS_H
#define CLICKGRAPHICS_H
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QObject>
#include <QPen>
#include <QDebug>

class ClickGraphics : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    ClickGraphics(int row, int column, qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = nullptr);
    void setColor(std::string color);
    void updateColor();

signals:
    void clickNode(ClickGraphics *pointer, int row, int column);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    int row;
    int column;
    std::string color = "";
    bool clicked = false;
};

#endif // CLICKGRAPHICS_H
