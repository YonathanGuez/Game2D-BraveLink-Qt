#ifndef ZELDA_H
#define ZELDA_H
#include "personnage.h"
#include <QGraphicsItem>
#include <QRectF>

class GameController;

class Zelda : public Personnage
{
public:
    enum Attaque{
        Cut,
        Nothink,
        Defance
    };

    Zelda(GameController & controller);
    ~Zelda();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

    Attaque getAttaque();
    bool get_Be_Arme1();
    void set_Be_Arme1(bool k);
    bool get_Be_Arme2();
    void set_Be_Arme2(bool k);
    void setgiveAttaque(Attaque attaque);
    //renvoi la foto par rapport a la direction
    void setPhotoAttaque(Attaque attaque, Position position);
   // void setPhoto(PositionZelda position);
    void PhotoLeft(Attaque attaque);
    void PhotoRight(Attaque attaque);
    void PhotoUp(Attaque attaque);
    void PhotoDown(Attaque attaque);

    void set_Tresor();
    void set_Tuer();
    int get_Tresor();
    int get_Tuer();
protected:
    //replace le personnage a chaque evenement
    void advance(int step);
private:
    bool To_Be_Arme1;
    bool To_Be_Arme2;
    int Nb_Tresor;
    int Nb_Tuer;

    Attaque        giveAttaque;
    GameController &controller;
};

#endif // ZELDA_H
