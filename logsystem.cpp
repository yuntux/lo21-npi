#include "logsystem.h"
#include <QtGui>
#include <iostream>
#include "iostream"

LogSystem* LogSystem::instance=0;

LogSystem& LogSystem::getInstance(){
    if (!instance) instance= new LogSystem();
    return *instance;
}

void LogSystem::libereInstance(){
    delete instance;
}

LogSystem::LogSystem()
{
}

/*
void LogSystem::ConstruireLog_ajouterConsoleEtFichierLog(int numero=0, string const &phrase="", enum niveau lev=faible){
    LogMessage* m = new LogMessage(numero, phrase, niveau);
    this->ajouterConsoleLog(*m);
    this->ajouterFichierLog(*m);
}
*/
void LogSystem::ajouterFcihierEtConsole(LogMessage m){
    this->ajouterConsoleLog(m);
    this->ajouterFichierLog(m);
}

void LogSystem::ajouterFichierLog(LogMessage m){
    QFile file("log");
    //if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
    if (!file.open(QIODevice::ReadWrite)) {
        //QMessageBox::information(this, QObject::tr("Impossible d'ouvrir le fichier."), file.errorString());
        return;
    }

    //on parcourt le fichier pour ajouter à la fin
     while (!file.atEnd()) {
         QString line = file.readLine();
     }

    QTextStream out(&file);
    out<< m.what();
    out<<" \n";
    file.close();
    /**
      * \brief Ajouter Fichier Log
      * \details On parcourt le fichier pour ajouter à la fin
      * \param m Un LogMessage
      */
}

void LogSystem::ajouterConsoleLog(LogMessage m){
    cerr << "MESSAGE DE LOG : " << m.what() << endl;
    /**
      * \brief Ajouter Console Log
      * \details On affiche le message sur la sotir standard d'erreur.
      */
}
