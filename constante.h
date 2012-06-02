#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <iostream>
#include <QtGui>

enum Type {
       ent,
       rat,
       real,
       comp,
       expr,
       erreur
    };

class Constante
{
public:
    const Type& getType() { return genre; }
    virtual QString afficher() const = 0;
//    virtual Constante* operator+(Constante& c)=0;

protected:
    Type genre;
//    virtual void construireConstante(const std::string&) = 0;
};
    //Constante operator+(Constante* const&a, Constante* const&b);

class FrabriqueConstante{
public:
    //virtual Constante frabriquer()=0;
};

#endif // CONSTANTE_H
