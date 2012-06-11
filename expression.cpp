#include "expression.h"

Expression::Expression(QString s):_expr(s)
{
}


Constante* Expression::addition(Constante* c)
{
    return c;
}

Constante* Expression::produit(Constante *c)
{
    return c;
}

Constante* Expression::division(Constante* c)
{
    return c;
}

Constante* Expression::signe()
{
    return this;
}

Constante* Expression::soustraction(Constante* c)
{
    return c;
}

Constante* Expression::inv()
{
    return this;
}

Constante* Expression::fact()
{
    return this;
}

Constante* Expression::sinus(bool angle)
{
    return this;
}

Constante* Expression::cosinus(bool angle)
{
    return this;
}

Constante* Expression::sinush(bool angle)
{
    return this;
}

Constante* Expression::cosinush(bool angle)
{
    return this;
}

Constante* Expression::tangente(bool angle)
{
    return this;
}

Constante* Expression::tangenteh(bool angle)
{
    return this;
}

QString Expression::afficher() const
{
    return _expr;
}
