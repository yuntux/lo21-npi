#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <iostream>
#include <cmath>
#include "pile.h"
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "entier.h"
#include "expression.h"
#include <typeinfo>
#include "calculatrice.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //Initialisation de l'interface
    ui->setupUi(this);

    //CONNEXIONS CLAVIER BASIC
    connect(ui->num0, SIGNAL(clicked()), this, SLOT(num0Clicked()));
    connect(ui->num1, SIGNAL(clicked()), this, SLOT(num1Clicked()));
    connect(ui->num2, SIGNAL(clicked()), this, SLOT(num2Clicked()));
    connect(ui->num3, SIGNAL(clicked()), this, SLOT(num3Clicked()));
    connect(ui->num4, SIGNAL(clicked()), this, SLOT(num4Clicked()));
    connect(ui->num5, SIGNAL(clicked()), this, SLOT(num5Clicked()));
    connect(ui->num6, SIGNAL(clicked()), this, SLOT(num6Clicked()));
    connect(ui->num7, SIGNAL(clicked()), this, SLOT(num7Clicked()));
    connect(ui->num8, SIGNAL(clicked()), this, SLOT(num8Clicked()));
    connect(ui->num9, SIGNAL(clicked()), this, SLOT(num9Clicked()));
    connect(ui->POINT, SIGNAL(clicked()), this, SLOT(POINTClicked()));
    connect(ui->ESPACE, SIGNAL(clicked()), this, SLOT(ESPACEClicked()));
    connect(ui->DOLLAR, SIGNAL(clicked()), this, SLOT(DOLLARClicked()));
    connect(ui->QUOTE, SIGNAL(clicked()), this, SLOT(QUOTEClicked()));
    connect(ui->CE, SIGNAL(clicked()), this, SLOT(CEClicked()));
    connect(ui->C, SIGNAL(clicked()), this, SLOT(CClicked()));

    connect(ui->ENTER, SIGNAL(clicked()), this, SLOT(ENTERClicked()));
    connect(ui->EVAL, SIGNAL(clicked()), this, SLOT(EVALClicked()));

    //CONNEXIONS CLAVIER AVANCE
    connect(ui->FACTORIEL, SIGNAL(clicked()), this, SLOT(FACTORIELClicked()));
    connect(ui->ADDITIONNER, SIGNAL(clicked()), this, SLOT(ADDITIONNERClicked()));
    connect(ui->SOUSTRAIRE, SIGNAL(clicked()), this, SLOT(SOUSTRAIREClicked()));
    connect(ui->MULTIPLIER, SIGNAL(clicked()), this, SLOT(MULTIPLIERClicked()));
    connect(ui->DIVISER, SIGNAL(clicked()), this, SLOT(DIVISERClicked()));
    connect(ui->POW, SIGNAL(clicked()), this, SLOT(POWClicked()));
    connect(ui->SIN, SIGNAL(clicked()), this, SLOT(SINClicked()));
    connect(ui->COS, SIGNAL(clicked()), this, SLOT(COSClicked()));
    connect(ui->TAN, SIGNAL(clicked()), this, SLOT(TANClicked()));
    connect(ui->SINH, SIGNAL(clicked()), this, SLOT(SINHClicked()));
    connect(ui->COSH, SIGNAL(clicked()), this, SLOT(COSHClicked()));
    connect(ui->TANH, SIGNAL(clicked()), this, SLOT(TANHClicked()));
    connect(ui->MOD, SIGNAL(clicked()), this, SLOT(MODClicked()));
    connect(ui->SIGN, SIGNAL(clicked()), this, SLOT(SIGNClicked()));
    connect(ui->LN, SIGNAL(clicked()), this, SLOT(LNClicked()));
    connect(ui->LOG, SIGNAL(clicked()), this, SLOT(LOGClicked()));
    connect(ui->INV, SIGNAL(clicked()), this, SLOT(INVClicked()));
    connect(ui->SQR, SIGNAL(clicked()), this, SLOT(SQRClicked()));
    connect(ui->SQRT, SIGNAL(clicked()), this, SLOT(SQRTClicked()));
    connect(ui->CUBE, SIGNAL(clicked()), this, SLOT(CUBEClicked()));

    //CONNEXIONS OPERATIONS SUR PILES
    connect(ui->annuler, SIGNAL(clicked()), this, SLOT(annulerClicked()));
    connect(ui->retablir, SIGNAL(clicked()), this, SLOT(retablirClicked()));
    connect(ui->vider_pile, SIGNAL(clicked()), this, SLOT(vider_pileClicked()));
    connect(ui->supprimer_tete_pile, SIGNAL(clicked()), this, SLOT(supprimer_tete_pileClicked()));
    connect(ui->dupliquer_tete_pile, SIGNAL(clicked()), this, SLOT(dupliquer_tete_pileClicked()));


    //CONNEXIONS POUR CHANGEMENT DE MOD
    connect(ui->_clavierBasic, SIGNAL(stateChanged(int)), this, SLOT(_clavierBasicStateChange(int)));
    connect(ui->_clavierAvance, SIGNAL(stateChanged(int)), this, SLOT(_clavierAvanceStateChange(int)));
    connect(ui->_modComplexeOFF, SIGNAL(toggled(bool)), this, SLOT(_modComplexeOFFClicked(bool)));
    connect(ui->_modComplexeON, SIGNAL(toggled(bool)), this, SLOT(_modComplexeONClicked(bool)));
    connect(ui->_modDegres, SIGNAL(toggled(bool)), this, SLOT(_modDegresToggled(bool)));
    connect(ui->_modRadians, SIGNAL(toggled(bool)), this, SLOT(_modRadiansToggled(bool)));
    connect(ui->_modEntiers, SIGNAL(toggled(bool)), this, SLOT(_modEntier(bool)));
    connect(ui->_modRationnels, SIGNAL(toggled(bool)), this, SLOT(_modRationnel(bool)));
    connect(ui->_modReels, SIGNAL(toggled(bool)), this, SLOT(_modReel(bool)));


    Calculatrice::getInstance().getPileStockage(); // NE PAS SUPPRIMER, ON CONSTRUIT LE SINGLETON
    ui->listView->setModel(Calculatrice::getInstance().getPileStockage());
    //Restauration du context
    this->loadFromFile();

    //RACOURCIS CLAVIER
    QShortcut* ctrlz = new QShortcut(QKeySequence(tr("Ctrl+Z", "Annuler")), this, SLOT(annulerClicked()), SLOT(annulerClicked()));
    QShortcut* ctrlr = new QShortcut(QKeySequence(tr("Ctrl+R", "Rétablir")), this, SLOT(retablirClicked()), SLOT(retablirClicked()));
    QShortcut* ctrlc = new QShortcut(QKeySequence(tr("Ctrl+C", "Rétablir")), this, SLOT(vider_pileClicked()), SLOT(vider_pileClicked()));
    QShortcut* enter = new QShortcut(QKeySequence(Qt::Key_Enter), this, SLOT(ENTERClicked()), SLOT(ENTERClicked()));
    QShortcut* retour = new QShortcut(QKeySequence(Qt::Key_Return), this, SLOT(ENTERClicked()), SLOT(ENTERClicked()));
}

