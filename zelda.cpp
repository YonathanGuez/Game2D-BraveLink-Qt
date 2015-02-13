#include <QPainter>
#include <QDebug>
#include "constants.h"
#include "gamecontroller.h"
#include "monstre.h"
#include "zelda.h"
#include <QDebug>

Zelda::Zelda(GameController &control):controller(control)
{
     qDebug()<< "constructeur de ZELDA ";
    _NomPersonnage="ZELDA";
    _Foto = QPixmap(":/new/new/images/zeldaDown.png");
    _x=200;
    _y=200;
    _Force=2;
    _Speed=10;
    _Vie=50;
    _Alive=true;
    To_Be_Arme1=false;
    To_Be_Arme2=false;
    moveDirection=NoMove;
    Yourposition=Down;
    giveAttaque=Nothink;
    Nb_Tresor=0;
    Nb_Tuer=0;
    setData(GD_Type, GO_Zelda);

}
Zelda::~Zelda()
{
    qDebug()<< "Destructeur de ZELDA ";
}

QRectF Zelda::boundingRect() const
{
    return QRectF(-32, -96/2, 50, 50);//mon image fait 100 sur 100 pour toute la bouger
}

void Zelda::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::NoBrush);
    painter->drawPixmap(-32, -46, _Foto);
}

void Zelda::setgiveAttaque(Attaque attaque)
{
    giveAttaque = attaque;
}

//getteur retournant la direction que va prendre zelda


Zelda::Attaque Zelda::getAttaque()
{
    return giveAttaque;
}
bool Zelda::get_Be_Arme1()
{
    return To_Be_Arme1;
}
void Zelda::set_Be_Arme1(bool k)
{
    To_Be_Arme1=k;
    if(k==true)
    {
        qDebug()<<"Zelda est Armer de sciseaux ";
    }
}
bool Zelda::get_Be_Arme2()
{
    return To_Be_Arme2;
}

void Zelda::set_Be_Arme2(bool k)
{
    To_Be_Arme2=k;
    if(k==true)
    {
        qDebug()<<"Zelda est Armer d un extincteur' ";
    }

}

void Zelda::PhotoLeft(Attaque attaque)
{

    if(attaque == Cut)
    {
        _Foto = QPixmap(":/new/new/images/zeldaLeftA.png");
    }
    else if(attaque == Defance)
    {
        _Foto = QPixmap(":/new/new/images/zeldaLeftA2.png");
    }
    else if(attaque == Nothink)
    {
        _Foto = QPixmap(":/new/new/images/zeldaLeft.png");
    }
}

void Zelda::PhotoRight(Attaque attaque)
{

    if(attaque == Cut)
    {
        _Foto = QPixmap(":/new/new/images/zeldaRightA.png");
    }
    else if(attaque == Defance)
    {
        _Foto = QPixmap(":/new/new/images/zeldaRightA2.png");
    }
    else if(attaque == Nothink)
    {
        _Foto = QPixmap(":/new/new/images/zeldaRight.png");
    }
}

void Zelda::PhotoUp(Attaque attaque)
{
    if(attaque == Cut)
    {
        _Foto = QPixmap(":/new/new/images/zeldaUpA.png");
    }
    else if(attaque == Defance)
    {
        _Foto = QPixmap(":/new/new/images/zeldaUpA2.png");
    }
    else if(attaque==Nothink)
    {
        _Foto = QPixmap(":/new/new/images/zeldaUp.png");
    }
}

void Zelda::PhotoDown(Attaque attaque)
{

    if(attaque == Cut)
    {
        _Foto = QPixmap(":/new/new/images/zeldaDownA.png");
    }
    else if(attaque == Defance)
    {
        _Foto = QPixmap(":/new/new/images/zeldaDownA2.png");
    }
    else if(attaque == Nothink)
    {
        _Foto = QPixmap(":/new/new/images/zeldaDown.png");
    }
}
void Zelda::setPhotoAttaque(Attaque attaque, Position position)
{
    switch (position)
    {
        case Left:
            PhotoLeft(attaque);
            break;
        case Right:
            PhotoRight(attaque);
            break;
        case Up:
            PhotoUp(attaque);
            break;
        case Down:
            PhotoDown(attaque);
            break;
        default:
            break;
    }

}

int Zelda::get_Tresor()
{
   return Nb_Tresor;
}

int Zelda::get_Tuer()
{
    return Nb_Tuer;
}
void Zelda::set_Tuer()
{
    Nb_Tuer=this->get_Tuer()+1;
    qDebug()<<"Vous avez tuer "<<Nb_Tuer<<" Monstre ";
}
void Zelda::set_Tresor()
{
   Nb_Tresor=this->get_Tresor()+10;
   qDebug()<<"Votre Fortune est de  "<<Nb_Tuer<<" Tresors ";
}

//envoi de la position du personnage
void Zelda::advance(int step)
{
    if (!step) {
        return;
    }
    setFlag(ItemIsFocusable);
    setFocus();
    //si le personnage est encore en vie
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
        else{}
    }
    else
    {   //Foto de Zelda RIP
        this->set_Foto(QPixmap(":/new/new/images/zeldaRIP.png"));
    }
    this->setPos(_x,_y);
    controller.DecorCollisions();
}


