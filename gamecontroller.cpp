#include <QEvent>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include "gamecontroller.h"
#include "element.h"
#include "zelda.h"
#include "monstre.h"
#include "bonus.h"
#include "goumba.h"
#include "sonic.h"
#include "link.h"
#include "boss.h"
#include "door.h"
#include <QTimer>

GameController::GameController(QGraphicsScene &scene, QObject *parent) :
    QObject(parent),
    scene(scene),
    zelda(new Zelda(*this))
{

    timer.start(1000/33);

    this->Game();
    scene.installEventFilter(this);

    this->resume();
}
GameController::~GameController()
{
}
void GameController::Game()
{
    LoadLevel(":new/new/niveau/level1.txt");
    zelda->setPos(150,150);
    zelda->set_X(150);
    zelda->set_Y(150);
    scene.addItem(zelda);
    pause=0;
    PixampPv.load(":/new/new/images/coeur5.png");
    imagePv = scene.addPixmap(PixampPv);
    imagePv->setPos(10,570);
    imagePv->setZValue(10);

}

void GameController::resume()
{
    connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
}


void GameController::gameOver()
{
    QPixmap GameOver=QPixmap(":/new/new/images/GameOver.png");
    scene.addPixmap(GameOver);
}
void GameController::WinGame()
{
    QPixmap WinGame=QPixmap(":/new/new/images/WinGame.png");
    scene.addPixmap(WinGame);
}
void GameController::NewGame()
{
    scene.clear();
    zelda=new Zelda(*this);
    Game();
}

void GameController::Pause()
{
    timer.stop();
    pause=1;

}
void GameController::Reprise()
{
    timer.start();
    pause=0;
}

//Les Deplacements du personnage
void GameController::keyPressEvent(QKeyEvent *event)
{

    switch (event->key())
    {
        case Qt::Key_Left:
            qDebug()<<"gauche";
            zelda->setMoveDirection(Zelda::MoveLeft);
            zelda->setPosition(Zelda::Left);
            zelda->setPhotoAttaque(zelda->getAttaque(),zelda->getPosition());

            break;
        case Qt::Key_Right:
            qDebug()<<"droite";
            zelda->setMoveDirection(Zelda::MoveRight);
            zelda->setPosition(Zelda::Right);
            zelda->setPhotoAttaque(zelda->getAttaque(),zelda->getPosition());
            break;
        case Qt::Key_Up:
            qDebug()<<"haut";
            zelda->setMoveDirection(Zelda::MoveUp);
            zelda->setPosition(Zelda::Up);
            zelda->setPhotoAttaque(zelda->getAttaque(),zelda->getPosition());
            break;
        case Qt::Key_Down:
            qDebug()<<"bas";
            zelda->setMoveDirection(Zelda::MoveDown);
            zelda->setPosition(Zelda::Down);
            zelda->setPhotoAttaque(zelda->getAttaque(),zelda->getPosition());
            break;
        case Qt::Key_4:
           qDebug()<<"gauche";
            zelda->setMoveDirection(Zelda::MoveLeft);
            zelda->setPosition(Zelda::Left);
            zelda->setPhotoAttaque(zelda->getAttaque(),zelda->getPosition());
          break;
        case Qt::Key_6:
            qDebug()<<"droite";
            zelda->setMoveDirection(Zelda::MoveRight);
            zelda->setPosition(Zelda::Right);
            zelda->setPhotoAttaque(zelda->getAttaque(),zelda->getPosition());
             break;
        case Qt::Key_8:
            qDebug()<<"haut";
            zelda->setMoveDirection(Zelda::MoveUp);
            zelda->setPosition(Zelda::Up);
            zelda->setPhotoAttaque(zelda->getAttaque(),zelda->getPosition());
            break;
        case Qt::Key_5:
            qDebug()<<"bas";
            zelda->setMoveDirection(Zelda::MoveDown);
            zelda->setPosition(Zelda::Down);
            zelda->setPhotoAttaque(zelda->getAttaque(),zelda->getPosition());
            break;
        case Qt::Key_W:
            qDebug()<<"attaque 1";
            if(zelda->get_Be_Arme1()==true)
            {
                zelda->setgiveAttaque(Zelda::Cut);
                zelda->set_X(zelda->get_X()+1);
                zelda->set_Y(zelda->get_Y()+1);
            }
            zelda->setPhotoAttaque(zelda->getAttaque(),zelda->getPosition());
            break;
        case Qt::Key_X:
            qDebug()<<"attaque 2";
            if(zelda->get_Be_Arme2()==true)
            {
                zelda->setgiveAttaque(Zelda::Defance);
                zelda->set_X(zelda->get_X()+1);
                zelda->set_Y(zelda->get_Y()+1);
            }
            zelda->setPhotoAttaque(zelda->getAttaque(),zelda->getPosition());
            break;
        case Qt::Key_A:
            qDebug()<<"Nouveau jeu";
            if(zelda->get_Alive()==false)
            {
                QTimer::singleShot(0, this, SLOT(NewGame()));
                break;
            }
            else
                break;
        case Qt::Key_P:
             if(pause == 0)
             {
                this->Pause();
             }
             else if(pause == 1)
             {
                 this->Reprise();
             }
        default:
            break;
    }
}

