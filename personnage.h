#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <QGraphicsItem>
#include <QRectF>
#include <QString>

class Personnage: public QGraphicsItem
{

public:
   enum Direction {
       NoMove,
       MoveLeft,
       MoveRight,
       MoveUp,
       MoveDown
   };
   enum Position{
       Left,
       Right,
       Up,
       Down
   };

   //constructeur(defaut ,parametre,copie)// destructeur
    Personnage();
    Personnage(qreal x,qreal y);
    Personnage(QPixmap foto,QString nom, int vitesse, int force,int vie,qreal x, qreal y,bool alive);
    Personnage(Personnage &P);
    ~Personnage();

    //Setteur
    void    set_Foto(QPixmap foto);
    void    set_Alive(bool alive);
    void    set_Speed(int vitesse);
    void    set_Force(int puissance);
    void    set_NomMonstre(QString nom);
    void    set_Vie(int vie);
    void    set_X(int x);
    void    set_Y(int y);
    void    setMoveDirection(Direction direction);
    void    setPosition(Position position);
    //fonction
    void    Perso_IS_Dead();
    void    Lose_Life(int lose);
    void    Ma_Position();

    //Getteur
    QPixmap get_Foto();
    bool    get_Alive();
    int     get_Speed();
    int     get_Force();
    QString get_NomMonstre();
    int     get_Vie();
    int     get_X();
    int     get_Y();
    Direction getDirection();
    Position getPosition();
    void    moveLeft();
    void    moveRight();
    void    moveUp();
    void    moveDown();

protected:
   int            _Speed;   //vitesse
   int            _Force;   //force
   int            _Vie;     //point de vie
   bool           _Alive;   //est il encore en vie?
   qreal          _x;       //abs
   qreal          _y;       //Ord
   QString        _NomPersonnage;
   QPixmap        _Foto;
   Direction      moveDirection;
   Position       Yourposition;


};

#endif // PERSONNAGE_H
