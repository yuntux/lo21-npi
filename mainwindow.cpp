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
#include "logsystem.h"

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
    connect(ui->PIBOUTON, SIGNAL(clicked()), this, SLOT(PIBOUTONClicked()));

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
    LogMessage msg(0, "Chargement du context.", tracabilite);
    LogSystem::getInstance().ajouterFcihierEtConsole(msg);
    /**
      * \brief Chargement du contexte
      * \details Cette fonction sert à charger le contexte qui a été sauvegardé dans la fonction saveToFile. Pour cela on regarde les
      *          paramètres stockés et on modifie les paramètres de MainWindow en fonction
      */
}

void MainWindow::_modDegresToggled(bool b){
    if(b){
        Calculatrice::getInstance().setMesureAngle(degre);
        Calculatrice::getInstance().getContext()->setValue("ModAngle", "degre");
    } else {
        this->_modRadiansToggled(true);
    }
    /**
      * \brief Mode Degré
      * \details Passage en mode degré
      * \param b Booléen permettant de déterminer le mode
      */
}

void MainWindow::_modRadiansToggled(bool b){
    if(b){
        Calculatrice::getInstance().setMesureAngle(radian);
        Calculatrice::getInstance().getContext()->setValue("ModAngle", "radian");
    } else {
        this->_modDegresToggled(true);
    }
    /**
      * \brief Mode Radian
      * \details Passage en mode radian
      * \param b Booléen permettant de déterminer le mode
      */
}

void MainWindow::_modComplexeONClicked(bool b){
    if(b){
        Calculatrice::getInstance().setModComplexe(true);
        ui->DOLLAR->show();
        Calculatrice::getInstance().getContext()->setValue("ModComplexe", true);
    } else {
        this->_modComplexeOFFClicked(true);
    }
    /**
      * \brief Mode Complexe actif
      * \details Passage en mode complexe
      * \param b Booléen permettant de déterminer si le mode est activé
      */
}

void MainWindow::_modComplexeOFFClicked(bool b){
    if(b){
        Calculatrice::getInstance().setModComplexe(false);
        ui->DOLLAR->hide();
        Calculatrice::getInstance().getContext()->setValue("ModComplexe", false);
    } else {
        this->_modComplexeONClicked(true);
    }
    /**
      * \brief Mode Complexe inactif
      * \details Passage en mode complexe
      * \param b Booléen permettant de déterminer si le mode est désactivé
      */
}

void MainWindow::_clavierBasicStateChange(int cochee){
    if(cochee==0){ //a Ã©tÃ© dÃ©cochÃ©e
        ui->widget_clavierBasic->hide();
        Calculatrice::getInstance().getContext()->setValue("ClavierBasic", false);
        ui->inputLine->setEnabled(true);
        ui->inputLine->setFocus();
    } else if (cochee==2) { //a Ã©tÃ© cochÃ©e
        ui->widget_clavierBasic->show();
        Calculatrice::getInstance().getContext()->setValue("ClavierBasic", true);
        ui->inputLine->setEnabled(false);
    }
    /**
      * \brief Clavier basique
      * \details Permet de montrer ou de cacher le clavier basique, selon la valeur du paramètre
      * \param cochee Entier permettant de savoir si on cache ou non le clavier basique
      */
}

void MainWindow::_clavierAvanceStateChange(int cochee){
    if(cochee==0){ //a Ã©tÃ© dÃ©cochÃ©e
        ui->widget_clavierAvance->hide();
        Calculatrice::getInstance().getContext()->setValue("ClavierAvance", false);
    } else if (cochee==2) { //a Ã©tÃ© cochÃ©e
        ui->widget_clavierAvance->show();
        Calculatrice::getInstance().getContext()->setValue("ClavierAvance", true);
    }
    /**
      * \brief Clavier avancé
      * \details Permet de montrer ou de cacher le clavier avancé, selon la valeur du paramètre
      * \param cochee Entier permettant de savoir si on cache ou non le clavier avancé
      */
}