//quand le bouton est relacher
void GameController::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Left:
            zelda->setMoveDirection(Zelda::NoMove);
            zelda->setPosition(Zelda::Left);
            zelda->setPhotoAttaque(zelda->getAttaque(),zelda->getPosition());
            break;
        case Qt::Key_Right:
            zelda->setMoveDirection(Zelda::NoMove);
            zelda->setPosition(Zelda::Right);
            zelda->setPhotoAttaque(zelda->getAttaque(),zelda->getPosition());
            break;
        case Qt::Key_Up:
            zelda->setMoveDirection(Zelda::NoMove);
            zelda->setPosition(Zelda::Up);
            zelda->setPhotoAttaque(zelda->getAttaque(),zelda->getPosition());
            break;
        case Qt::Key_Down:;
            zelda->setMoveDirection(Zelda::NoMove);
            zelda->setPosition(Zelda::Down);
            zelda->setPhotoAttaque(zelda->getAttaque(),zelda->getPosition());
            break;
        case Qt::Key_4:
            zelda->setMoveDirection(Zelda::NoMove);
            zelda->setPosition(Zelda::Left);
            zelda->setPhotoAttaque(zelda->getAttaque(),zelda->getPosition());
            break;
        case Qt::Key_6:
            zelda->setMoveDirection(Zelda::NoMove);
            zelda->setPosition(Zelda::Right);
            zelda->setPhotoAttaque(zelda->getAttaque(),zelda->getPosition());
            break;
        case Qt::Key_8:
            zelda->setMoveDirection(Zelda::NoMove);
            zelda->setPosition(Zelda::Up);
            zelda->setPhotoAttaque(zelda->getAttaque(),zelda->getPosition());
            break;
        case Qt::Key_5:;
            zelda->setMoveDirection(Zelda::NoMove);
            zelda->setPosition(Zelda::Down);
            zelda->setPhotoAttaque(zelda->getAttaque(),zelda->getPosition());
            break;
        case Qt::Key_W:
            qDebug()<<"attaque 1";
            if(zelda->get_Be_Arme1()==true)
            {
                zelda->set_X(zelda->get_X()-1);
                zelda->set_Y(zelda->get_Y()-1);
            }
            zelda->setgiveAttaque(Zelda::Nothink);
            zelda->setPhotoAttaque(Zelda::Nothink,zelda->getPosition());
            break;
        case Qt::Key_X:
            qDebug()<<"attaque 2";
            if(zelda->get_Be_Arme2()==true)
            {
                zelda->set_X(zelda->get_X()-1);
                zelda->set_Y(zelda->get_Y()-1);
            }
            zelda->setgiveAttaque(Zelda::Nothink);
            zelda->setPhotoAttaque(Zelda::Nothink,zelda->getPosition());
            break;
        default:
           zelda->setMoveDirection(Zelda::NoMove);
           zelda->setgiveAttaque(Zelda::Nothink);
           zelda->setPhotoAttaque(zelda->getAttaque(),zelda->getPosition());
           break;
    }
}

