#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "constante.h"

class Expression : public Constante
{
    QString _expr;
public:
    Expression(QString s);
    virtual Constante* addition(Constante* c);
    virtual Constante* produit(Constante *c);
    virtual Constante* division(Constante* c);
    virtual Constante* signe();
    virtual Constante* soustraction(Constante* c);
    virtual Constante* inv();
    virtual Constante* fact();
    virtual Constante* sinus();
    virtual QString afficher() const;
};
#endif // EXPRESSION_H