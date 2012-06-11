/**
 * \file entier.h
 * \brief Calculatrice en polonais inversé. Classe Entier.
 * \author Aurélien DUMAINE
 * \author Simon LANCELOT
 * \version 0.1
 * \date juin 2012
 *
 * Licence : GNU/GPL version 3 (http://www.gnu.org/copyleft/gpl.html)
 * Dépot Git : http://code.google.com/p/lo21-npi/
 *
 */
#ifndef ENTIER_H
#define ENTIER_H

#include "constante.h"

class Entier : public Constante{
    int _valeur;

public:
    Entier(int e):_valeur(e){}
    Entier(Constante* c);
    virtual ~Entier(){}
    virtual QString afficher() const{ return QString::number(_valeur);}
    int getValeur() const {return _valeur;}
    void setValeur(int v){_valeur=v;}

    virtual Constante* addition(Constante* c);
    virtual Constante* produit(Constante *c);
    virtual Constante* signe();
    virtual Constante* division(Constante* c);
    virtual Constante* soustraction(Constante* c);
    int mod(Entier *c);
    virtual Constante* fact();
    virtual Constante* inv();
    virtual Constante* sinus(bool angle);
    virtual Constante* cosinus(bool angle);
    virtual Constante* sinush(bool angle);
    virtual Constante* cosinush(bool angle);

};

#endif // ENTIER_H
