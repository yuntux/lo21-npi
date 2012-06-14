/**
 * \file calculatrice.h
 * \brief Calculatrice en polonais inversé. Singleton de la calculatrice.
 * \author Aurélien DUMAINE
 * \author Simon LANCELOT
 * \version 0.1
 * \date juin 2012
 *
 * Licence : GNU/GPL version 3 (http://www.gnu.org/copyleft/gpl.html)
 * Dépot Git : http://code.google.com/p/lo21-npi/
 *
 */

#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include "pile.h"
#include "constante.h"
#include "mainwindow.h"
#include <QtGui>

class Calculatrice
{
    static Calculatrice* instance;

    enum MesureAngle _modAngle;
    enum Type _modConstante;
    bool _modComplexe;

    Pile _pileStockage;
    Pile _pileAffichage;
    QList<Pile*> Historique;
    unsigned int indice_pile_actuelle;
    //QList<Pile*>::iterator it_pile_actuelle;

    QSettings* context;

    //void saveToFile();
    //void loadFromFile();

protected:
    Calculatrice();  // à mettre dans la partie privée pour en interdire l'utilisationv
    Calculatrice(const Calculatrice&){}
    virtual ~Calculatrice(); // à mettre dans la partie privée pour en interdire l'utilisationv
    void operator=(const Calculatrice &);  // non défini mais à mettre dans la partie privée pour en interdire l'utilisation
public:
    static Calculatrice& getInstance();
    static void libereInstance();

    void annuler();
    void retablir();
    Pile* getPileStockage() {return Historique[indice_pile_actuelle];}
    int taille_pile_hitorique() {return Historique.size();}
    void afficher_toutes_piles_hitorique();

    void saisie_nouvelle_pile(Pile* nouvelle);

    //Pile* getPileStockage() {return &_pileStockage;} //anvant l'itérateur
    Pile* getPileAffichage() {return &_pileAffichage;}
    enum MesureAngle getMesureAngle() const {return _modAngle;}
    enum Type getModConstante() const {return _modConstante;}
    bool getModComplexe() const {return _modComplexe;}
    QSettings* getContext() const {return context;}
    void setModConstante(enum Type t){_modConstante = t; context->setValue("ModeConstante", _modConstante);}
    void setMesureAngle(enum MesureAngle a){_modAngle = a;}
    void setModComplexe(bool c){_modComplexe = c;}
};

#endif // CALCULATRICE_H