bool GameController::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::KeyPress)
    {
        keyPressEvent((QKeyEvent *)event);
        return true;
    }
    if(event->type() == QEvent::KeyRelease)
    {
        keyReleaseEvent((QKeyEvent *)event);
        return true;
    }
    else
    {
        return QObject::eventFilter(object, event);
    }
}

void GameController::affichage()
{
    int pv = zelda->get_Vie();
    int nb = zelda->get_Tuer();
    scene.removeItem(imagePv);
    scene.removeItem(imageNbKill);
    if(zelda->get_Alive())
    {
        if( pv>=50 ){ PixampPv.load(":/new/new/images/coeur6.png"); }
        else if( pv<50 && pv>=40 ) { PixampPv.load(":/new/new/images/coeur5.png"); }
        else if( pv<40 && pv>=30 ) { PixampPv.load(":/new/new/images/coeur4.png"); }
        else if( pv<30 && pv>=20 ) { PixampPv.load(":/new/new/images/coeur3.png"); }
        else if( pv<20 && pv>=10 ) { PixampPv.load(":/new/new/images/coeur2.png"); }
        else if( pv<10 && pv>=1 ) { PixampPv.load(":/new/new/images/coeur1.png"); }
        else {}
        imagePv = scene.addPixmap(PixampPv);
        imagePv->setPos(10,570);
        imagePv->setZValue(10);
        if( nb>=10 ){ PixampNbKill.load(":/new/new/images/thDead8.png"); }
        else if( nb<10 && nb>=8 ) { PixampNbKill.load(":/new/new/images/thDead7.png"); }
        else if( nb<8 && nb>=6 ) { PixampNbKill.load(":/new/new/images/thDead6.png"); }
        else if( nb<6 && nb>=4 ) { PixampNbKill.load(":/new/new/images/thDead5.png"); }
        else if( nb<4 && nb>=2 ) { PixampNbKill.load(":/new/new/images/thDead3.png"); }
        else if( nb<2 && nb>=0 ) { PixampNbKill.load(":/new/new/images/thDead1.png"); }
        else {}
        imageNbKill = scene.addPixmap(PixampNbKill);
        imageNbKill->setPos(560,560);
        imageNbKill->setZValue(10);
    }
}


