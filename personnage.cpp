#include "personnage.h"
#include <QDebug>

Personnage::Personnage():_NomPersonnage("Personnage")
{
        qDebug()<< "constructeur de Personnage ";
}
Personnage::Personnage(qreal x, qreal y)
{
    qDebug()<< "constructeur de Personnage par parametre ";
    _NomPersonnage="Personnage";
    _x=x;
    _y=y;
}
Personnage::Personnage(QPixmap foto, QString nom, int vitesse, int force, int vie, qreal x, qreal y, bool alive)
{
    qDebug()<<"constructeur par parametre de Personnage ";

    _Foto=foto;
    _NomPersonnage=nom;
    _Speed=vitesse;
    _Force=force;
    _Vie=vie;
    _x=x;
    _y=y;
    _Alive=alive;

    this->setPos(_x,_y);
}
Personnage::Personnage(Personnage &P)
{
    qDebug()<<"constructeur par copie de Personnage ";

    _Foto=P._Foto;
    _NomPersonnage=P._NomPersonnage;
    _Speed=P._Speed;
    _Force=P._Force;
    _Alive=P._Alive;
    _Vie=P._Vie;

}
Personnage::~Personnage()
{
    qDebug()<<"Destructeur de Personnage  ";
}
//////////////////////getteur
QString Personnage::get_NomMonstre()
{
    return _NomPersonnage;
}

QPixmap Personnage::get_Foto()
{
    return _Foto;
}
bool Personnage::get_Alive()
{
    return _Alive;
}

int Personnage::get_Speed()
{
    return _Speed;
}

int Personnage::get_Force()
{
    return _Force;
}
int Personnage::get_Vie()
{
    return _Vie;
}
int Personnage::get_X()
{
    return _x;
}
int Personnage::get_Y()
{
    return _y;
}
Personnage::Position Personnage::getPosition()
{
    return Yourposition;
}


////////////////////////Setteur

void Personnage::setPosition(Position position)
{
    Yourposition = position;
}
void Personnage::set_NomMonstre(QString nom)
{
    _NomPersonnage=nom;
}

void Personnage::set_Alive(bool alive)
{
    _Alive=alive;
}

void Personnage::set_Foto(QPixmap foto)
{
    _Foto=foto;
}

void Personnage::set_Speed(int vitesse)
{
    _Speed=vitesse;
}
void Personnage::set_Force(int puissance)
{
    _Force=puissance;
}
void Personnage::set_Vie(int vie)
{
    _Vie=vie;
}
void Personnage::set_X(int x)
{
    _x=x;
}
void Personnage::set_Y(int y)
{
    _y=y;
}

void Personnage::Perso_IS_Dead()
{
        qDebug()<<this->_NomPersonnage<<" est mort";
        this->_Alive=false;
}

void Personnage::setMoveDirection(Direction direction)
{
    moveDirection = direction;
}
Personnage::Direction Personnage::getDirection()
{
    return moveDirection;
}

void Personnage::moveLeft()
{
    this->set_X(_x-_Speed);
}
void Personnage::moveRight()
{
    this->set_X(_x+_Speed);
}
void Personnage::moveUp()
{
   this->set_Y(_y-_Speed);
}
void Personnage::moveDown()
{
    this->set_Y(_y+_Speed);
}
void Personnage::Ma_Position()
{
    if(this->getDirection()== MoveUp)
    {
        this->setPosition(Up);
    }
    else if(this->getDirection()== MoveDown)
    {
        this->setPosition(Down);
    }
    else if(this->getDirection()== MoveLeft)
    {
        this->setPosition(Left);
    }
    else if(this->getDirection()== MoveRight)
    {
        this->setPosition(Right);
    }
}

void Personnage::Lose_Life(int lose)
{
    if(this->_Vie > 0)
    {
        this->set_Vie((this->_Vie)-lose);
        qDebug()<<"la vie de" <<this->_NomPersonnage<<" est de :"<<this->_Vie;
    }
    else if(this->_Vie <=0)
    {
        this->Perso_IS_Dead();
    }
}
