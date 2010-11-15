#include <QtGui/QApplication>

#include <QtXml/QXmlSimpleReader>
#include <QtXml/QXmlInputSource>

#include <QFile>

#include <QDebug>

#include "mainwindow.h"
#include "XmlConfigFactory.h"

int main(int /* argc */, char ** /* argv */)
{
   // QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    XmlConfigFactory handler;
    QXmlSimpleReader reader;
    reader.setContentHandler(&handler);
    reader.setErrorHandler(&handler);

    QFile file("test.xml");
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Cannot read file" << endl;
        return -1;
    }

    QXmlInputSource xmlInputSource(&file);
    if (reader.parse(xmlInputSource))
        qDebug() << "Parse Ok." << endl;
}