void GameController::ZeldaHitWall(Zelda *zelda, Element *wall)
{

    if(zelda->getDirection() == Zelda::MoveUp)
    {
        zelda->moveDown();
    }
    else if (zelda->getDirection() == Zelda::MoveRight)
    {
        zelda->moveLeft();
    }
    else if (zelda->getDirection() == Zelda::MoveLeft)
    {
        zelda->moveRight();
    }
    else if (zelda->getDirection() == Zelda::MoveDown)
    {
        zelda->moveUp();
    }
    else {}
}
////////////////////////////////Zelda touche la porte ////////////////////////
void GameController::ZeldaHitDoor(Door *door)
{
    qreal tmp_x, tmp_y;
    tmp_x = door->get_xNextLevel();
    tmp_y = door->get_yNextLevel();
    ClearLevel();
    LoadLevel(door->getNextLevel());
    zelda->setPos(tmp_x,tmp_y);
    zelda->set_X(tmp_x);
    zelda->set_Y(tmp_y);
}
/////////////////////////////////Zelda contre le Monstre //////
void GameController::ZeldaHitMonstre(Zelda *zelda, Monstre *monstre)
{
    if ((zelda->getAttaque() == Zelda::Cut)||(zelda->getAttaque() == Zelda::Defance))
    {
        if(monstre->get_Alive()== false)
        {//si le monstre est tué alors on le supprime de la scène.
            QPixmap tmpPixmap =(monstre->get_Foto());
            QGraphicsPixmapItem* tmpdead;
            tmpdead = scene.addPixmap(tmpPixmap);
            tmpdead->setPos(monstre->get_X(),monstre->get_Y());
            tmpdead->setZValue(-1);
            listMort << tmpdead;
            scene.removeItem(monstre);
            this->zelda->set_Tuer();
        }
        else
        {
            monstre->Lose_Life(zelda->get_Force());
        }

    }
    else if(zelda->getDirection() == Zelda::MoveUp)
    {
            zelda->setMoveDirection(Zelda::MoveDown);
            zelda->Lose_Life(monstre->get_Force());
    }
    else if (zelda->getDirection() == Zelda::MoveRight)
    {
            zelda->setMoveDirection(Zelda::MoveLeft);
            zelda->Lose_Life(monstre->get_Force());
    }
    else if (zelda->getDirection() == Zelda::MoveLeft)
    {
            zelda->setMoveDirection(Zelda::MoveRight);
            zelda->Lose_Life(monstre->get_Force());
    }
    else if (zelda->getDirection() == Zelda::MoveDown)
    {
            zelda->setMoveDirection(Zelda::MoveUp);
            zelda->Lose_Life(monstre->get_Force());
    }
    else if(zelda->getDirection() == Zelda::NoMove)
    {
            zelda->setMoveDirection(Zelda::NoMove);
            zelda->Lose_Life(monstre->get_Force());
    }
    else{}
    affichage();
}
void GameController::ZeldaHitBonus(Bonus *bonus)
{

    QString tmpBonus;
    tmpBonus = bonus->get_typeBonus();
    if(tmpBonus == "sciseaux")
    {
        zelda->set_Be_Arme1(true);
         scene.removeItem(bonus);
    }
    else if(tmpBonus == "extinct")
    {
        zelda->set_Be_Arme2(true);
        scene.removeItem(bonus);
    }
    else if(tmpBonus == "coeur")
    {
        zelda->set_Vie(zelda->get_Vie()+10);
////////////////Rajoute/////////////////////////////////////////////
        qDebug()<<" Zelda a maintenent  "<<zelda->get_Vie()<<" de vie";
        QPixmap tmpPixmap =(QPixmap(":/new/new/images/vieplus.png"));
        QGraphicsPixmapItem* tmp;
        tmp = scene.addPixmap(tmpPixmap);
        tmp->setPos(bonus->x(),bonus->y());
        listMort << tmp;
        affichage();
//////////////////////////////////////////////////////////////
        scene.removeItem(bonus);
    }
    else if(tmpBonus == "feuille")
    {
        if(zelda->getAttaque()==Zelda::Cut)
        {
            if(zelda->get_Speed()==1 || zelda->get_Speed()==2)
            {
                //ne rien faire il faut continuer �  pouvoir se déplacer
            }
            else zelda->set_Speed(zelda->get_Speed()-1);
////////////////Rajoute/////////////////////////////////////////////
            qDebug()<<" Zelda a maintenent  "<<zelda->get_Speed()<<" de vitesse";
            QPixmap tmpPixmap =(QPixmap(":/new/new/images/vitessemoins.png"));
            QGraphicsPixmapItem* tmp;
            tmp = scene.addPixmap(tmpPixmap);
            tmp->setPos(bonus->x(),bonus->y());
            listMort << tmp;
////////////////////////////////////////////////////////////
        }
        else ZeldaHitWall(zelda,bonus);
    }
////////////////////////Rajout//////////////////////
    else if(tmpBonus == "fire1")
    {
        if(zelda->getAttaque()==Zelda::Defance)
        {
            zelda->set_Speed(zelda->get_Speed()-1);
            qDebug()<<" Zelda a maintenent  "<<zelda->get_Speed()<<" de vitesse car elle c est bruler";
              scene.removeItem(bonus);
        }
        else
        {
            ZeldaHitWall(zelda,bonus);
        }
    }
    else if(tmpBonus == "fire2")
    {
        if((zelda->getAttaque()==Zelda::Defance) && (zelda->get_Tuer() >= 10) && (zelda->get_Tresor() >= 10))
        {

            zelda->set_Speed(zelda->get_Speed()-1);
            qDebug()<<" Zelda a maintenent  "<<zelda->get_Speed()<<" de vitesse car elle c est bruler";
            QPixmap tmpPixmap =(QPixmap(":/new/new/images/vitessemoins.png"));
            QGraphicsPixmapItem* tmp;
            tmp = scene.addPixmap(tmpPixmap);
            tmp->setPos(bonus->x(),bonus->y());
            listMort << tmp;

            scene.removeItem(bonus);
        }
        else
        {
            ZeldaHitWall(zelda,bonus);
            QPixmap tmpPixmap =(QPixmap(":/new/new/images/message.png"));
            QGraphicsPixmapItem* tmp;
            tmp = scene.addPixmap(tmpPixmap);
            tmp->setPos(200,50);
            listMort << tmp;
        }
 ///////////////////////////////////////////////////////
    }
    else if(tmpBonus == "botte")
    {
 ////////////////////Rajout//////////////////////////////
        zelda->set_Speed(zelda->get_Speed()+2);
        qDebug()<<" Zelda a maintenent  "<<zelda->get_Speed()<<" de vitesse";
        QPixmap tmpPixmap =(QPixmap(":/new/new/images/vitesseplus.png"));
        QGraphicsPixmapItem* tmp;
        tmp = scene.addPixmap(tmpPixmap);
        tmp->setPos(bonus->x(),bonus->y());
        listMort << tmp;
        scene.removeItem(bonus);
    }
    else if(tmpBonus == "diamant")
    {
        zelda->set_Tresor();
        qDebug()<<" Zelda a maintenent  "<<zelda->get_Tresor()<<" de vitesse";
        QPixmap tmpPixmap =(QPixmap(":/new/new/images/tresorplus1.png"));
        QGraphicsPixmapItem* tmp;
        tmp = scene.addPixmap(tmpPixmap);
        tmp->setPos(bonus->x(),bonus->y());
        listMort << tmp;
        scene.removeItem(bonus);
    }
 ////////////////////////////////////////////////////////
    else{};
    affichage();
}

