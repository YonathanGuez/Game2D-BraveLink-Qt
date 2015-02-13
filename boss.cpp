#include "boss.h"
#include "gamecontroller.h"
#include <QDebug>
#include <QPainter>
#include "constants.h"
#include <QTimer>

//constructeur par defaut
Boss::Boss()
{
     qDebug()<<"constructeur par Defaut de Boss";
    _NomPersonnage="Monstre_Boss";
    _Foto=QPixmap(":/new/new/images/BossUp.png");
    _Speed=10;
    _Force=5;
    _Vie=100;
    _Alive=true;
    _x=600;
    _y=400;
    moveDirection=MoveUp;
    this->setPos(_x,_y);
}
//constructeur par parametre seulment pour les coordonn�es
Boss::Boss(qreal x,qreal y)
{
    qDebug()<<"constructeur par parametre de Boss";
    _NomPersonnage="Monstre_Boss";
    _Foto=QPixmap(":/new/new/images/BossUp.png");
    _Speed=10;
    _Force=5;
    _Vie=100;
    _Alive=true;
    _x=x;
    _y=y;
    moveDirection=MoveUp;
    this->setPos(_x,_y);
}
//constructeur tout parametre
Boss::Boss(QPixmap foto,QString nom, int vitesse, int force,int vie,qreal x, qreal y,bool alive)
{
    qDebug()<<"constructeur par parametre de Boss";
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
Boss::~Boss()
 {
     qDebug()<<"destructeur  Boss";
 }
//fonction de cadre de delimitation
QRectF Boss::boundingRect() const
{
    return QRectF(-50, -50, 100, 100);//mon image fait 100 sur 100 pour toute la bouger
}
//fonction de painture sur la scene
void Boss::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::NoBrush);
    painter->drawPixmap(-50, -50, _Foto);
}
void Boss::setPhotoDeplacement(Direction position)
{
    switch (position)
    {
        case MoveLeft:
            this->set_Foto(QPixmap(":/new/new/images/BossLeft.png"));
            break;
        case MoveRight:
            this->set_Foto(QPixmap(":/new/new/images/BossRight.png"));
            break;
        case MoveUp:
            this->set_Foto(QPixmap(":/new/new/images/BossUp.png"));
            break;
        case MoveDown:
            this->set_Foto(QPixmap(":/new/new/images/BossDown.png"));
            break;
        default:
            break;
    }
}

void Boss::ParcourMonstre(Personnage *perso)
{// le monstre va suivre zelda
   qreal x=perso->get_X();
   qreal y=perso->get_Y();

   if(x >=this->get_X()+50)
   {
       this->setMoveDirection(Monstre::MoveRight);
   }
   else if (x <= this->get_X()-50)
   {
       this->setMoveDirection(Monstre::MoveLeft);
   }
   else if( (x <this->get_X()+50) && (x> this->get_X()-50))
   {
       if(y > this->get_Y()+50)
       {
            this->setMoveDirection(Monstre::MoveDown);
       }
       else if (y <this->get_Y()-50)
       {
            this->setMoveDirection(Monstre::MoveUp);
       }
       else if ((y <= this->get_Y()+50)&&(y >=this->get_Y()-50))
       {
           if(x >=this->get_X()+10)
           {
               this->setMoveDirection(Monstre::MoveRight);
           }
           else if (x <= this->get_X()-10)
           {
               this->setMoveDirection(Monstre::MoveLeft);
           }
           else{}
       }
   }
}
void Boss::advance(int p)
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
        this->set_Foto(QPixmap(":/new/new/images/BossRIP.png"));
    }
}
