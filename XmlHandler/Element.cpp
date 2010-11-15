#include "Element.h"
#include <QDebug>

Element::Element()
{
    qDebug() << "Element crée :-)";
}

Rail::Rail(const QMap<QString,QString>& param)
:Element()
{

}
