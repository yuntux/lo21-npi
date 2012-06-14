#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include "fonctions.h"
#include <iostream>
#include <cmath>
#include "pile.h"
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "entier.h"
#include "expression.h"
#include "calculatrice.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //Initialisation de la calculatrice
    _modAngle = degre;
    _modConstante = entier;
    _modComplexe = false;

    //FIXME : comment lier la pile d'affichage Ã  la QListveiw Ã©tant donnÃ© que QStack n'hÃ©rite pas de QAstractmodelitem ?
    //ui->listView_2->setModel(_pileAffichage);

/*    _pileStockageReelle.append(3.14);
    _pileStockageReelle.append(3.14);
    _pileStockageReelle.append(3.14);
*/
    /*Complexe c1(2,3);
    Complexe c2(4,5);
    Complexe c3(6,7);
    _pileStockageComplexe.append(c1);
    _pileStockageComplexe.append(c2);
    _pileStockageComplexe.append(c3);
*/
    _pileAffichage.append("premier Ã©lement de la pile affichage");
    _pileAffichage.append("deuxiÃ?me Ã©lement de la pile affichage");
    _pileAffichage.append("troisiÃ?me Ã©lement de la pile affichage");




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
    //connect(ui->EVAL, SIGNAL(clicked()), this, SLOT(EVALClicked()));

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
    //this->saveToFile();
    this->loadFromFile();

    /*Complexe c(1,3);
    Complexe d(2,8);
    Complexe e(3,8);
    Complexe f(4,8);
    Complexe g(5,8);
    Complexe h(6,8);
    _pileStockage.append(&c);
    _pileStockage.append(&c);
    _pileStockage.append(&d);
    _pileStockage.append(&e);
    _pileStockage.append(&f);
    _pileStockage.append(&g);
    _pileStockage.append(&h);
    this->afficheur_pile(_pileStockage);
    */

    //Calculatrice::getInstance(); // NE PAS SUPPRIMER, ON CONSTRUIT LE SINGLETON
    Calculatrice::getInstance().getPileStockage();
    ui->listView->setModel(Calculatrice::getInstance().getPileStockage());

}


void MainWindow::afficheur_pile(Pile p){
    //on copie la liste en local pour l'itérer en la détr
    //for (int i=0; i<p.size(); i++)
      //  ui->listWidget->addItem(p.pop()->afficher());
}


void MainWindow::saveToFile(){
    QFile file("context");
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Impossible d'ouvrir le fichier."),
            file.errorString());
        return;
    }

    QTextStream out(&file);

    if (_modAngle==degre) out<< "degre\n";
    if (_modAngle==radian) out<< "radian\n";

    if (_modComplexe) {out<< "complexeON\n";} else {out<< "complexeOFF\n";}
    if (_modConstante==entier) {out<< "entier\n";} else if (_modConstante==reel) {out<< "reel\n";} else if (_modConstante==rationnel) {out<<"rationnel\n";}

    if (ui->_clavierBasic->isChecked()) {out<<"clavierBasicON\n";} else {out<<"clavierBasicOFF\n";}
    if (ui->_clavierAvance->isChecked()) {out<<"clavierAvanceON\n";} else {out<<"clavierAvanceOFF\n";}


    while (!_pileAffichage.empty())
    {
        QString temp = _pileAffichage.pop();
        out << temp <<"\n";
    }
    out<<"\n"; // on a fini la pile => une ligne vide

    while (!_pileStockageReelle.empty())
        out << _pileStockageReelle.pop()<<"\n";
    out<<"\n"; // on a fini la pile => une ligne vide

    while (!_pileStockageComplexe.empty())
    {
        Complexe temp = _pileStockageComplexe.pop();
        out << temp.getPartieReelle()<<"$"<<temp.getPartieImaginaire()<<"\n";
    }
    out<<"\n"; // on a fini la pile => une ligne vide

}


