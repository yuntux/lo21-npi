#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "constante.h"



class Expression : public Constante
{
    QString _expr;
public:
    Expression(QString s) :_expr(s){}
    virtual ~Expression(){}
    QString getExpr() const {return _expr;}
    void setExpr(QString e){ _expr = e;}
    virtual QString afficher() const{ return _expr; }
};
#endif // EXPRESSION_H