void MainWindow::_modReel(bool b)
{
    if(b){
        Calculatrice::getInstance().setModConstante(reel);
        Calculatrice::getInstance().getContext()->setValue("ModConstante", "reel");
        ui->listView->reset();
        ui->listView->setModel(Calculatrice::getInstance().getPileStockage());
    } else {
        this->_modRationnel(true);
    }
    /**
      * \brief Mode réel
      * \details Permet le passage du mode constante en réel, en fonction de la valeur du paramètre,
      *          puis sauvegarder dans un fichier
      * \param b Booléen permettant le passage dans ce mode
      */
}


void MainWindow::_modRationnel(bool b)
{
    if(b){
        Calculatrice::getInstance().setModConstante(rationnel);
        Calculatrice::getInstance().getContext()->setValue("ModConstante", "rationnel");
        ui->listView->reset();
        ui->listView->setModel(Calculatrice::getInstance().getPileStockage());
    } else {
        this->_modReel(true);
    }
    /**
      * \brief Mode rationnel
      * \details Permet le passage du mode constante en rationnel, en fonction de la valeur du paramètre,
      *          puis sauvegarder dans un fichier
      * \param b Booléen permettant le passage dans ce mode
      */
}


void MainWindow::_modEntier(bool b)
{
    if(b){
        Calculatrice::getInstance().setModConstante(entier);
        Calculatrice::getInstance().getContext()->setValue("ModConstante", "entier");
        ui->listView->reset();
        ui->listView->setModel(Calculatrice::getInstance().getPileStockage());
    } else {
        this->_modRationnel(true);
    }
    /**
      * \brief Mode rationnel
      * \details Permet le passage du mode constante en rationnel, en fonction de la valeur du paramètre,
      *          puis sauvegarder dans un fichier
      * \param b Booléen permettant le passage dans ce mode
      */
}

void MainWindow::PIBOUTONClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" 3.14159265 ");
    /**
      * \brief Clic sur le bouton PI
      * \details Lorsque l'on clique sur le bouton 0, on ajoute une valeur approchée de PI sur la inputline
      */

}

void MainWindow::num0Clicked(){
    ui->inputLine->setText(ui->inputLine->text()+"0");
    /**
      * \brief Clic sur le bouton 0
      * \details Lorsque l'on clique sur le bouton 0, on ajoute 0 sur la inputline
      */

}

void MainWindow::num1Clicked(){
    ui->inputLine->setText(ui->inputLine->text()+"1");
    /**
      * \brief Clic sur le bouton 1
      * \details Lorsque l'on clique sur le bouton 1, on ajoute 1 sur la inputline
      */
}

void MainWindow::num2Clicked(){
    ui->inputLine->setText(ui->inputLine->text()+"2");
    /**
      * \brief Clic sur le bouton 2
      * \details Lorsque l'on clique sur le bouton 2, on ajoute 2 sur la inputline
      */
}

void MainWindow::num3Clicked(){
    ui->inputLine->setText(ui->inputLine->text()+"3");
    /**
      * \brief Clic sur le bouton 3
      * \details Lorsque l'on clique sur le bouton 3, on ajoute 3 sur la inputline
      */
}


void MainWindow::num4Clicked(){
    ui->inputLine->setText(ui->inputLine->text()+"4");
    /**
      * \brief Clic sur le bouton 4
      * \details Lorsque l'on clique sur le bouton 4, on ajoute 4 sur la inputline
      */
}

void MainWindow::num5Clicked(){
    ui->inputLine->setText(ui->inputLine->text()+"5");
    /**
      * \brief Clic sur le bouton 5
      * \details Lorsque l'on clique sur le bouton 5, on ajoute 5 sur la inputline
      */
}

void MainWindow::num6Clicked(){
    ui->inputLine->setText(ui->inputLine->text()+"6");
    /**
      * \brief Clic sur le bouton 6
      * \details Lorsque l'on clique sur le bouton 6, on ajoute 6 sur la inputline
      */
}

void MainWindow::num7Clicked(){
    ui->inputLine->setText(ui->inputLine->text()+"7");
    /**
      * \brief Clic sur le bouton 7
      * \details Lorsque l'on clique sur le bouton 7, on ajoute 7 sur la inputline
      */
}

void MainWindow::num8Clicked(){
    ui->inputLine->setText(ui->inputLine->text()+"8");
    /**
      * \brief Clic sur le bouton 8
      * \details Lorsque l'on clique sur le bouton 8, on ajoute 8 sur la inputline
      */
}

