#include "link.h"
#include "gamecontroller.h"
#include <QDebug>
#include <QPainter>
#include "constants.h"
#include <QTimer>

//constructeur par defaut
Link::Link():Personnage::Personnage()
{
     qDebug()<<"constructeur par Defaut de Link";
    _NomPersonnage="Link";
    _Foto=QPixmap(":/new/new/images/LinkDown.png");
    _Speed=5;
    _Force=1;
    _Alive=true;
    _x=600;
    _y=400;
    moveDirection=NoMove;
    setData(GD_Type, GO_Link);
    this->setPos(_x,_y);
}
//constructeur par parametre seulment pour les coordonn�es
Link::Link(qreal x,qreal y):Personnage::Personnage(_x,_y)
{
    qDebug()<<"constructeur par parametre de Link";
    _NomPersonnage="Link";
    _Foto=QPixmap(":/new/new/images/LinkDown.png");
    _Speed=1;
    _Force=1;
    _Vie=20;
    _Alive=true;
    _x=x;
    _y=y;
    moveDirection=NoMove;
    setData(GD_Type, GO_Link);
    this->setPos(_x,_y);
}
//constructeur tout parametre
Link::Link(QPixmap foto,QString nom, int vitesse, int force,int vie,qreal x, qreal y,bool alive)
{
    qDebug()<<"constructeur par parametre de Link";
    _Foto=foto;
    _NomPersonnage=nom;
    _Speed=vitesse;
    _Force=force;
    _Vie=vie;
    _x=x;
    _y=y;
    _Alive=alive;
    moveDirection=NoMove;
    setData(GD_Type, GO_Link);
    this->setPos(_x,_y);
}
//destructeur
Link::~Link()
 {
     qDebug()<<"destructeur  Link";
 }
//fonction de cadre de delimitation
QRectF Link::boundingRect() const
{
    return QRectF(-25, -25, 50, 50);//mon image fait 100 sur 100 pour toute la bouger
}
//fonction de painture sur la scene
void Link::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::NoBrush);
    painter->drawPixmap(-30, -30, _Foto);
}

void Link::setPhotoDeplacement(Direction position)
{
    switch (position)
    {
        case MoveLeft:
            this->set_Foto(QPixmap(":/new/new/images/LinkLeft.png"));
            break;
        case MoveRight:
            this->set_Foto(QPixmap(":/new/new/images/LinkRight.png"));
            break;
        case MoveUp:
            this->set_Foto(QPixmap(":/new/new/images/LinkUp.png"));
            break;
        case MoveDown:
            this->set_Foto(QPixmap(":/new/new/images/LinkDown.png"));
            break;
        default:
            break;
    }

}

void Link::advance(int p)
{
    if (!p) {
        return;
    }
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