void MainWindow::loadFromFile(){
    QFile file("context");

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Impossible d'ouvrir le fichier."),
            file.errorString());
        return;
    }

    QTextStream in(&file);
    QString line;
    //la premiÃ?re ligne contient _modAngle
    line = in.readLine();
    if (line=="degre") {
        _modAngle=degre;
        ui->_modDegres->setChecked(true);
    } else if (line=="radian") {
        _modAngle=radian;
        ui->_modRadians->setChecked(true);
    }
    //la deuxiÃ?me ligne contient _mdoComplexe
    line = in.readLine();
    if (line=="complexeOFF") {
        _modComplexe=false;
        ui->_modComplexeOFF->setChecked(true);
    } else if (line=="complexeON") {
        _modComplexe=true;
        ui->_modComplexeON->setChecked(true);
    }
    //la deuxiÃ?me ligne contient _modConstante
    line = in.readLine();
    if (line=="entier") {
        _modConstante=entier;
        ui->_modEntiers->setChecked(true);
    } else if (line=="rationnel") {
        _modConstante=rationnel;
        ui->_modRationnels->setChecked(true);
    } else if (line=="reel") {
        ui->_modReels->setChecked(true);
        //propager dans l'interface
    }
    //affichage du clavier basic
    line = in.readLine();
    if (line=="clavierBasicON") {
        ui->widget_clavierBasic->show();
        ui->_clavierBasic->setCheckState(Qt::Checked);
        ui->inputLine->setEnabled(false);
    } else {
        ui->widget_clavierBasic->hide();
        ui->_clavierBasic->setCheckState(Qt::Unchecked);
        ui->inputLine->setEnabled(true);
    }
    //affichage du clavier avance
    line = in.readLine();
    if (line=="clavierAvanceON") {
        ui->widget_clavierAvance->show();
        ui->_clavierAvance->setCheckState(Qt::Checked);
    } else {
        ui->widget_clavierAvance->hide();
        ui->_clavierAvance->setCheckState(Qt::Unchecked);
    }
    //pile d'affichage
/*    do {
        line = in.readLine();
    } while (!line.isNull());
    //pile reels
    //pile complexe
*/
//ui->inputLine->setText("FIN");
}

void MainWindow::_modDegresToggled(bool b){
    if(b){
        _modAngle=degre;
    //    ui->inputLine->setText("DegresON");
        saveToFile();
    } else {
        this->_modRadiansToggled(true);
        saveToFile();
    }
}

void MainWindow::_modRadiansToggled(bool b){
    if(b){
        _modAngle=radian;
      //  ui->inputLine->setText("RadiansON");
        saveToFile();
    } else {
        this->_modDegresToggled(true);
        saveToFile();
    }
}

void MainWindow::_modComplexeONClicked(bool b){
    if(b){
        _modComplexe = true;
        this->_pileStockageComplexe.clear();
        this->_pileStockageReelle.clear();
        this->_pileAffichage.clear();
        //ui->inputLine->setText("ComplexeON");
        saveToFile();
    } else {
        this->_modComplexeOFFClicked(true);
        saveToFile();
    }
}

void MainWindow::_modComplexeOFFClicked(bool b){
    if(b){
        _modComplexe = false;
        this->_pileStockageComplexe.clear();
        this->_pileStockageReelle.clear();
        this->_pileAffichage.clear();
        //ui->inputLine->setText("ComplexeOFF");
        saveToFile();
    } else {
        this->_modComplexeONClicked(true);
        saveToFile();
    }
}

void MainWindow::_clavierBasicStateChange(int cochee){
    if(cochee==0){ //a Ã©tÃ© dÃ©cochÃ©e
        ui->widget_clavierBasic->hide();
        //FIXME :quand le clavier est cachÃ© on ne peut plus rien saisir !
        ui->inputLine->setEnabled(true);
        saveToFile();
    } else if (cochee==2) { //a Ã©tÃ© cochÃ©e
        ui->widget_clavierBasic->show();
        ui->inputLine->setEnabled(false);
        saveToFile();
    }
}

void MainWindow::_clavierAvanceStateChange(int cochee){
    if(cochee==0){ //a Ã©tÃ© dÃ©cochÃ©e
        ui->widget_clavierAvance->hide();
        saveToFile();
    } else if (cochee==2) { //a Ã©tÃ© cochÃ©e
        ui->widget_clavierAvance->show();
        saveToFile();
    }
}

void MainWindow::_modReel(bool b)
{
    if(b){
        _modConstante=reel;
        //ui->inputLine->setText("Réels");
        saveToFile();
    } else {
        this->_modRationnel(true);
        saveToFile();
    }
}


void MainWindow::_modRationnel(bool b)
{
    if(b){
        _modConstante=rationnel;
       // ui->inputLine->setText("Rationnel");
        saveToFile();
    } else {
        this->_modReel(true);
        saveToFile();
    }
}


void MainWindow::_modEntier(bool b)
{
    if(b){
        _modConstante=entier;
        ui->inputLine->setText("Entier");
        saveToFile();
    } else {
        this->_modRationnel(true);
        saveToFile();
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
    ui->inputLine->setText(ui->inputLine->text()+"!");
}

void MainWindow::ADDITIONNERClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"+");
}

void MainWindow::SOUSTRAIREClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"-");
}

void MainWindow::MULTIPLIERClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"*");
}

void MainWindow::DIVISERClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"/");
}

void MainWindow::POWClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"POW");
}

void MainWindow::SINClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"SIN");
}

void MainWindow::COSClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"COS");
}

void MainWindow::TANClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"TAN");
}

void MainWindow::SINHClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"SINH");
}

void MainWindow::COSHClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"COSH");
}

void MainWindow::TANHClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"TANH");
}

void MainWindow::MODClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"MOD");
}

void MainWindow::SIGNClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"SIGN");
}