void MainWindow::vider_pileClicked(){
    Pile* nouvel_etat = new Pile(); //on crée une pile vide
    Calculatrice::getInstance().saisie_nouvelle_pile(nouvel_etat);
    ui->listView->setModel(Calculatrice::getInstance().getPileStockage());
}

void MainWindow::supprimer_tete_pileClicked(){
    Pile* nouvel_etat = Calculatrice::getInstance().getPileStockage()->copier_pile();
    Calculatrice::getInstance().saisie_nouvelle_pile(nouvel_etat);
    Calculatrice::getInstance().getPileStockage()->drop();
    ui->listView->setModel(Calculatrice::getInstance().getPileStockage());
}

void MainWindow::dupliquer_tete_pileClicked(){
    Pile* nouvel_etat = Calculatrice::getInstance().getPileStockage()->copier_pile();
    Calculatrice::getInstance().saisie_nouvelle_pile(nouvel_etat);
    Calculatrice::getInstance().getPileStockage()->dup();
    ui->listView->setModel(Calculatrice::getInstance().getPileStockage());

}

void MainWindow::loadFromFile(){

    QString angle_ini = Calculatrice::getInstance().getContext()->value("ModAngle").toString();
    if (angle_ini=="degre") {
        Calculatrice::getInstance().setMesureAngle(degre);
        ui->_modDegres->setChecked(true);
    } else if (angle_ini=="radian") {
        Calculatrice::getInstance().setMesureAngle(radian);
        ui->_modRadians->setChecked(true);
    }
    bool complexe_ini = Calculatrice::getInstance().getContext()->value("ModComplexe").toBool();
    if (!complexe_ini) {
        Calculatrice::getInstance().setModComplexe(false);
        ui->_modComplexeOFF->setChecked(true);
    } else if (complexe_ini) {
        Calculatrice::getInstance().setModComplexe(true);
        ui->_modComplexeON->setChecked(true);
    }
    QString constante_ini = Calculatrice::getInstance().getContext()->value("ModConstante").toString();
    if (constante_ini=="entier") {
        Calculatrice::getInstance().setModConstante(entier);
        ui->_modEntiers->setChecked(true);
    } else if (constante_ini=="rationnel") {
        Calculatrice::getInstance().setModConstante(rationnel);
        ui->_modRationnels->setChecked(true);
    } else if (constante_ini=="reel") {
        Calculatrice::getInstance().setModConstante(reel);
        ui->_modReels->setChecked(true);
    }
    bool clavierBasic_ini = Calculatrice::getInstance().getContext()->value("ClavierBasic").toBool();
    if (clavierBasic_ini) {
        ui->widget_clavierBasic->show();
        ui->_clavierBasic->setCheckState(Qt::Checked);
        ui->inputLine->setEnabled(false);
    } else {
        ui->widget_clavierBasic->hide();
        ui->_clavierBasic->setCheckState(Qt::Unchecked);
        ui->inputLine->setEnabled(false);
        ui->inputLine->setFocus(); //FIXME : le focus n'est pas mis
    }
    bool clavierAvance_ini = Calculatrice::getInstance().getContext()->value("ClavierAvance").toBool();
    if (clavierAvance_ini) {
        ui->widget_clavierAvance->show();
        ui->_clavierAvance->setCheckState(Qt::Checked);
    } else {
        ui->widget_clavierAvance->hide();
        ui->_clavierAvance->setCheckState(Qt::Unchecked);
    }
}

