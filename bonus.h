#ifndef BONUS_H
#define BONUS_H
#include <QString>
#include "element.h"
#include <constants.h>
#include <QString>

class Bonus : public Element
{

public:
    Bonus(qreal x, qreal y, QString adresseTexture, GameObjectTypes type, int dim, QString typeBonus);
    QString get_typeBonus();

private:
    QString typeBonus;
};

#endif // Bonus_H