void MainWindow::num9Clicked(){
    ui->inputLine->setText(ui->inputLine->text()+"9");
    /**
      * \brief Clic sur le bouton 9
      * \details Lorsque l'on clique sur le bouton 9, on ajoute 8 sur la inputline
      */
}


void MainWindow::POINTClicked(){
    ui->inputLine->setText(ui->inputLine->text()+".");
    /**
      * \brief Clic sur le bouton "."
      * \details Lorsque l'on clique sur le bouton ".", on ajoute un point sur la inputline
      */
}


void MainWindow::ESPACEClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" ");
    /**
      * \brief Clic sur le bouton espace
      * \details Lorsque l'on clique sur le bouton "_", on ajoute un espace sur la inputline
      */
}

void MainWindow::FACTORIELClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" ! ");
    /**
      * \brief Clic sur le bouton !
      * \details Lorsque l'on clique sur le bouton !, on ajoute ! sur la inputline
      */
}

void MainWindow::ADDITIONNERClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" + ");
    /**
      * \brief Clic sur le bouton +
      * \details Lorsque l'on clique sur le bouton +, on ajoute + sur la inputline
      */
}

void MainWindow::SOUSTRAIREClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" - ");
    /**
      * \brief Clic sur le bouton -
      * \details Lorsque l'on clique sur le bouton -, on ajoute - sur la inputline
      */
}

void MainWindow::MULTIPLIERClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" * ");
    /**
      * \brief Clic sur le bouton *
      * \details Lorsque l'on clique sur le bouton *, on ajoute * sur la inputline
      */
}

void MainWindow::DIVISERClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"/");
    /**
      * \brief Clic sur le bouton /
      * \details Lorsque l'on clique sur le bouton /, on ajoute / sur la inputline
      */
}

void MainWindow::POWClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" POW ");
    /**
      * \brief Clic sur le bouton POW
      * \details Lorsque l'on clique sur le bouton POW, on ajoute POW sur la inputline
      */
}

void MainWindow::SINClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" SIN ");
    /**
      * \brief Clic sur le bouton SIN
      * \details Lorsque l'on clique sur le bouton SIN, on ajoute SIN sur la inputline
      */
}

void MainWindow::COSClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" COS ");
    /**
      * \brief Clic sur le bouton COS
      * \details Lorsque l'on clique sur le bouton COS, on ajoute COS sur la inputline
      */
}

void MainWindow::TANClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" TAN ");
    /**
      * \brief Clic sur le bouton TAN
      * \details Lorsque l'on clique sur le bouton TAN, on ajoute TAN sur la inputline
      */
}

void MainWindow::SINHClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" SINH ");
    /**
      * \brief Clic sur le bouton SINH
      * \details Lorsque l'on clique sur le bouton SINH, on ajoute SINH sur la inputline
      */
}

void MainWindow::COSHClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" COSH ");
    /**
      * \brief Clic sur le bouton COSH
      * \details Lorsque l'on clique sur le bouton COSH, on ajoute COSH sur la inputline
      */
}

void MainWindow::TANHClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" TANH ");
    /**
      * \brief Clic sur le bouton TANH
      * \details Lorsque l'on clique sur le bouton TANH, on ajoute TANH sur la inputline
      */
}

void MainWindow::MODClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" MOD ");
    /**
      * \brief Clic sur le bouton MOD
      * \details Lorsque l'on clique sur le bouton MOD, on ajoute MOD sur la inputline
      */
}

void MainWindow::SIGNClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" SIGN ");
    /**
      * \brief Clic sur le bouton SIGN
      * \details Lorsque l'on clique sur le bouton SIGN, on ajoute SIGN sur la inputline
      */
}

void MainWindow::SQRClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" SQR ");
    /**
      * \brief Clic sur le bouton SQR
      * \details Lorsque l'on clique sur le bouton SQR, on ajoute SQR sur la inputline
      */
}

void MainWindow::SQRTClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" SQRT ");
    /**
      * \brief Clic sur le bouton SQRT
      * \details Lorsque l'on clique sur le bouton SQRT, on ajoute SQRT sur la inputline
      */
}

