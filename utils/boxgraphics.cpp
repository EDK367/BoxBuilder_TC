#include "boxgraphics.h"

BoxGraphics::BoxGraphics(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent) : QObject(),
    QGraphicsRectItem(x, y, w, h, parent)
{
    setPen(QPen(Qt::cyan, 2));

    // visualizacion de poder en el tablero no enlaces
    textItem = new QGraphicsTextItem("", this);
    textItem->setDefaultTextColor(Qt::red);
    textItem->setZValue(1);

    // estilos
    QFont font;
    font.setPointSize(15);
    font.setBold(true);
    textItem->setFont(font);
}

void BoxGraphics::insertPower(const std::string &text)
{
    QString qtText = QString::fromStdString(text);
    textItem->setPlainText(qtText);

    QRectF boxRect = rect();
    QRectF textRect = textItem->boundingRect();

    qreal xPos = boxRect.left() + (boxRect.width() - textRect.width()) / 2;
    qreal yPos = boxRect.top() + (boxRect.height() - textRect.height()) / 2;

    textItem->setPos(xPos, yPos);
}

void BoxGraphics::insertPlayer(const char &name, const std::string &color)
{
    QString qtText(name);
    textItem->setPlainText(qtText);

    QColor qColor(QString::fromStdString(color));

    setBrush(QBrush(qColor));
    setPen(QPen(Qt::white));
    QColor textColor = (qColor == Qt::black ? Qt::white : Qt::black);
    textItem->setDefaultTextColor(textColor);

    QRectF boxRect = rect();
    QRectF textRect = textItem->boundingRect();

    qreal xPos = boxRect.left() + (boxRect.width() - textRect.width()) / 2;
    qreal yPos = boxRect.top() + (boxRect.height() - textRect.height()) / 2;

    textItem->setPos(xPos, yPos);
}
