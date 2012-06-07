#ifndef PILE_H
#define PILE_H
#include <iostream>
#include <stack>
#include <vector>
#include "constante.h"
#include "complexe.h"
#include "rationnel.h"

class Pile : public QAbstractListModel
{
    Q_OBJECT
//http://www.java2s.com/Code/Cpp/Qt/stringlistmodelexample.htm
//http://www.developpez.net/forums/d414542/c-cpp/bibliotheques/qt/qabstractitemmodel-qlistview/

private:
    QList<Constante*> p;

public:
    Constante* pop();
    Constante* top(){return p.at(0);}
    void push(Constante* ptr);
    bool isEmpty() const {return p.isEmpty();}
    int size() const {return p.size();}
    Pile(QObject *parent = 0):QAbstractListModel(parent){};
    virtual ~Pile();
    Constante* sum(unsigned int x=2);
    QString afficher() const;

    //surcharge des fonctions virtuelles pures de QAbstractItemModel

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

protected:

    void operator=(const Pile&);
};

#endif // PILE_H
