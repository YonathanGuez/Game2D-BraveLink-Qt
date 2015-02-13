#include "goumba.h"
#include "gamecontroller.h"
#include <QDebug>
#include <QPainter>
#include "constants.h"
#include <QTimer>

//constructeur par defaut
Goumba::Goumba()
{
     qDebug()<<"constructeur par Defaut de Goumba";
    _NomPersonnage="Monstre_Goumba";
    _Foto=QPixmap(":/new/new/images/enemy.png");
    _Speed=5;
    _Force=1;
    _Vie=15;
    _Alive=true;
    _x=600;
    _y=400;
    moveDirection=MoveUp;
    this->setPos(_x,_y);
}
//constructeur par parametre seulment pour les coordonn�es
Goumba::Goumba(qreal x,qreal y,Direction  direction)
{
    qDebug()<<"constructeur par parametre de Goumba";
    _NomPersonnage="Monstre_Goumba";
    _Foto=QPixmap(":/new/new/images/enemy.png");
    _Speed=1;
    _Force=1;
    _Vie=15;
    _Alive=true;
    _x=x;
    _y=y;
    moveDirection=direction;
    this->setPos(_x,_y);
}
//constructeur tout parametre
Goumba::Goumba(QPixmap foto,QString nom, int vitesse, int force,int vie,qreal x, qreal y,bool alive)
{
    qDebug()<<"constructeur par parametre de Goumba";
    _Foto=foto;
    _NomPersonnage=nom;
    _Speed=vitesse;
    _Force=force;
    _Vie=vie;
    _x=x;
    _y=y;
    _Alive=alive;
    moveDirection=MoveUp;
    this->setPos(_x,_y);
}
//destructeur
Goumba::~Goumba()
 {
     qDebug()<<"destructeur  Goumba";
 }
//fonction de cadre de delimitation
QRectF Goumba::boundingRect() const
{
    return QRectF(-25, -25, 50, 50);//mon image fait 100 sur 100 pour toute la bouger
}
//fonction de painture sur la scene
void Goumba::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::NoBrush);
    painter->drawPixmap(-25, -25, _Foto);
}
void Goumba::ParcourMonstre(Personnage *perso)
{
    if(this->getDirection() == Monstre::MoveUp)
    {
        this->setMoveDirection(Monstre::MoveDown);
    }
    else if (this->getDirection() == Monstre::MoveDown)
    {
       this->setMoveDirection(Monstre::MoveUp);
    }
    else if (this->getDirection() == Monstre::MoveLeft)
    {
        this->setMoveDirection(Monstre::MoveRight);
    }
    else if (this->getDirection() ==Monstre::MoveRight)
    {
        this->setMoveDirection(Monstre::MoveLeft);
    }
}


void Goumba::advance(int p)
{
    if (!p) {
        return;
    }
    if(this->_Alive==true)
    {
        if(moveDirection == MoveLeft)
        {
            this->moveLeft();
        }
        else if(moveDirection == MoveRight)
        {
            this->moveRight();
        }
        else if(moveDirection == MoveUp)
        {
            this->moveUp();
        }
        else if(moveDirection == MoveDown)
        {
            this->moveDown();
        }
        this->setPos(_x,_y);
    }
    else
    {   //Foto de Zelda RIP
        this->set_Foto(QPixmap(":/new/new/images/enemyRIP.png"));
    }

}
