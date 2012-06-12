#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H
#include <QtGui>
#include <exception>

/*********CODES ERREUR
1,"Division par zéro", important
2,"La fonction X n'est pas implémentée pour les Y.", moyen
3,"Type de constante non prévu dans la fonction Constante* Reel::soustraction(Constante* c).", important
5,"Nombre d'opérandes  dans la pile insuffisant.", moyen
6,"La chaine saisie est invalide", moyen
**********/

enum niveau {faible, moyen, important};
using namespace std;

class LogMessage: public exception
{
    int m_numero;               // Numéro de l'erreur.
    string m_phrase;            // Description de l'erreur.
    enum niveau _level;               // Niveau de l'erreur.

public:
    LogMessage(int numero=0, string const &phrase="", enum niveau lev=faible) throw() : m_numero(numero),m_phrase(phrase),_level(lev){
        QMessageBox msgBox;
        QString contenu(this->what());
        contenu.toUtf8();
        msgBox.setText(contenu);
        msgBox.exec();
    }

     virtual const char* what() const throw()     { return m_phrase.c_str(); }

     virtual const char* getNiveau() const throw()
     {
         if (_level==faible) return "Faible";
         if (_level==moyen) return "Moyen";
         if (_level==important) return "Important";
         return "Niveau inconnu";
     }

    virtual ~LogMessage() throw() {}
};

#endif // LOGMESSAGE_H
