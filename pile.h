#ifndef PILE_H
#define PILE_H
#include <iostream>
#include <stack>
#include <vector>
#include "constante.h"
#include "complexe.h"
#include "rationnel.h"

class Pile// : public QAbstractItemModel
{
    //Q_OBJECT
//http://www.java2s.com/Code/Cpp/Qt/stringlistmodelexample.htm
//http://www.developpez.net/forums/d414542/c-cpp/bibliotheques/qt/qabstractitemmodel-qlistview/

private:
    //QStack<Constante*> p;
    QList<Constante*> p;

public:
    Constante* pop();
    Constante* top(){return p.at(0);}
    void push(Constante* ptr) {p.push_front(ptr);}
    bool isEmpty() const {return p.isEmpty();}
    int size() const {return p.size();}
    Pile(QObject *parent = 0){};
    ~Pile();
    Constante* sum(unsigned int x=2);
    QString afficher() const;

    //surcharge des fonctions virtuelles pures de QAbstractItemModel
    /*
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    bool insertRows(int position, int rows, const QModelIndex &parent);
    bool removeRows(int position, int rows, const QModelIndex &parent);
    virtual QModelIndex parent(const QModelIndex &child) const;
    virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
*/
protected:

    void operator=(const Pile&);
};

#endif // PILE_H