void MainWindow::_modDegresToggled(bool b){
    if(b){
        Calculatrice::getInstance().setMesureAngle(degre);
        Calculatrice::getInstance().getContext()->setValue("ModAngle", "degre");
    } else {
        this->_modRadiansToggled(true);
    }
}

void MainWindow::_modRadiansToggled(bool b){
    if(b){
        Calculatrice::getInstance().setMesureAngle(radian);
        Calculatrice::getInstance().getContext()->setValue("ModAngle", "radian");
    } else {
        this->_modDegresToggled(true);
    }
}

void MainWindow::_modComplexeONClicked(bool b){
    if(b){
        Calculatrice::getInstance().setModComplexe(true);
        ui->DOLLAR->show();
        Calculatrice::getInstance().getContext()->setValue("ModComplexe", true);
    } else {
        this->_modComplexeOFFClicked(true);
    }
}

void MainWindow::_modComplexeOFFClicked(bool b){
    if(b){
        Calculatrice::getInstance().setModComplexe(false);
        ui->DOLLAR->hide();
        Calculatrice::getInstance().getContext()->setValue("ModComplexe", false);
    } else {
        this->_modComplexeONClicked(true);
    }
}

void MainWindow::_clavierBasicStateChange(int cochee){
    if(cochee==0){ //a Ã©tÃ© dÃ©cochÃ©e
        ui->widget_clavierBasic->hide();
        Calculatrice::getInstance().getContext()->setValue("ClavierBasic", false);
        //FIXME :quand le clavier est cachÃ© on ne peut plus rien saisir !
        ui->inputLine->setEnabled(true);
        ui->inputLine->setFocus();
    } else if (cochee==2) { //a Ã©tÃ© cochÃ©e
        ui->widget_clavierBasic->show();
        Calculatrice::getInstance().getContext()->setValue("ClavierBasic", true);
        ui->inputLine->setEnabled(false);
    }
}

