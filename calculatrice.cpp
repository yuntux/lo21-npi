#include "calculatrice.h"
#include <QtGui>
#include "logmessage.h"
#include "logsystem.h"

Calculatrice* Calculatrice::instance=0;
/**
 * \brief Dans un Singleton, nécessité d'avoir une instante de type static

  */

Calculatrice::~Calculatrice(){
    delete(context);
    /**
     * \brief Le destructeur de la classe
      */
}

Calculatrice::Calculatrice() : context(new QSettings("context.ini", QSettings::IniFormat))
{
    Historique.prepend(new Pile);
    indice_pile_actuelle = 0;

    //CHARGEMENT DE LA PILE
     context->beginGroup("PileStockage");
      QStringList keys = context->allKeys();
      int taille = keys.size();
      for (int i=taille-1; i>=0; i--){
          Constante* tmp = stringToConstante(context->value(keys.at(i)).toString(), true);
          this->getPileStockage()->push(tmp);
      }
      for (int i=0; i<taille; i++){
          context->remove(keys.at(i));
      }
     context->endGroup();

     LogMessage msg(0, "Chargement de la pile.", tracabilite);
     LogSystem::getInstance().ajouterFcihierEtConsole(msg);
     /**
     * \brief Constructeur de la calculatrice
     * \details Construit le QSettings context et restaure la pile enregistré lors de la dernière utilisation.
     */
}

void Calculatrice::saisie_nouvelle_pile(Pile* nouvelle){
    //on enlève tous les potentiels redo
    for(unsigned int i=0; i<indice_pile_actuelle; i++){
        Pile* tmp = Historique.at(0);
        Historique.removeAt(0); // ATTENTION : c'est bien zéro !
        delete(tmp);
    }
    //on ajoute le nouvel état en tête
    Historique.prepend(nouvelle);
    indice_pile_actuelle = 0;
}

void Calculatrice::annuler(){
    if (indice_pile_actuelle != Historique.size()-1){
        indice_pile_actuelle++;
    }
    LogMessage msg(0, "Annulation.", tracabilite);
    LogSystem::getInstance().ajouterFcihierEtConsole(msg);
    /**
    * \brief Fonction annulé
    * \details Annule la dernière action.
    */
}

void Calculatrice::retablir(){
    if (indice_pile_actuelle != 0)
        indice_pile_actuelle--;
    LogMessage msg(0, "Retablissement.", tracabilite);
    LogSystem::getInstance().ajouterFcihierEtConsole(msg);
    /**
    * \brief Fonction rétablir
    * \details Rétabli le dernier état annulé de la pile Historique.
    */
}

void Calculatrice::afficher_toutes_piles_hitorique(){
    qDebug() << "PILES HISTORIQUES\n";
    for(int i=0; i<Historique.size(); i++)
        qDebug() << "PILE " << i << "\n" << Historique.at(i)->afficher();
}

Calculatrice& Calculatrice::getInstance(){
    if (!instance) instance= new Calculatrice();
    return *instance;
    /**
    * \brief Récupération de l'instance
    * \details Permet de ne pas instancier plus d'une fois la classe
    */
}

void Calculatrice::libereInstance(){
    delete instance;
    /**
      * \brief destruction de l'instance
      */
}

