#ifndef ELEMENT_H
#define ELEMENT_H


#include <QMap>
#include <QString>

class Element
{
    public :
        Element();
};

class Rail : public Element
{
public:
    Rail(const QMap<QString,QString>& param);
};


class Noeud : public Element
{

public:
Noeud(const QMap<QString,QString>& param)
    {
    }

};


class NoeudEntree : public Element
{
public:
NoeudEntree(const QMap<QString,QString>& param)
    {
    }

};


class NoeudSortie : public Element
{
public:

NoeudSortie(const QMap<QString,QString>& param)
    {
    }

};


class Tapis : public Element
{
public:

Tapis(const QMap<QString,QString>& param)
    {
    }

};


class Chariot : public Element
{
public:
Chariot(const QMap<QString,QString>& param)
    {
    }

};


class Bagage : public Element
{
public:
Bagage(const QMap<QString,QString>& param)
    {
    }

};


class Evenement : public Element
{
public:
    Evenement(const QMap<QString,QString>& param)
    {
    }

};


class AiguillageY : public Element
{
public:
AiguillageY(const QMap<QString,QString>& param)
    {
    }

};


class AiguillageA : public Element
{
public:
AiguillageA(const QMap<QString,QString>& param)
    {
    }

};

#endif // ELEMENT_H