void MainWindow::_clavierAvanceStateChange(int cochee){
    if(cochee==0){ //a Ã©tÃ© dÃ©cochÃ©e
        ui->widget_clavierAvance->hide();
        Calculatrice::getInstance().getContext()->setValue("ClavierAvance", false);
    } else if (cochee==2) { //a Ã©tÃ© cochÃ©e
        ui->widget_clavierAvance->show();
        Calculatrice::getInstance().getContext()->setValue("ClavierAvance", true);
    }
}

void MainWindow::_modReel(bool b)
{
    if(b){
        Calculatrice::getInstance().setModConstante(reel);
        Calculatrice::getInstance().getContext()->setValue("ModConstante", "reel");
    } else {
        this->_modRationnel(true);
    }
}


void MainWindow::_modRationnel(bool b)
{
    if(b){
        Calculatrice::getInstance().setModConstante(rationnel);
        Calculatrice::getInstance().getContext()->setValue("ModConstante", "rationnel");
    } else {
        this->_modReel(true);
    }
}


void MainWindow::_modEntier(bool b)
{
    if(b){
        Calculatrice::getInstance().setModConstante(entier);
        Calculatrice::getInstance().getContext()->setValue("ModConstante", "entier");
    } else {
        this->_modRationnel(true);
    }
}


void MainWindow::num0Clicked(){
    ui->inputLine->setText(ui->inputLine->text()+"0");

}

void MainWindow::num1Clicked(){
    ui->inputLine->setText(ui->inputLine->text()+"1");
}

void MainWindow::num2Clicked(){
    ui->inputLine->setText(ui->inputLine->text()+"2");
}

void MainWindow::num3Clicked(){
    ui->inputLine->setText(ui->inputLine->text()+"3");
}


void MainWindow::num4Clicked(){
    ui->inputLine->setText(ui->inputLine->text()+"4");
}

void MainWindow::num5Clicked(){
    ui->inputLine->setText(ui->inputLine->text()+"5");
}

void MainWindow::num6Clicked(){
    ui->inputLine->setText(ui->inputLine->text()+"6");
}

void MainWindow::num7Clicked(){
    ui->inputLine->setText(ui->inputLine->text()+"7");
}

void MainWindow::num8Clicked(){
    ui->inputLine->setText(ui->inputLine->text()+"8");
}

void MainWindow::num9Clicked(){
    ui->inputLine->setText(ui->inputLine->text()+"9");
}


void MainWindow::POINTClicked(){
    ui->inputLine->setText(ui->inputLine->text()+".");
}


void MainWindow::ESPACEClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" ");
}

void MainWindow::FACTORIELClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" ! ");
}

void MainWindow::ADDITIONNERClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" + ");
}

void MainWindow::SOUSTRAIREClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" - ");
}

void MainWindow::MULTIPLIERClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" * ");
}

void MainWindow::DIVISERClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"/");
}

void MainWindow::POWClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" POW ");
}

void MainWindow::SINClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" SIN ");
}

void MainWindow::COSClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" COS ");
}

void MainWindow::TANClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" TAN ");
}

void MainWindow::SINHClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" SINH ");
}

