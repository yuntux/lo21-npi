#include "expression.h"

Expression::Expression(QString s):_expr(s)
{
    /**
      * \brief Constructeur d'Expression
      * \details On affecte à l'attribut \e _expr la valeur passée en paramètre
      * \param s Une QString
      */
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

Constante* Expression::logN()
{
    return this;
}

Constante* Expression::carre()
{
    return this;
}

Constante* Expression::cube()
{
    return this;
}

Constante* Expression::racine()
{
    return this;
}

Constante* Expression::puissance(Constante *c)
{
    return this;
}

Constante* Expression::log1()
{
    return this;
}
