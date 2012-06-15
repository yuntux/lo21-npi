#include "pile.h"
#include "calculatrice.h"
#include "logsystem.h"
#include "logmessage.h"

using namespace std;

void Pile::push(Constante* ptr) {
    p.push_front(ptr);
    /**
      * \brief Empiler
      * \details Permet d'empiler la Constante entrée en paramètre dans la pile
      * \param ptr Un pointeur de Constante
      */
}

int Pile::rowCount(const QModelIndex &parent) const {
    return p.size();
    /**
     * \brief Compteur Taille
     * \details Permet de connaître la taille d'une pile
     * \param parent Un QModelIndex
     * \return Un entier correspondant à la taille de la pile
     */
}


QVariant Pile::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= this->size())
        return QVariant();

    if (role == Qt::DisplayRole)
        //if (p.at(index.row()))
            //return p.at(index.row())->afficher();
        return p.at(index.row())->afficher(); //renvoyer un QStrigng
    else
        return QVariant();
}


Pile::~Pile()
{
    int s = this->size(); //ATTENTION : il faut bien fixer la taille avant !
    for(int i=0; i<s; i++){
        Constante* tmp = this->pop();
        delete(tmp);
    }
    /**
      * \brief Destructeur de pile
      * \details Destruction de la pile et de chaque membre de cette pile
      */
}

QString Pile::afficher() const {
    QString string_pile;
    string_pile = string_pile + "### DEBUT PILE###\n";

    for(int i=0; i<p.size(); i++){
        string_pile = string_pile + p.at(i)->afficher() + "\n";
    }
    string_pile = string_pile + "### FIN PILE###";
    return string_pile;
    /**
      * \brief Affichage pile
      * \details On affiche chaque élément de la pile en concaténant dans une QString
      * \return Une \e QString correspondant à ce qui se trouve dans la pile
      */
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
    LogMessage msg(0, "Depilement.", tracabilite);
    LogSystem::getInstance().ajouterFcihierEtConsole(msg);
    /**
      * \brief Dépiler
      * \details Tester d'abord si la pile n'est pas vide. Si c'est bon, alors on dépile le premier élément, oorrespondant au dernier ajouté
      * \return Une \e Constante correspondant au dernier élément, ou NULL
      */
}

/*Constante* Pile::top()
{
    return p.top;

}*/

Constante* Pile::sum(unsigned int x)
{
    Constante* res = new Complexe(0);

    for(int i=0;i<x;i++)
    {
        res=res->addition(this->pop());
    }
    this->push(res);
    return res;
    /**
      * \brief Somme sur la pile
      * \details Effectue la somme sur les \a x premiers éléments de la pile, en fonction du paramètre.
      *          Pour cela, on ajoute au résultat (qui est un Complexe) la valeur de l'élément dépilé. On empile ensuite le résultat
      * \param x Entier correspondant au nombre d'éléments à sommer
      * \return Une \e Constante contenant le résultat de la somme
      */
}

Constante* Pile::mean(unsigned int x)
{
    Constante* tmp = this->sum(x);
    Entier e(x);
    return new Complexe(tmp->division(&e));
//    LogMessage msg(0, "Calcul de la moyenne de la pile.", tracabilite);
 //   LogSystem::getInstance().ajouterFcihierEtConsole(msg);
    /**
      * \brief Moyenne sur la pile
      * \details Effectue la moyenne sur les \a x premiers éléments de la pile, en fonction du paramètre.
      *          Pour cela, on appelle la fonction \e sum, puis on divise en fonction du paramètre x
      * \param x Entier correspondant au nombre d'éléments pour la moyenne
      * \return Une \e Constante contenant le résultat de la moyenne
      */
}

void Pile::clear(){
    for(int i=0; i<this->size(); i++){
        Constante* tmp = this->pop();
        delete(tmp);
    }
    LogMessage msg(0, "Suppression de tous les éléments de la liste.", tracabilite);
    LogSystem::getInstance().ajouterFcihierEtConsole(msg);
    /**
      * \brief Vider la pile
      * \details On dépile chaque élément de la pile, en faisant appel à la fonction \e pop
      */
}

void Pile::dup(){
    Constante* tmp = this->p.at(0)->recopie();
    this->push(tmp);
    LogMessage msg(0, "Duplication de la tete de pile.", tracabilite);
    LogSystem::getInstance().ajouterFcihierEtConsole(msg);
    /**
      * \brief Duplication
      * \details Duplication du premier élément de la pile
      */
}

Pile* Pile::copier_pile(){
    Pile* nouv = new Pile();
    for(int i =0; i<p.size(); i++){
        Constante* tmp = p.at(i)->recopie();
        nouv->p.push_back(tmp);
    }
    return nouv;
    /**
      * \brief Copier la pile
      * \details Copie la pile et les éléments qu'elle contient
      */
}

void Pile::drop(){
    Constante* tmp = this->pop();
    delete(tmp);
    LogMessage msg(0, "Suppression tete de pile.", tracabilite);
    LogSystem::getInstance().ajouterFcihierEtConsole(msg);
    /**
      * \brief Suppression premier élément
      * \details Supprimer le premier élément de la pile
      */
}

void Pile::swap(unsigned int x, unsigned int y){
    Constante* tmp1 = p.at(x);
    Constante* tmp2 = p.at(y);
    p[x] = tmp2;
    p[y] = tmp1;
//    LogMessage msg(0, "Inversion des éléments "+x+" et "+y+" de la pile.", tracabilite);
//    LogSystem::getInstance().ajouterFcihierEtConsole(msg);
    /**
      * \brief Échange
      * \details Échange des deux éléments dont les positions sont passées en paramètres
      * \param x Entier, position du premier élément
      * \param y Entier, position du second élément
      */
}


void Pile::sauv_pile_context(){
    int s = this->size();
    for (int i=0; i<s; i++){
        QString libelle("PileStockage/Element"+QString::number(i));
        if (p.at(i)->afficher().count("$")==0)
            //FIXME : bug des complexe dans le .ini => boucle infinie
            Calculatrice::getInstance().getContext()->setValue(libelle, p.at(i)->afficher());
        else
            Calculatrice::getInstance().getContext()->setValue(libelle, "0");
    }
    LogMessage msg(0, "Sauvegarde de la pile dans le fichier ini.", tracabilite);
    LogSystem::getInstance().ajouterFcihierEtConsole(msg);
    /**
      * \brief Sauvegarde de la pile
      * \details Sauvegarde la pile dans le fichier ini
      */
}
