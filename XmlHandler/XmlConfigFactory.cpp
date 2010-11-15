#include "XmlConfigFactory.h"

#include <QDebug>

const char* XmlConfigFactory::NodeName_String[] = {
    "elementName",
    "config",
    "rail",
    "id",
    "noeudDebut",
    "noeudFin",
    "noeud",
    "x",
    "y",
    "noeudSortie",
    "noeudEntree",
    "tapis",
    "chariot",
    "refRail",
    "bagage",
    "refChariot",
    "refTapis",
    "refNoeudEntree",
    "refNoeudSortie",
    "description",
    "evenenement",
    "type",
    "date",
    "specific",
    "k",
    "v",
    "aiguillageY",
    "refDroite",
    "refGauche",
    "refEntree",
    "aiguillageA"
};


XmlConfigFactory::XmlConfigFactory()
    :innerNode(false)
{
    element_list.append("rail");
    element_list.append("noeud");
    element_list.append("noeudEntree");
    element_list.append("noeudSortie");
    element_list.append("tapis");
    element_list.append("chariot");
    element_list.append("bagage");
    element_list.append("evenement");
    element_list.append("aiguillageY");
    element_list.append("aiguillageA");
}


bool XmlConfigFactory::startElement(const QString &/*namespaceURI*/,
                                const QString &/*localName*/,
                                const QString &qname,
                                const QXmlAttributes & /*attributes*/)
{
    if(element_list.contains(qname))
    {
        innerNode = true;
    }
    return true;
}


bool XmlConfigFactory::endElement(const QString &/*namespaceURI*/,
                              const QString &/*localName*/,
                              const QString &qname)
{
    if(element_list.contains(qname))
    {
        parameterMap[NodeName_String[elementName]] = qname;
        innerNode = false;
        buildElement(parameterMap);
        parameterMap.clear();
    }
    else
    {
        parameterMap[qname] = nodeText.trimmed();
    }

    nodeText.clear();

    return true;
}

bool XmlConfigFactory::characters(const QString &str)
{
        if( ! str.isEmpty())
                nodeText += str;
        return true;
}

/**
 * For debugging
 */
void XmlConfigFactory::printElement(const QString& qname)
{
    qDebug() << qname << " " << parameterMap;
}


void XmlConfigFactory::buildElement(const QMap<QString,QString>& parameterMap)
{
    printElement(parameterMap[NodeName_String[elementName]]);
    if(parameterMap[NodeName_String[elementName]] =="rail")
    {
        elements[NodeName_String[elementName]].push_back(new Rail(parameterMap));
    }
    else if(parameterMap[NodeName_String[elementName]] == "noeud")
    {
        elements[NodeName_String[elementName]].push_back(new Noeud(parameterMap));

    }
    else if(parameterMap[NodeName_String[elementName]] == "noeudEntree")
    {
        elements[NodeName_String[elementName]].push_back(new NoeudEntree(parameterMap));

    }
    else if(parameterMap[NodeName_String[elementName]] == "noeudSortie")
    {
        elements[NodeName_String[elementName]].push_back(new NoeudSortie(parameterMap));

    }
    else if(parameterMap[NodeName_String[elementName]] == "tapis")
    {
        elements[NodeName_String[elementName]].push_back(new Tapis(parameterMap));

    }
    else if(parameterMap[NodeName_String[elementName]] == "chariot")
    {
        elements[NodeName_String[elementName]].push_back(new Chariot(parameterMap));

    }
    else if(parameterMap[NodeName_String[elementName]] == "bagage")
    {
        elements[NodeName_String[elementName]].push_back(new Bagage(parameterMap));

    }
    else if(parameterMap[NodeName_String[elementName]] == "evenement")
    {
        elements[NodeName_String[elementName]].push_back(new Evenement(parameterMap));

    }
    else if(parameterMap[NodeName_String[elementName]] == "aiguillageY")
    {
        elements[NodeName_String[elementName]].push_back(new AiguillageY(parameterMap));

    }
    else if(parameterMap[NodeName_String[elementName]] == "aiguillageA")
    {
        elements[NodeName_String[elementName]].push_back(new AiguillageA(parameterMap));

    }
}


