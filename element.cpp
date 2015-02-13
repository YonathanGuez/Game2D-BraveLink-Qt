#include "element.h"
#include <QPainter>
#include "constants.h"

Element::Element(qreal x, qreal y, QString AdresseTexture, GameObjectTypes type, int dim)
{
    this->setPos(x,y);
    setData(GD_Type, type);
    Texture=QPixmap(AdresseTexture);
    taille = dim;
}

QRectF Element::boundingRect() const
{
    return QRectF(-taille/2,-taille/2, taille, taille );
}

void Element::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::NoBrush);
    painter->drawPixmap(-taille/2, -taille/2, Texture);

}