void MainWindow::CUBEClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" CUBE ");
    /**
      * \brief Clic sur le bouton CUBE
      * \details Lorsque l'on clique sur le bouton CUBE, on ajoute CUBE sur la inputline
      */
}

void MainWindow::LNClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" LN ");
    /**
      * \brief Clic sur le bouton LN
      * \details Lorsque l'on clique sur le bouton LN, on ajoute LN sur la inputline
      */
}

void MainWindow::LOGClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" LOG ");
    /**
      * \brief Clic sur le bouton LOG
      * \details Lorsque l'on clique sur le bouton LOG, on ajoute LOG sur la inputline
      */
}

void MainWindow::INVClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" INV ");
    /**
      * \brief Clic sur le bouton INV
      * \details Lorsque l'on clique sur le bouton INV, on ajoute INV sur la inputline
      */
}

void MainWindow::DOLLARClicked(){
    ui->inputLine->setText(ui->inputLine->text()+"$");
    /**
      * \brief Clic sur le bouton $
      * \details Lorsque l'on clique sur le bouton $, on ajoute $ sur la inputline
      */
}

void MainWindow::QUOTEClicked(){
    ui->inputLine->setText(ui->inputLine->text()+" ' ");
    /**
      * \brief Clic sur le bouton '
      * \details Lorsque l'on clique sur le bouton ', on ajoute ' sur la inputline
      */
}

void MainWindow::CEClicked(){
    ui->inputLine->setText("");
    ui->listView->reset();
    /**
      * \brief Clic sur le bouton CE
      * \details Lorsque l'on clique sur le bouton CE, on retire tout ce qu'il y a sur la inputline, et on
      *          reset la listview
      */
}

void MainWindow::CClicked(){
    //on retire le dernier cractère entré : celui le plus à gauche
    QString newstring = ui->inputLine->text().remove(ui->inputLine->text().size()-1, 1);
    ui->inputLine->setText(newstring);
    ui->listView->reset();
    /**
      * \brief Clic sur le bouton C
      * \details Lorsque l'on clique sur le bouton C, on retire le dernier caractère entré sur la inputline
      */
}

MainWindow::~MainWindow()
{
    delete ui;
    /**
      * \brief Destructeur de MainWindow
      * \details Destruction de ui
      */
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
                throw LogMessage(3,"Nombre de quotes impair.", important);
            } else {
                 if (!dernier_element_expression(chaine))
                    traiter_bloc_calcul(chaine);
             }
        ui->listView->reset();
        ui->listView->setModel(Calculatrice::getInstance().getPileStockage());

    }

    catch(std::exception const& e)
    {
        // FIXME : interagir avec logsystem + regroupement avec QMessagBox
        //LogMessage msg(0, e.wath() ,faible);
        //LogSystem::getInstance().ajouterFcihierEtConsole(msg);
        cerr << "ERREUR : " << e.what() << endl;
    }
    //qDebug() << "PILE COURANTE \n" << Calculatrice::getInstance().getPileStockage()->afficher();
    //Calculatrice::getInstance().afficher_toutes_piles_hitorique();
    /**
      * \brief Clic sur le bouton ENTER
      * \details Récupération de la inputline sous forme de QString et traitement de plusieurs cas. En fonction
      *          de l'interrupteur booléen \e dans_une_exp, on va déterminer si l'on se trouve ou non dans une expression.
      *          En fonction de cela, on enverra soit la fonction \e traiter_bloc_expression, soit la fonction \e traiter_bloc_calcul
      */
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
        Constante* operande1 = NULL;
        Constante* operande2 = NULL;
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

        if(temp=="+")
            calc.getPileStockage()->push(operande2->addition(operande1));
        else if(temp=="*")
            calc.getPileStockage()->push(operande2->produit(operande1));
        else if(temp=="/")
            calc.getPileStockage()->push(operande2->division(operande1));
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
            Constante* nouvelle_constante = stringToConstante(temp, true);
            //si c'est convertible, on l'empile
            if (nouvelle_constante)
                    calc.getPileStockage()->push(nouvelle_constante);
