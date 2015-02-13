#ifndef ELEMENT_H
#define ELEMENT_H

#include <constants.h>
#include <QString>
#include <QGraphicsItem>

class Element : public QGraphicsItem
{
public:
    Element(qreal x, qreal y, QString AdresseTexture , GameObjectTypes type, int dim);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
protected:
    int taille;
    QPixmap Texture;

};

#endif // ELEMENT_H
