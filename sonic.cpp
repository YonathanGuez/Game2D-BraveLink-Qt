#include "sonic.h"
#include "gamecontroller.h"
#include <QDebug>
#include <QPainter>
#include "constants.h"
#include <QTimer>

//constructeur par defaut
Sonic::Sonic()
{
     qDebug()<<"constructeur par Defaut de Sonic";
    _NomPersonnage="Monstre_Sonic";
    _Foto=QPixmap(":/new/new/images/SonicUp.png");
    _Speed=5;
    _Force=1;
    _Vie=30;
    _Alive=true;
    _x=600;
    _y=400;
    moveDirection=MoveUp;
    this->setPos(_x,_y);
}
//constructeur par parametre seulment pour les coordonn�es
Sonic::Sonic(qreal x,qreal y)
{
    qDebug()<<"constructeur par parametre de Sonic";
    _NomPersonnage="Monstre_Sonic";
    _Foto=QPixmap(":/new/new/images/SonicUp.png");
    _Speed=5;
    _Force=1;
    _Vie=4;
    _Alive=true;
    _x=x;
    _y=y;
    moveDirection=MoveUp;
    this->setPos(_x,_y);
}
//constructeur tout parametre
Sonic::Sonic(QPixmap foto,QString nom, int vitesse, int force,int vie,qreal x, qreal y,bool alive)
{
    qDebug()<<"constructeur par parametre de Sonic";
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
Sonic::~Sonic()
 {
     qDebug()<<"destructeur  Sonic";
 }
//fonction de cadre de delimitation
QRectF Sonic::boundingRect() const
{
    return QRectF(-25, -25, 50, 50);//mon image fait 100 sur 100 pour toute la bouger
}
//fonction de painture sur la scene
void Sonic::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::NoBrush);
    painter->drawPixmap(-30, -30, _Foto);
}

void Sonic::setPhotoDeplacement(Direction position)
{
    switch (position)
    {
        case MoveLeft:
            this->set_Foto(QPixmap(":/new/new/images/SonicLeft.png"));
            break;
        case MoveRight:
            this->set_Foto(QPixmap(":/new/new/images/SonicRight.png"));
            break;
        case MoveUp:
            this->set_Foto(QPixmap(":/new/new/images/SonicUp.png"));
            break;
        case MoveDown:
            this->set_Foto(QPixmap(":/new/new/images/SonicDown.png"));
            break;
        default:
            break;
    }

}

void Sonic::advance(int p)
{
    if (!p) {
        return;
    }
    if(this->_Alive==true)
    {
        if(moveDirection == MoveLeft)
        {
            this->setPhotoDeplacement(this->getDirection());
            this->moveLeft();
        }
        else if(moveDirection == MoveRight)
        {
            this->setPhotoDeplacement(this->getDirection());
            this->moveRight();
        }
        else if(moveDirection == MoveUp)
        {
            this->setPhotoDeplacement(this->getDirection());
            this->moveUp();
        }
        else if(moveDirection == MoveDown)
        {
            this->setPhotoDeplacement(this->getDirection());
            this->moveDown();
        }
        this->setPos(_x,_y);
    }
    else
    {   //Foto de Zelda RIP
        this->set_Foto(QPixmap(":/new/new/images/SonicRIP.png"));
    }

}
