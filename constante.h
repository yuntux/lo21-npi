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

enum Type {
       entier,
       rationnel,
       reel,
       complexe,
       expression,
       //erreur
    };

class Constante
{
public:
    virtual ~Constante(){};
    virtual QString afficher() const = 0;
    virtual Constante* addition(Constante* c)=0;
    virtual Constante* produit(Constante* c)=0;
    virtual Constante* division(Constante* c)=0;
    virtual Constante* signe()=0;
    Constante* recopie();
    virtual Constante* soustraction(Constante* c)=0;
    virtual Constante* inv()=0;
    virtual Constante* fact()=0;
    virtual Constante* sinus(bool angle)=0;
    virtual Constante* cosinus(bool angle)=0;
    virtual Constante* sinush(bool angle)=0;
    virtual Constante* cosinush(bool angle)=0;
};

class FrabriqueConstante{
public:
    //virtual Constante frabriquer()=0;
};

#endif // CONSTANTE_H
