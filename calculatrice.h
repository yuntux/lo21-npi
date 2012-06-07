/**
 * \file calculatrice.h
 * \brief Calculatrice en polonais inversé. Singleton de la calculatrice.
 * \author Aurélien DUMAINE
 * \author Simon LANCELOT
 * \version 0.1
 * \date juin 2012
 *
 * Licence : GNU/GPL version 3 (http://www.gnu.org/copyleft/gpl.html)
 *
 */

#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include "pile.h"
#include "constante.h"
#include "mainwindow.h"

class Calculatrice
{
    static Calculatrice* instance;

    enum MesureAngle _modAngle;
    enum Type _modConstante;
    bool _modComplexe;

    Pile _pileStockage;
    Pile _pileAffichage;

    Pile* getPileStockage() {return &_pileStockage;}
    Pile* getPileAffichage() {return &_pileAffichage;}
    enum MesureAngle getMesureAngle() const {return _modAngle;}
    enum Type getModConstante() const {return _modConstante;}
    bool getModComplexe() const {return _modComplexe;}
    void setModConstante(enum Type t){_modConstante = t;}
    void setMesureAngle(enum MesureAngle a){_modAngle = a;}
    void setModComplexe(bool c){_modComplexe = c;}
    //void saveToFile();
    //void loadFromFile();

protected:
    Calculatrice();  // à mettre dans la partie privée pour en interdire l'utilisationv
    Calculatrice(const Calculatrice&);  // non défini mais à mettre dans la partie privée pour en interdire l'utilisation
    virtual ~Calculatrice(); // à mettre dans la partie privée pour en interdire l'utilisationv
    void operator=(const Calculatrice &);  // non défini mais à mettre dans la partie privée pour en interdire l'utilisation
public:
    static Calculatrice& getInstance();
    static void libereInstance();
};

#endif // CALCULATRICE_H
