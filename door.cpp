#include "door.h"
#include <QPainter>
#include "constants.h"

static const qreal WALL_RADIUS = 100;

Door::Door(qreal x, qreal y, QString adresseTexture, QString nextLevel, GameObjectTypes type, int dim, qreal _x, qreal _y) : Element(x,y,adresseTexture, type, dim)
{
    Element(x,y, adresseTexture, type, dim);
    this->nextLevel=nextLevel;
    this->xNextLevel = _x;
    this->yNextLevel = _y;
}

QString Door::getNextLevel()
{
    return this->nextLevel;
}

qreal Door::get_xNextLevel()
{
    return this->xNextLevel;
}

qreal Door::get_yNextLevel()
{
    return this->yNextLevel;
}

