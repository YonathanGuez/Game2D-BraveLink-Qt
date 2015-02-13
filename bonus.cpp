#include "bonus.h"
#include <QPainter>
#include "constants.h"

static const qreal WALL_RADIUS = 100;

Bonus::Bonus(qreal x, qreal y, QString adresseTexture, GameObjectTypes type, int dim, QString typeBonus) : Element(x,y,adresseTexture, type, dim)
{
    Element(x,y, adresseTexture, type, dim);
    setData(GD_Type, GO_Bonus);
    this->typeBonus = typeBonus;
}


QString Bonus::get_typeBonus()
{
    return this->typeBonus;
}