/*                    if (operande1)
                        delete(operande1);
                    if (operande2)
                        delete(operande2);
*/
            else
                throw LogMessage(6,"La chaine saisie est invalide", moyen);
        }
    }
    /**
      * \brief Traitement d'un bloc calcul
      * \details Permet de traiter un bloc de calcul. Effectue un split en fonction de l'espace, puis regarde pour chaque membre
      *          de la liste si c'est un opérateur. Si c'est le cas, on dépile un premier opérande. Si, de plus, c'est un opérateur
      *          binaire, alors on dépile un deuxième opérande. On effectue ensuite le calcul puis on empile le résultat
      * \param s Une QString
      */
}

Constante* stringToConstante(QString temp, bool essayer_construire_complexe){
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
            int num = r.at(0).toInt();
            int denom = r.at(1).toInt();
            Constante* tmp = new Rationnel(num, denom);
            return tmp;
        }
//on essaye de voir si on peut construire un complexe à partir de temp
        //si temp contient exactement un dollar
        if (temp.count(QRegExp("$"))==1 && essayer_construire_complexe) {
            if (Calculatrice::getInstance().getModComplexe()) {
                QStringList c = temp.split("\$");
                Constante* re = stringToConstante(c.at(0), false);
                Constante* im = stringToConstante(c.at(1), false);
                return new Complexe(re, im);
            }
            throw LogMessage(7,"Complexes désactivés : impossible", moyen);
        }
        //non convertible en une constante
         throw LogMessage(8,"La chaine saisie est invalide", moyen);
         return NULL;
         /**
           * \brief Conversion string vers Constante
           * \details En maniant les RegExp, on vérifie si l'on peut convertir en l'un des types de constante.
           *          Si c'est possible, on crée une nouvelle constante du type dans lequel on peut convertir.
           *          Essayer_construire_complexe évite les boucle infinies lorsque l'on rentre n'importe quoi
           *            dans la QTextLine lorsque le clavier basic est désactivé !
           * \return Une \e Constante du type dans lequel il est possible de convertir la chaine
           * \param temp Une QString, essayer_construire_complexe Un booléen
           */
}

void MainWindow::traiter_bloc_expression(QString s){
    Constante* exp = new Expression("'"+s+"'");
    Calculatrice::getInstance().getPileStockage()->push(exp);
    /**
      * \brief Traitement d'un expression
      * \details Crée une expression avec la chaine passée en argument et empile cette chaine.
      * \param s Une QString
      */
}

void MainWindow::EVALClicked(){
    try {
            if (!Calculatrice::getInstance().getPileStockage()->isEmpty()){
                Constante* dernier_element_pop = Calculatrice::getInstance().getPileStockage()->pop();

                if (Expression *tmp=dynamic_cast<Expression *>(dernier_element_pop)){
                    QString c(tmp->getExpr());
                    c.replace("'","");
                    ui->inputLine->setText(c);
                    MainWindow::ENTERClicked();
                    LogMessage msg(0, "Evaluation de l'expression en tete de pile.", tracabilite);
                    LogSystem::getInstance().ajouterFcihierEtConsole(msg);
//                    delete(dernier_element_pop);
                } else {
                    throw LogMessage(3,"Le dernier élément de la pile n'est pas une expression. EVAL impossible.", important);
                    //on remet le dernier élément puisque ce n'est pas un exceptation
                    Calculatrice::getInstance().getPileStockage()->push(dernier_element_pop);
                    return;
                }

            }else{
                throw LogMessage(3,"La pile est vide. Rien à évaluer.", important);
                return;
            }
    }
    catch(std::exception const& e)
    {
        cerr << "ERREUR : " << e.what() << endl;
    }
    /**
      * \brief EVALClicked
      * \details Lorsque l'on clique sur EVAL, on vérifie que la pile est non vide,
      * que son dernier élément est une expression puis on simule une saisie de l'expression dans
      * la QTextLine suivi d'un click sur ENTER.
      */
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
//            delete(dernier_element_pop);
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
     Calculatrice::getInstance().libereInstance();
     LogSystem::getInstance().libereInstance();
     event->accept();
     /**
       * \brief Méthode executée lorsque l'on quite
       * \details Sauvegarde la pile lorsque l'on quitte.
       * la QTextLine suivi d'un click sur ENTER.
       */
}
