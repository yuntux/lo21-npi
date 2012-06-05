#include "pile.h"

using namespace std;

/*
int Pile::rowCount(const QModelIndex &parent) const { return p.size();}
int Pile::columnCount(const QModelIndex &parent) const {return createIndex(0,0);}
QModelIndex Pile::parent(const QModelIndex &child) const{ return createIndex(0, 0);}
QModelIndex Pile::index(int row, int column, const QModelIndex &parent = QModelIndex()) const{ return creanteIndex(row, column);}
}

QVariant Pile::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >=  p.size())
        return QVariant();

    if (role == Qt::DisplayRole)
        return p.at(index.row());
    else
        return QVariant();
}

QVariant Pile::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return QString("Column %1").arg(section);
    else
        return QString("Row %1").arg(section);
}

Qt::ItemFlags Pile::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool Pile::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        p.replace(index.row(), value.toString());
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

bool Pile::insertRows(int position, int rows, const QModelIndex &parent)
{
    beginInsertRows(QModelIndex(), position, position+rows-1);
    for (int row = 0; row < rows; ++row) {
        p.insert(position, "");
    }
    endInsertRows();
    return true;
}

bool Pile::removeRows(int position, int rows, const QModelIndex &parent)
{
    beginRemoveRows(QModelIndex(), position, position+rows-1);
    for (int row = 0; row < rows; ++row) {
        p.removeAt(position);
    }
    endRemoveRows();
    return true;
}
*/
Pile::~Pile()
{
//FIXME
}

QString Pile::afficher() const {
    //FIXME : affichage ne devrait pas DETRUIRE LA PILE !
    /*QString pile;
    pile = pile + "### DEBUT PILE###\n";
    QStack<Constante*> copie(this->p);
    while (!copie.isEmpty())
         pile = pile + copie.pop()->afficher() + "\n";
    pile = pile + "### FIN PILE###";
    return pile;
    */
    QString string_pile;
    string_pile = string_pile + "### DEBUT PILE###\n";

    for(int i=0; i<p.size(); i++){
        string_pile = string_pile + p.at(i)->afficher() + "\n";
    }
    string_pile = string_pile + "### FIN PILE###";
    return string_pile;
}

Constante* Pile::pop()
{
    if (!p.isEmpty()) {
        Constante* tmp = p.at(0);
        p.removeAt(0);
        return tmp;
    } else {
        return NULL;
    }
}

/*Constante* Pile::top()
{
    return p.top;

}*/

Constante* Pile::sum(unsigned int x)
{
    /*
    Constante* res= new Complexe;
    res = 0;
    for(int i=0;i<x;i++)
    {
        res=res->addition(top());
        this->pop();
    }
    this->push(res);
    return res;
    */
}
