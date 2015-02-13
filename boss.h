#ifndef BOSS_H
#define BOSS_H

#include "monstre.h"

class Boss:public Monstre
{
public:
    Boss();
    Boss(qreal x,qreal y);
    Boss(QPixmap foto, QString nom, int vitesse, int force, int vie, qreal x, qreal y, bool alive);
    ~Boss();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void advance(int p);
    void setPhotoDeplacement(Direction position);
    void ParcourMonstre(Personnage *perso);
 private:

};

#endif // BOSS_H