void MainWindow::SQRClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"SQR");
}

void MainWindow::SQRTClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"SQRT");
}

void MainWindow::CUBEClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"CUBE");
}

void MainWindow::LNClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"LN");
}

void MainWindow::LOGClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"LOG");
}

void MainWindow::INVClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"INV");
}

void MainWindow::DOLLARClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"$");
}

void MainWindow::QUOTEClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"'");
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
                    traiter_bloc_expression(chaine); //cette fonction doit concat avec le dernier element de la pile si c'est une expr?
                    dans_une_exp = false;
                    chaine = "";
                } else {
                    //on rencontre le quote d'ouverture d'une chaine, ce qui était avant doit etre empilé/calculé
                    traiter_bloc_calcul(chaine);
                    dans_une_exp = true;
                    chaine = "";
                }
            } else {
                //qu'on soit ou non dans une chaine on ajoute ce caractère à la sous-chaine en cours
                chaine = chaine + s.at(i);
            }
        }
        //une fois à la fin de l'expression
            if (dans_une_exp)
                throw("Erreur, nombre de quote(s) impaire");
            else
                 traiter_bloc_calcul(chaine);

        //on sauvegarge ce nouvel état que l'on ajoute à la pile historique

        qDebug() << "Nombre de piles dans l'historique : " << Calculatrice::getInstance().taille_pile_hitorique();
        Calculatrice::getInstance().afficher_toutes_piles_hitorique();
        ui->listView->setModel(Calculatrice::getInstance().getPileStockage());
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
    QStringList list = s.split(" ");
    Calculatrice& calc = Calculatrice::getInstance();

    //la vérification du _modConstante n'intervient que lorsque l'on tente d'insérer une constante dans la pile de stockage et à l'affichage
    //la vérification du _modAngle n'intervient que lors du calcul d'une fonction trigo
    bool type_angle = false;
    if(calc.getMesureAngle()==degre)
        type_angle = true;
    //la vérification du _modComplexe n'intervient que lorsque l'on tente d'insérer un complexe dans la pile de stockage
    foreach(QString temp, list)
    {
        Constante* operande1;
        Constante* operande2;
        //si c'est un opérateur on a besoin d'au moins un opérande pour faire un calcul
        if(temp=="+" || temp=="*" || temp=="-" || temp=="/" || temp=="!" || temp=="SIN" || temp=="SINH"  || temp=="COS" || temp=="COSH" || temp=="TAN" || temp=="TANH" || temp=="INV" || temp=="SIGN")
            if (!calc.getPileStockage()->isEmpty())

                operande1 = calc.getPileStockage()->pop();
            else
                throw LogMessage(5,"Nombre d'opérandes insuffisants dans la pile.", moyen);

        //si c'est un operateur binaire on a besoin d'un second opérandes
        if(temp=="+" || temp=="*" || temp=="-" || temp=="/")
            if (!calc.getPileStockage()->isEmpty())
                operande2 = calc.getPileStockage()->pop();
            else
                throw LogMessage(5,"Nombre d'opérandes dans la pile insuffisant.", moyen);

        if(temp=="+")
            calc.getPileStockage()->push(operande1->addition(operande2));
        else if(temp=="*")
            calc.getPileStockage()->push(operande1->produit(operande2));
        else if(temp=="/")
            calc.getPileStockage()->push(operande1->division(operande2));
        else if(temp=="-")
            calc.getPileStockage()->push(operande1->soustraction(operande2));
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

Constante* MainWindow::stringToConstante(QString temp){
//on essaye de voir si c'est convertible en un int temp.toInt();
        QRegExp regexpEntier("^[\\d]*$");
        if (regexpEntier.exactMatch(temp))
            return new Entier(temp.toInt());
//on essaye de voir si c'est convertible en un double temp.toDouble();
        QRegExp regexpReel("^[\\d]*.[\\d]$");
        if (regexpReel.exactMatch(temp))
            return new Reel(temp.toDouble());
//on essaye de voir s'il obéit à la regexp d'un rationnel du genre ([0-9])/([0-9])
        QRegExp regexpRationnel("^[\\d]*/[\\d]*$");
        if (regexpRationnel.exactMatch(temp)) {
            QStringList r = temp.split("/");
            return new Rationnel(r.at(0).toInt(), r.at(1).toInt());
        }
//on essaye de voir si on peut construire un complexe à partir de temp
        //si temp contient exactement un dollar
        if (temp.count(QRegExp("$"))==1) {
            QStringList c = temp.split("\$");
            Constante* re = stringToConstante(c.at(0));
            Constante* im = stringToConstante(c.at(1));
            return new Complexe(re, im);
        }
        //non convertible en une constante
        return NULL;
}

void MainWindow::traiter_bloc_expression(QString s){
        //ajouter à la bonne pile
        //concater à la ligned'avant si c'est aussi une expression
}

