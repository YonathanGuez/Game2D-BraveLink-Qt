#include "monstre.h"
#include "constants.h"
#include <QDebug>

Monstre::Monstre():Personnage::Personnage()
{
    _NomPersonnage="Monstre";
    qDebug()<< "constructeur de monstre ";
    setData(GD_Type, GO_Monstre);
}
Monstre::Monstre(qreal x,qreal y):Personnage::Personnage(_x,_y)
{
    qDebug()<< "constructeur de monstre par parametre ";
    _NomPersonnage="Monstre";
    _x=x;
    _y=y;
    setData(GD_Type, GO_Monstre);

}

Monstre::Monstre(QPixmap foto, QString nom, int vitesse, int force,int vie, qreal x, qreal y, bool alive):
    Personnage::Personnage( _Foto,_NomPersonnage,_Speed,_Force,_Vie,_x,_y,_Alive)
{
    qDebug()<<"constructeur par parametre de Monstre ";

    _Foto=foto;
    _NomPersonnage=nom;
    _Speed=vitesse;
    _Force=force;
    _Vie=vie;
    _x=x;
    _y=y;
    _Alive=alive;

    this->setPos(_x,_y);
    setData(GD_Type, GO_Monstre);
}
Monstre::~Monstre()
{
    qDebug()<<"Destructeur de monstre  ";

}
void Monstre::PositionMonstre()
{
    if(this->getPosition() == Monstre::Up)
    {
        this->setMoveDirection(Monstre::MoveDown);
    }
    else if (this->getPosition() == Monstre::Right)
    {
       this->setMoveDirection(Monstre::MoveLeft);
    }
    else if (this->getPosition() == Monstre::Right)
    {
        this->setMoveDirection(Monstre::MoveLeft);
    }
    else if (this->getPosition() == Monstre::Up)
    {
        this->setMoveDirection(Monstre::MoveDown);
    }
}

void Monstre::ParcourMonstre(Personnage *perso)
{
    if(this->getDirection() == Monstre::MoveUp)
    {
        this->setMoveDirection(Monstre::MoveDown);
    }
    else if (this->getDirection() == Monstre::MoveDown)
    {
       this->setMoveDirection(Monstre::MoveLeft);
    }
    else if (this->getDirection() == Monstre::MoveLeft)
    {
        this->setMoveDirection(Monstre::MoveRight);
    }
    else if (this->getDirection() ==Monstre::MoveRight)
    {
        this->setMoveDirection(Monstre::MoveUp);
    }
}
