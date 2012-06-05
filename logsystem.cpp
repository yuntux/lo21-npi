#include "logsystem.h"
#include <QtGui>
#include <iostream>

LogSystem::LogSystem()
{
}

void LogSystem::ajouterFichierLog(LogMessage m){
    QFile file("log");
    if (!file.open(QIODevice::WriteOnly)) {
 //       QMessageBox::information(this, QObject::tr("Impossible d'ouvrir le fichier."),
   //         file.errorString());
        return;
    }

    //on parcourt le fichier pour ajouter à la fin
    QString line = file.readLine();
    while (!line.isNull()) {
        line = file.readLine();
    }

    QTextStream out(&file);
    out<< m.getMessage();
}

void LogSystem::ajouterConsoleLog(LogMessage m){
    qDebug() << m.getMessage();
}
