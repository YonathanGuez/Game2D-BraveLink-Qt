#ifndef GOUMBA_H
#define GOUMBA_H
#include "monstre.h"
#include "personnage.h"
class GameController;

class Goumba:public Monstre
{
public:
    Goumba();
    Goumba(qreal x, qreal y, Direction direction);
    Goumba(QPixmap foto, QString nom, int vitesse, int force, int vie, qreal x, qreal y, bool alive);
    ~Goumba();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void advance(int p);
    void ParcourMonstre(Personnage *perso);
 private:



};

#endif // GOUMBA_H
