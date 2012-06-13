/**
 * \file complexe.h
 * \brief Calculatrice en polonais inversé. Classe composite de gestion des complexes.
 * \author Aurélien DUMAINE
 * \author Simon LANCELOT
 * \version 0.1
 * \date juin 2012
 *
 * Licence : GNU/GPL version 3 (http://www.gnu.org/copyleft/gpl.html)
  * Dépot Git : http://code.google.com/p/lo21-npi/
 *
 */

#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "constante.h"
#include "entier.h"

class Complexe : public Constante{
    //attention _reel et _imaginaire doivent être de type constante
    Constante* _reelle;
    Constante* _imaginaire;

public:
    Complexe():_reelle(new Entier(0)), _imaginaire(new Entier(0)){}
    Complexe(Constante* r, Constante* i);
    //virtual ~Complexe(){delete(_reelle); delete (_imaginaire);}
    //virtual ~Complexe(){}
    virtual QString afficher() const;
    Constante* getPartieReelle() const {return _reelle;}
    Constante* getPartieImaginaire() const {return _imaginaire;}
    void setReelle(Constante* re){_reelle=re;}
    void setImaginaire(Constante* im){_imaginaire=im;}

    Complexe(Constante* c);
    //Complexe* conjugue(Complexe* c);
    //Constante* module(Complexe* c);
    //Constante* argument(Complexe* c);

    virtual Constante* addition(Constante* c);
    virtual Constante* produit(Constante *c);
    virtual Constante* division(Constante* c);
    virtual Constante* signe();
    virtual Constante* soustraction(Constante* c);
    virtual Constante* inv();
    virtual Constante* fact();
    virtual Constante* sinus(bool angle);
    virtual Constante* cosinus(bool angle);
    virtual Constante* sinush(bool angle);
    virtual Constante* cosinush(bool angle);
    virtual Constante* tangente(bool angle);
    virtual Constante* tangenteh(bool angle);
    virtual Constante* logN();
    virtual Constante* log1();
    virtual Constante* puissance(Constante* c);
    virtual Constante* carre();
    virtual Constante* cube();
    virtual Constante* racine();
};

class FrabriqueComplexe : public Complexe{
public:
    Complexe fabriquer();
};

#endif // COMPLEXE_H
