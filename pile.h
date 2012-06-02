#ifndef PILE_H
#define PILE_H
#include <iostream>
#include <stack>
#include <vector>
#include "constante.h"
#include "complexe.h"
#include "rationnel.h"

class Pile
{
    QStack<Constante*> p;

public:
    Constante* pop();
    void append(Constante* ptr);
    Constante* top();
    bool isEmpty() const {return p.isEmpty();}
    int size() const {return p.size();}
    Pile();
    ~Pile();
    Constante* sum(unsigned int x=2);

protected:

    void operator=(const Pile&);
};

#endif // PILE_H
