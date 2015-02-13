#ifndef SONIC_H
#define SONIC_H

#include "monstre.h"

class Sonic:public Monstre
{
public:
    Sonic();
    Sonic(qreal x,qreal y);
    Sonic(QPixmap foto, QString nom, int vitesse, int force, int vie, qreal x, qreal y, bool alive);
    ~Sonic();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void advance(int p);
    void setPhotoDeplacement(Direction position);
 private:



};

#endif // SONIC_H
