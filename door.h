#ifndef DOOR_H
#define DOOR_H

#include <QString>
#include "element.h"
#include <constants.h>

class Door : public Element
{

public:
    Door(qreal x, qreal y, QString adresseTexture, QString nextLevel, GameObjectTypes type, int dim, qreal _xNextLevel, qreal _yNextLevel);
    QString getNextLevel();
    qreal get_xNextLevel();
    qreal get_yNextLevel();

private:
    QString nextLevel;
    qreal xNextLevel;
    qreal yNextLevel;
};


#endif // DOOR_H
