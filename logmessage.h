#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H
#include <QtGui>
#include <exception>

enum niveau {faible, moyen, important};
using namespace std;

class LogMessage: public exception
{
    int m_numero;               // Numéro de l'erreur.
    string m_phrase;            // Description de l'erreur.
    enum niveau _level;               // Niveau de l'erreur.

public:
    LogMessage(int numero=0, string const& phrase="", enum niveau lev=faible) throw() : m_numero(numero),m_phrase(phrase),_level(lev){}

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
