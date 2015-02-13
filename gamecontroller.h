#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QTimer>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QList>
#include <iostream>

#include <QGraphicsPixmapItem>
class QGraphicsScene;
class QKeyEvent;

class Zelda;
class Bonus;
class Element;
class Wall;
class Door;
class Link;
class Monstre;

class GameController : public QObject
{
    Q_OBJECT
public:
    GameController(QGraphicsScene &scene, QObject *parent = 0);
    ~GameController();
    void Game();
    void gameOver();
    void WinGame();
    void Pause();
    void Reprise();
    void ClearLevel();
    void LoadLevel(QString fileName);
    void ZeldaHitWall(Zelda *zelda, Element *wall);
    void ZeldaHitDoor(Door *door);
    void ZeldaHitMonstre(Zelda *zelda, Monstre *monstre);
    void ZeldaHitBonus(Bonus *bonus);
    void DecorCollisions();
    void affichage();
    int pause;

public slots:

    void resume();
    void NewGame();

protected:
    bool eventFilter(QObject *object, QEvent *event);
private:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    QTimer timer;
    QGraphicsScene &scene;
    QList<Element *> listElement;
    QList<Door *> listDoor;
    QList<Monstre *> listMonstre;
    QList<Bonus *> listBonus;
    QList<Link *> listPersonage;

    QList<QGraphicsPixmapItem *> listMort;
    Zelda *zelda;
    Link *link;

    QGraphicsPixmapItem* imagePv;
    QPixmap PixampPv;
    QGraphicsPixmapItem* imageNbKill;
    QPixmap PixampNbKill;

};

#endif // GAMECONTROLLER_H
