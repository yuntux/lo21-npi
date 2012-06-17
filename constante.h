/**
 * \file constante.h
 * \brief Calculatrice en polonais inversé. Classe composite de gestion des constantes.
 * \author Aurélien DUMAINE
 * \author Simon LANCELOT
 * \version 0.1
 * \date juin 2012
 *
 * Licence : GNU/GPL version 3 (http://www.gnu.org/copyleft/gpl.html)
 * Dépot Git : http://code.google.com/p/lo21-npi/
 *
 */

#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <iostream>
#include <QtGui>
#include "logmessage.h"
#include "logsystem.h"

enum Type {
       entier,
       rationnel,
       reel,
       complexe,
       expression,
    };

class Constante
{
public:
    virtual ~Constante(){};
    virtual QString afficher() const = 0; //afficher est virtuelle pure donc la classe est abstraite
    virtual Constante* addition(Constante* c){throw LogMessage(2,"La fonction LOG n'est pas implémentée pour les complexes.", moyen);}
    virtual Constante* produit(Constante* c){throw LogMessage(2,"La fonction LOG n'est pas implémentée pour les complexes.", moyen);}
    virtual Constante* division(Constante* c){throw LogMessage(2,"La fonction LOG n'est pas implémentée pour les complexes.", moyen);}
    virtual Constante* signe(){throw LogMessage(2,"La fonction LOG n'est pas implémentée pour les complexes.", moyen);}
    Constante* recopie();
    virtual Constante* soustraction(Constante* c){throw LogMessage(2,"La fonction LOG n'est pas implémentée pour les complexes.", moyen);}
    virtual Constante* inv(){throw LogMessage(2,"La fonction LOG n'est pas implémentée pour les complexes.", moyen);}
    virtual Constante* fact(){throw LogMessage(2,"La fonction LOG n'est pas implémentée pour les complexes.", moyen);}
    virtual Constante* sinus(bool angle){throw LogMessage(2,"La fonction LOG n'est pas implémentée pour les complexes.", moyen);}
    virtual Constante* cosinus(bool angle){throw LogMessage(2,"La fonction LOG n'est pas implémentée pour les complexes.", moyen);}
    virtual Constante* sinush(bool angle){throw LogMessage(2,"La fonction LOG n'est pas implémentée pour les complexes.", moyen);}
    virtual Constante* cosinush(bool angle){throw LogMessage(2,"La fonction LOG n'est pas implémentée pour les complexes.", moyen);}
    virtual Constante* tangente(bool angle){throw LogMessage(2,"La fonction LOG n'est pas implémentée pour les complexes.", moyen);}
    virtual Constante* tangenteh(bool angle){throw LogMessage(2,"La fonction LOG n'est pas implémentée pour les complexes.", moyen);}
    virtual Constante* logN(){throw LogMessage(2,"La fonction LOG n'est pas implémentée pour les complexes.", moyen);}
    virtual Constante* log1(){throw LogMessage(2,"La fonction LOG n'est pas implémentée pour les complexes.", moyen);}
    virtual Constante* puissance(Constante* c){throw LogMessage(2,"La fonction LOG n'est pas implémentée pour les complexes.", moyen);}
    virtual Constante* carre(){throw LogMessage(2,"La fonction LOG n'est pas implémentée pour les complexes.", moyen);}
    virtual Constante* cube(){throw LogMessage(2,"La fonction LOG n'est pas implémentée pour les complexes.", moyen);}
    virtual Constante* racine(){throw LogMessage(2,"L'opérateur demandé n'est pas implémenté pour ce type d'opérande.", moyen);}
};

#endif // CONSTANTE_H