void GameController::DecorCollisions()
{
    QList<QGraphicsItem*> collisions = zelda->collidingItems();
    //je vais aussi gerer les collisions du monstre

    foreach (QGraphicsItem *collidingItem,collisions)
    {
        if (collidingItem->data(GD_Type) == GO_Element)
        {
            ZeldaHitWall(zelda,(Element *)collidingItem);
        }
        else if(collidingItem->data(GD_Type) == GO_Monstre)
        {
            ZeldaHitMonstre(zelda,(Monstre *)collidingItem);
            if(zelda->get_Alive()==false)
            {
                this->gameOver();
            }
        }
        else if (collidingItem->data(GD_Type) == GO_Door)
        {
            ZeldaHitDoor((Door *)collidingItem);
        }
        else if (collidingItem->data(GD_Type) == GO_Bonus)
        {
            ZeldaHitBonus((Bonus *)collidingItem);
        }
        else if (collidingItem->data(GD_Type) == GO_Link)
        {//si on touche Link le jeu est terminer
            this->WinGame();
        }
    }

    for(int i=0;i<listMonstre.length();i++)
    {
        foreach (QGraphicsItem *collidingItem2,listMonstre[i]->collidingItems())
        {
            listMonstre[i]->ParcourMonstre(zelda);
            listMonstre[i]->PositionMonstre();//je donne la nouvelle position a mon monstre

        }
    }
}
void GameController::LoadLevel(QString fileName)
{
    QFile fichier(fileName);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream stream(&fichier);

    int PosX, PosY, Z_PosX, Z_PosY,dim;                                     //variables temporaires de position pour construire les objets.

    QString word,adresse;
    while(! stream.atEnd())
    {
        stream >> word;
        if(word =="backGroundBrush")                    //Chargement du fond
        {
            stream >> word;
            scene.setBackgroundBrush(QPixmap(word));
        }
        else if (word == "wall")                        //Chargement des murs
        {
            stream >> PosX;
            stream >> PosY;
            stream >> dim;
            if(dim == 100) { adresse = ":/new/new/images/mur.jpg"; }
            else { adresse = ":/new/new/images/petitmur.jpg"; }
            Element *tmpWall = new Element( PosX, PosY, adresse, GO_Element, dim);
            listElement << tmpWall;
            scene.addItem(tmpWall);
        }
        else if (word == "cloud")                        //Chargement des murs
        {
            stream >> PosX;
            stream >> PosY;
            stream >> dim;
            if(dim == 100) { adresse = ":/new/new/images/cloud.png"; }
            else { adresse = ":/new/new/images/petitcloud.png"; }
            Element *tmpWall = new Element( PosX, PosY, adresse, GO_Element, dim);
            listElement << tmpWall;
            scene.addItem(tmpWall);
        }
        else if (word == "Zelda")                       //Placer le héro
        {
            stream >> PosX;
            stream >> PosY;
            zelda->set_X(PosX);
            zelda->set_Y(PosY);
            zelda->setPos(PosX, PosY);
        }
        else if (word == "water")                       //Chargement de l'eau
        {
            stream >> PosX;
            stream >> PosY;
            stream >> dim;
            if(dim == 100) { adresse = ":/new/new/images/eau.jpg"; }
            else { adresse = ":/new/new/images/petiteau.jpg"; }
            Element *tmpWater = new Element(PosX,PosY,adresse, GO_Element, dim);
            listElement << tmpWater;
            scene.addItem(tmpWater);
        }
        else if (word == "tree")                        //Chargement des arbres
        {
            stream >> PosX;
            stream >> PosY;
            stream >> dim;
            if(dim == 100) { adresse = ":/new/new/images/tree.jpg"; }
            else { adresse = ":/new/new/images/petittree.jpg"; }
            Element *tmpTree = new Element(PosX,PosY,adresse, GO_Element, dim);
            listElement << tmpTree;
            scene.addItem(tmpTree);
        }
        ///////////////////////////
        else if (word == "tree2")                        //Chargement des arbres
        {
            stream >> PosX;
            stream >> PosY;
            stream >> dim;
            if(dim == 100) { adresse = ":/new/new/images/tree2.png"; }
            else { adresse = ":/new/new/images/petitttree2.png"; }
            Element *tmpTree = new Element(PosX,PosY,adresse, GO_Element,dim);
            listElement << tmpTree;
            scene.addItem(tmpTree);
        }
        else if (word == "bois")                        //Chargement des arbres
        {
            stream >> PosX;
            stream >> PosY;
            stream >> dim;
            if(dim == 100) { adresse = ":/new/new/images/bois.png"; }
            else { adresse = ":/new/new/images/petitbois.png"; }
            Element *tmpTree = new Element(PosX,PosY,adresse, GO_Element,dim);
            listElement << tmpTree;
            scene.addItem(tmpTree);
        }
        else if (word == "roche")                        //Chargement des arbres
        {
            stream >> PosX;
            stream >> PosY;
            stream >> dim;
            if(dim == 100) { adresse = ":/new/new/images/roche.png"; }
            else { adresse = ":/new/new/images/petitroche.png"; }
            Element *tmpTree = new Element(PosX,PosY,adresse, GO_Element,dim);
            listElement << tmpTree;
            scene.addItem(tmpTree);
        }
        else if (word == "eiffel")                        //Chargement des arbres
        {
            stream >> PosX;
            stream >> PosY;
            stream >> dim;
            if(dim == 100) { adresse = ":/new/new/images/eiffel.png"; }
            else { adresse = "::/new/new/images/petiteiffel.png"; }
            Element *tmpTree = new Element(PosX,PosY,adresse, GO_Element,dim);
            listElement << tmpTree;
            scene.addItem(tmpTree);
        }
        else if (word == "t1")                        //Chargement des arbres
        {
            stream >> PosX;
            stream >> PosY;
            stream >> dim;
            if(dim == 100) { adresse = ":/new/new/images/T1.png"; }
            else {  }
            Element *tmpTree = new Element(PosX,PosY,adresse, GO_Element,dim);
            listElement << tmpTree;
            scene.addItem(tmpTree);
        }
        else if (word == "t2")                        //Chargement des arbres
        {
            stream >> PosX;
            stream >> PosY;
            stream >> dim;
            if(dim == 100) { adresse = ":/new/new/images/T2.png"; }
            else {  }
            Element *tmpTree = new Element(PosX,PosY,adresse, GO_Element,dim);
            listElement << tmpTree;
            scene.addItem(tmpTree);
        }
        else if (word == "liberte")                        //Chargement des arbres
        {
            stream >> PosX;
            stream >> PosY;
            stream >> dim;
            if(dim == 100) { adresse = ":/new/new/images/liberte.png"; }
            else { adresse = ":/new/new/images/petitliberte.png"; }
            Element *tmpTree = new Element(PosX,PosY,adresse, GO_Element,dim);
            listElement << tmpTree;
            scene.addItem(tmpTree);
        }
        /////////////////////////////////
        else if (word == "fire")                        //Chargement des arbres
        {
            stream >> PosX;
            stream >> PosY;
            stream >> dim;
            if(dim == 100) { adresse = ":/new/new/images/feu.png"; }
            else { adresse = ":/new/new/images/petitfeu.png"; }
            Element *tmpFire = new Element(PosX,PosY,adresse, GO_Element, dim);
            listElement << tmpFire;
            scene.addItem(tmpFire);
        }
        else if(word == "door")                         //Chargement des portes
        {
            stream >> PosX;
            stream >> PosY;
            stream >> dim;
            if(dim == 100) { adresse = ":/new/new/images/door.jpg"; }
            else { adresse = ":/new/new/images/petitdoor.jpg"; }
            stream >> word;
            stream >> Z_PosX;
            stream >> Z_PosY;
            Door *tmpDoor = new Door(PosX,PosY,adresse,word, GO_Door, dim, Z_PosX, Z_PosY);
            listElement << tmpDoor;
            scene.addItem(tmpDoor);
        }
        else if( word == "goumba1")
        {
            stream >> PosX;
            stream >> PosY;
            Goumba *tmpGoumba = new Goumba(PosX,PosY,Monstre::MoveUp);
            listMonstre << tmpGoumba;
            scene.addItem(tmpGoumba);
        }
        else if( word == "goumba2")
        {
            stream >> PosX;
            stream >> PosY;
            Goumba *tmpGoumba = new Goumba(PosX,PosY,Monstre::MoveLeft);
            listMonstre << tmpGoumba;
            scene.addItem(tmpGoumba);
        }
        else if( word == "sonic")
        {
            stream >> PosX;
            stream >> PosY;
            Sonic *tmpSonic = new Sonic(PosX,PosY);
            listMonstre << tmpSonic;
            scene.addItem(tmpSonic);
        }
        else if( word == "boss")
        {
            stream >> PosX;
            stream >> PosY;
            Boss *tmpSonic = new Boss(PosX,PosY);
            listMonstre << tmpSonic;
            scene.addItem(tmpSonic);
        }
        else if(word =="coca")
        {
            stream >> PosX;
            stream >> PosY;
            stream >> dim;
            if(dim == 100) { adresse = ":/new/new/images/CocaCola.png"; }
            else { adresse = ":/new/new/images/CocaCola.png"; }
            stream >> word;
            Bonus *tmpBonus = new Bonus(PosX,PosY,adresse, GO_Bonus, dim,"coeur");
            listBonus << tmpBonus;
            scene.addItem(tmpBonus);
        }
        else if(word == "fire1")
        {
            stream >> PosX;
            stream >> PosY;
            stream >> dim;
            if(dim == 100) { adresse = ":/new/new/images/fire2.png"; }
            else { adresse = ":/new/new/images/petitfire2.png"; }
            stream >> word;
            Bonus *tmpBonus = new Bonus(PosX,PosY,adresse, GO_Bonus, dim,"fire1");
            listBonus << tmpBonus;
            scene.addItem(tmpBonus);
        }
        else if(word == "fire2")
        {
            stream >> PosX;
            stream >> PosY;
            stream >> dim;
            if(dim == 100) { adresse = ":/new/new/images/fire2.png"; }
            else { adresse = ":/new/new/images/petitfire2.png"; }
            stream >> word;
            Bonus *tmpBonus = new Bonus(PosX,PosY,adresse, GO_Bonus, dim,"fire2");
            listBonus << tmpBonus;
            scene.addItem(tmpBonus);
        }

        else if(word == "sciseaux")
        {
            stream >> PosX;
            stream >> PosY;
            stream >> dim;
            adresse = ":/new/new/images/scissors.png";
            stream >> word;
            Bonus *tmpBonus = new Bonus(PosX,PosY,adresse, GO_Bonus, dim, "sciseaux");
            listBonus << tmpBonus;
            scene.addItem(tmpBonus);
        }
        else if(word == "feuille")
        {
            stream >> PosX;
            stream >> PosY;
            stream >> dim;
            if(dim == 100) { adresse = ":/new/new/images/feuille.png"; }
            else { adresse = ":/new/new/images/feuille.png"; }
            stream >> word;
            Bonus *tmpBonus = new Bonus(PosX,PosY,adresse, GO_Bonus, dim, "feuille");
            listBonus << tmpBonus;
            scene.addItem(tmpBonus);
        }
        else if(word == "extinct")
        {
            stream >> PosX;
            stream >> PosY;
            stream >> dim;
            if(dim == 100) { adresse = ":/new/new/images/extinct.png"; }
            else { adresse = ":/new/new/images/petitextinct.png"; }
            stream >> word;
            Bonus *tmpBonus = new Bonus(PosX,PosY,adresse, GO_Bonus, dim,"extinct");
            listBonus << tmpBonus;
            scene.addItem(tmpBonus);
        }
        else if(word == "botte")
        {
            stream >> PosX;
            stream >> PosY;
            stream >> dim;
            if(dim == 100) { adresse = ":/new/new/images/botte.png"; }
            else { adresse = ":/new/new/images/petitbotte.png"; }
            stream >> word;
            Bonus *tmpBonus = new Bonus(PosX,PosY,adresse, GO_Bonus, dim,"botte");
            listBonus << tmpBonus;
            scene.addItem(tmpBonus);
        }
        else if( word == "link")
        {
            stream >> PosX;
            stream >> PosY;
            Link *tmplink = new Link(PosX,PosY);
            listPersonage << tmplink;
            scene.addItem(tmplink);
        }
        else if(word == "diamant")
        {
            stream >> PosX;
            stream >> PosY;
            stream >> dim;
            if(dim == 100) { adresse = ":/new/new/images/diamant.png"; }
            else { adresse = ":/new/new/images/petitdiamant.png"; }
            stream >> word;
            Bonus *tmpBonus = new Bonus(PosX,PosY,adresse, GO_Bonus, dim,"diamant");
            listBonus << tmpBonus;
            scene.addItem(tmpBonus);
        }
        else{}
    }
}
void GameController::ClearLevel()
{
    while(!listMonstre.isEmpty())
    {
        scene.removeItem(listMonstre[0]);
        listMonstre.removeFirst();
    }
    while(!listBonus.isEmpty())
    {
        scene.removeItem(listBonus[0]);
        listBonus.removeFirst();
    }
    while(!listMort.isEmpty())
    {
        scene.removeItem(listMort[0]);
        listMort.removeFirst();
    }
    while(!listPersonage.isEmpty())
    {
        scene.removeItem(listPersonage[0]);
        listPersonage.removeFirst();
    }
    while(!listElement.isEmpty())
    {
        scene.removeItem(listElement[0]);
        listElement.removeFirst();
    }
}
