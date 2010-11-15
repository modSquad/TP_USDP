#ifndef MYXMLHANDLER_H
#define MYXMLHANDLER_H

#include <QtXml/QXmlDefaultHandler>
#include <QTextStream>
#include <QMap>
#include <QVector>

#include "Element.h"


class XmlConfigFactory : public QXmlDefaultHandler
{
public:
    explicit XmlConfigFactory();

    bool startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &attributes);
    bool endElement(const QString &namespaceURI, const QString &localName, const QString &qName);
    bool characters(const QString &str);

    enum NodeName
    {
        ERROR=-1,
        elementName,
        config,
        rail,
        id,
        noeudDebut,
        noeudFin,
        noeud,
        x,
        y,
        noeudSortie,
        tapis,
        noeudEntree,
        chariot,
        refRail,
        bagage,
        refChariot,
        refTapis,
        refNoeudEntree,
        refNoeudSortie,
        description,
        evenenement,
        type,
        date,
        specific,
        k,
        v,
        aiguillageY,
        refDroite,
        refGauche,
        refEntree,
        aiguillageA,
        _COUNT
    };

    static const char* NodeName_String[_COUNT];
    QList<QString> element_list;

private:
    bool innerNode;
    QString nodeText;
    QMap<QString,QString> parameterMap;
    /**
     * @brief Map des types vers les instances.
     */
    QMap<QString,QVector<Element*> > elements;
    void printElement(const QString& qname);
    void buildElement(const QMap<QString,QString>& parameterMap);
};

#endif // MYXMLHANDLER_H
