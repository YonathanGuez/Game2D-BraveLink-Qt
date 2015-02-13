#ifndef LINK_H
#define LINK_H
#include "personnage.h"

class Link:public Personnage
{
public:
    Link();
    Link(qreal x,qreal y);
    Link(QPixmap foto, QString nom, int vitesse, int force, int vie, qreal x, qreal y, bool alive);
    ~Link();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void advance(int p);
    void setPhotoDeplacement(Direction position);
 private:

};

#endif // LINK_H
