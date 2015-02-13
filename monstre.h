#ifndef MONSTRE_H
#define MONSTRE_H
#include "personnage.h"
#include <QGraphicsItem>
#include <QRectF>
#include <QString>

class Monstre: public Personnage
{

public:
    //constructeur(defaut ,parametre,copie)// destructeur
    Monstre();
    Monstre(qreal x,qreal y);
    Monstre(QPixmap foto,QString nom, int vitesse, int force,int vie,qreal x, qreal y,bool alive);
   // Monstre(Monstre &M);
    ~Monstre();

  virtual void ParcourMonstre(Personnage *perso);
  void PositionMonstre();
};

#endif // MONSTRE_H
