#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "constante.h"



class Expression : public Constante
{
    QString _expr;
public:
    Expression(QString s);
    //virtual ~Expression(){}
    QString getExpr() const {return _expr;}
    void setExpr(QString e){ _expr = e;}
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
    virtual Constante* puissance(Constante *c);
    virtual Constante* carre();
    virtual Constante* cube();
    virtual Constante* racine();
    virtual QString afficher() const;
};
#endif // EXPRESSION_H
