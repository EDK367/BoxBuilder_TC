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
    bool state = true;
public:
    BoxGraphics(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = nullptr);
    void insertPower(const std::string &text);
    void insertPlayer(const char &name, const std::string &color);
    void resetBox(bool state);

    bool getState() const;
};

#endif // BOXGRAPHICS_H