void MainWindow::COSHClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" COSH ");
}

void MainWindow::TANHClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" TANH ");
}

void MainWindow::MODClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" MOD ");
}

void MainWindow::SIGNClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" SIGN ");
}

void MainWindow::SQRClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" SQR ");
}

void MainWindow::SQRTClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" SQRT ");
}

void MainWindow::CUBEClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" CUBE ");
}

void MainWindow::LNClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" LN ");
}

void MainWindow::LOGClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" LOG ");
}

void MainWindow::INVClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" INV ");
}

void MainWindow::DOLLARClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"$");
}

void MainWindow::QUOTEClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" ' ");
}

void MainWindow::CEClicked(){
    ui->inputLine->setText("");
    ui->listView->reset();
}

void MainWindow::CClicked(){
    //on retire le dernier cractère entré : celui le plus à gauche
    QString newstring = ui->inputLine->text().remove(ui->inputLine->text().size()-1, 1);
    ui->inputLine->setText(newstring);
    ui->listView->reset();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::annulerClicked(){
    Calculatrice::getInstance().annuler();
    ui->listView->setModel(Calculatrice::getInstance().getPileStockage());
}
void MainWindow::retablirClicked(){
    Calculatrice::getInstance().retablir();
    ui->listView->setModel(Calculatrice::getInstance().getPileStockage());
}
void MainWindow::ENTERClicked(){
    //FIXME => UN ESPACE APRES UN OPERATEUR FAIT RENTRER UN ZÉRO !!!
    try {
        QString s = ui->inputLine->text();
        ui->inputLine->setText("");

        Pile* nouvel_etat = Calculatrice::getInstance().getPileStockage()->copier_pile();
        Calculatrice::getInstance().saisie_nouvelle_pile(nouvel_etat);

        bool dans_une_exp = false; //interrupteur qui permet de savoir si on est entre deux quotes
        QString chaine; //bloc qui est soit une expression soit un bloc à calculer
        for (int i=0; i<s.length();i++){
            if(s.at(i) == '\''){
                if (dans_une_exp){
                    //on était déjà dans une epxression donc on est sur le quote de sortie
                    if (!dernier_element_expression(chaine))
                        traiter_bloc_expression(chaine); //cette fonction doit concat avec le dernier element de la pile si c'est une expr?
                    dans_une_exp = false;
                    chaine = "";
                } else {
                    //on rencontre le quote d'ouverture d'une chaine, ce qui était avant doit etre empilé/calculé
                        if (!dernier_element_expression(chaine))
                            traiter_bloc_calcul(chaine);
                        dans_une_exp = true;
                        chaine = "";
                }
            } else {
                //qu'on soit ou non dans une chaine on ajoute ce caractère à la sous-chaine en cours
                chaine = chaine + s.at(i);
            }
        }
        //une fois à la fin du QLineEdit
            if (dans_une_exp) {
                throw("Erreur, nombre de quote(s) impaire");
            } else {
                 if (!dernier_element_expression(chaine))
                    traiter_bloc_calcul(chaine);
             }
        qDebug() << Calculatrice::getInstance().getPileStockage()->afficher();
        ui->listView->reset();
        ui->listView->setModel(Calculatrice::getInstance().getPileStockage());
        //Calculatrice::getInstance().getPileStockage()->sauv_pile_context();
    }

    catch(std::exception const& e)
    {
        // FIXME : interagir avec logsystem + regroupement avec QMessagBox
        cerr << "ERREUR : " << e.what() << endl;
    }
    //qDebug() << "PILE COURANTE \n" << Calculatrice::getInstance().getPileStockage()->afficher();
    //Calculatrice::getInstance().afficher_toutes_piles_hitorique();

}

void MainWindow::traiter_bloc_calcul(QString s){
    s.simplified();

    QStringList list = s.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    Calculatrice& calc = Calculatrice::getInstance();

    //la vérification du _modConstante n'intervient que lorsque l'on tente d'insérer une constante dans la pile de stockage et à l'affichage
    bool type_angle = false;
    if(calc.getMesureAngle()==degre)
        type_angle = true;
    //la vérification du _modComplexe n'intervient que lorsque l'on tente d'insérer un complexe dans la pile de stockage
    foreach(QString temp, list)
    {
        //FIXME : on ne dépile par pareil si c'est une epxpression qui précède
        Constante* operande1;
        Constante* operande2;
        //si c'est un opérateur on a besoin d'au moins un opérande pour faire un calcul
        if(temp=="+" || temp=="*" || temp=="-" || temp=="/" || temp=="!" || temp=="SIN" || temp=="SINH"  || temp=="COS" || temp=="COSH" || temp=="TAN" || temp=="TANH" || temp=="INV" || temp=="SIGN" || temp=="LOG" || temp=="LN" || temp=="CUBE" || temp=="SQR" || temp=="SQRT" || temp=="POW")
            if (!calc.getPileStockage()->isEmpty()){
                operande1 = calc.getPileStockage()->pop();
            } else {
                throw LogMessage(5,"Nombre d'opérandes insuffisants dans la pile.", moyen);
            }
        //si c'est un operateur binaire on a besoin d'un second opérandes
        if(temp=="+" || temp=="*" || temp=="-" || temp=="/" || temp=="POW")
            if (!calc.getPileStockage()->isEmpty())
                operande2 = calc.getPileStockage()->pop();
            else
                throw LogMessage(5,"Nombre d'opérandes dans la pile insuffisant.", moyen);

        if(temp=="+"){
            qDebug() << "OP1 " << operande1->afficher() << "OP2 " << operande2->afficher();
            if (typeid(*operande1)==typeid(Rationnel))
                    qDebug() << "OP1 est RATIONNEL";
            if (typeid(*operande2)==typeid(Rationnel))
                    qDebug() << "OP2 est RATIONNEL";
            calc.getPileStockage()->push(operande2->addition(operande1));
        }
        else if(temp=="*")
            calc.getPileStockage()->push(operande2->produit(operande1));
        else if(temp=="/")
            //FIXME : la méthode division plante si on enchaine deux divisions
            calc.getPileStockage()->push(operande2->produit(operande1->inv()));
        else if(temp=="-")
            calc.getPileStockage()->push(operande2->soustraction(operande1));
        else if(temp=="!")
            calc.getPileStockage()->push(operande1->fact());
        else if(temp=="SIN")
            calc.getPileStockage()->push(operande1->sinus(type_angle));
        else if(temp=="SINH")
            calc.getPileStockage()->push(operande1->sinush(type_angle));
        else if(temp=="COS")
            calc.getPileStockage()->push(operande1->cosinus(type_angle));
        else if(temp=="COSH")
            calc.getPileStockage()->push(operande1->cosinush(type_angle));
        else if(temp=="TAN")
            calc.getPileStockage()->push(operande1->tangente(type_angle));
        else if(temp=="TANH")
            calc.getPileStockage()->push(operande1->tangenteh(type_angle));
        else if(temp=="INV")
            calc.getPileStockage()->push(operande1->inv());
        else if(temp=="SIGN")
            calc.getPileStockage()->push(operande1->signe());
        else if(temp=="SQR")
            calc.getPileStockage()->push(operande1->carre());
        else if(temp=="SQRT")
            calc.getPileStockage()->push(operande1->racine());
        else if(temp=="CUBE")
            calc.getPileStockage()->push(operande1->cube());
        else if(temp=="LN")
            calc.getPileStockage()->push(operande1->logN());
        else if(temp=="POW")
            calc.getPileStockage()->push(operande2->puissance(operande1));
        else if(temp=="LOG")
            calc.getPileStockage()->push(operande1->log1());

        else {
            //on essaye de convertir la chaine en constante
            Constante* nouvelle_constante = stringToConstante(temp);
            //si c'est convertible, on l'empile
            if (nouvelle_constante)
                    calc.getPileStockage()->push(nouvelle_constante);
            else
                throw LogMessage(6,"La chaine saisie est invalide", moyen);
        }
    }
}

Constante* stringToConstante(QString temp){
    qDebug() << "ENTREE DANS STRINGTOCONSTNATE" << temp;
//on essaye de voir si c'est convertible en un int temp.toInt();
        QRegExp regexpEntier("^[\\d]*$");
        if (regexpEntier.exactMatch(temp))
            return new Entier(temp.toInt());
//on essaye de voir si c'est convertible en un double temp.toDouble();
        QRegExp regexpReel("^([0-9]+)?\\.([0-9]+)?$");
        if (regexpReel.exactMatch(temp))
            return new Reel(temp.toDouble());
//on essaye de voir s'il obéit à la regexp d'un rationnel du genre ([0-9])/([0-9])
        QRegExp regexpRationnel("^[\\d]*/[\\d]*$");
        if (regexpRationnel.exactMatch(temp)) {
            QStringList r = temp.split("/");
            //qDebug() << "Num : " << r.at(0).toInt() << " Denom : " << r.at(1).toInt();
            int num = r.at(0).toInt();
            int denom = r.at(1).toInt();
            Constante* tmp = new Rationnel(num, denom);
            return tmp;
        }
//on essaye de voir si on peut construire un complexe à partir de temp
        //si temp contient exactement un dollar
        if (temp.count(QRegExp("$"))==1) {
            if (Calculatrice::getInstance().getModComplexe()) {
                QStringList c = temp.split("\$");
                Constante* re = stringToConstante(c.at(0));
                Constante* im = stringToConstante(c.at(1));
                return new Complexe(re, im);
            }
            throw LogMessage(7,"Complexes désactivés : impossible", moyen);
        }
        //non convertible en une constante
        //FIXME : lever une exeption
         throw LogMessage(8,"La chaine saisie est invalide", moyen);
         return NULL;
}

void MainWindow::traiter_bloc_expression(QString s){
    Constante* exp = new Expression("'"+s+"'");
    Calculatrice::getInstance().getPileStockage()->push(exp);
}

void MainWindow::EVALClicked(){
    if (!Calculatrice::getInstance().getPileStockage()->isEmpty()){
        Constante* dernier_element_pop = Calculatrice::getInstance().getPileStockage()->pop();

        if (Expression *tmp=dynamic_cast<Expression *>(dernier_element_pop)){
            QString c(tmp->getExpr());
            c.replace("'","");
            ui->inputLine->setText(c);
            MainWindow::ENTERClicked();
        } else {
            //FIXME : lever exception
            //on remet le dernier élément puisque ce n'est pas un exceptation
            Calculatrice::getInstance().getPileStockage()->push(dernier_element_pop);
        }

    }else{
        //FIXME : lever exception
    }
}


bool MainWindow::dernier_element_expression(QString chaine) {
    if (!Calculatrice::getInstance().getPileStockage()->isEmpty()){
        //on elève le premier élément de la pile
        Constante* dernier_element_pop = Calculatrice::getInstance().getPileStockage()->pop();

        if (Expression *tmp=dynamic_cast<Expression *>(dernier_element_pop)){ //si le dernier élément est une expression
            //on conctatène cette expression avec chaine
            QString dernier_element = tmp->getExpr();
            dernier_element.replace("'","");
            //on l'envoie à traiter_bloc_expression
            traiter_bloc_expression(dernier_element+" "+chaine);
            //delete dernier_element_pop
            return true;
        }else{
            //Comme ce n'est pas une expression on doit remettre l'élément popé au départ dans la liste
            Calculatrice::getInstance().getPileStockage()->push(dernier_element_pop);
            return false;
        }
    } else {
        return false;
    }
}

void MainWindow::closeEvent(QCloseEvent *event){
     Calculatrice::getInstance().getPileStockage()->sauv_pile_context();
     event->accept();
}
