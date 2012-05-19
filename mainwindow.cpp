#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStack>
#include "TypeDonnee.h"





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Initialisation de la calculatrice
    _modAngles = degre;
    _modConstante = entier;
    _modComplexe = false;

    ui->setupUi(this);
    //CONNXIONS CLAVIER BASIC
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

    //CONNEXIONS CLAVIER AVANCE
    connect(ui->FACTORIEL, SIGNAL(clicked()), this, SLOT(FACTORIELClicked()));
    connect(ui->ADDITIONNER, SIGNAL(clicked()), this, SLOT(ADDITIONNERClicked()));
    connect(ui->SOUSTRAIRE, SIGNAL(clicked()), this, SLOT(SOUSTRAIREClicked()));
    connect(ui->MULTIPLIER, SIGNAL(clicked()), this, SLOT(MULTIPLIERClicked()));
    connect(ui->DIVISER, SIGNAL(clicked()), this, SLOT(FACTORIELClicked()));

    connect(ui->_clavierBasic, SIGNAL(stateChanged(int)), this, SLOT(_clavierBasicStateChange(int)));
    connect(ui->_clavierAvance, SIGNAL(stateChanged(int)), this, SLOT(_clavierAvanceStateChange(int)));
    connect(ui->_modComplexeOFF, SIGNAL(toggled(bool)), this, SLOT(_modComplexeOFFClicked(bool)));
    connect(ui->_modComplexeON, SIGNAL(toggled(bool)), this, SLOT(_modComplexeONClicked(bool)));
}

void MainWindow::_modComplexeONClicked(bool b){
    if(b){
        _modComplexe = true;
        this->_pileStockageComplexe.clear();
        this->_pileStockageReelle.clear();
        this->_pileAffichage.clear();
        ui->inputLine->setText("ComplexeON");
    } else {
        this->_modComplexeOFFClicked(true);
    }
}

void MainWindow::_modComplexeOFFClicked(bool b){
    if(b){
        _modComplexe = false;
        this->_pileStockageComplexe.clear();
        this->_pileStockageReelle.clear();
        this->_pileAffichage.clear();
        ui->inputLine->setText("ComplexeOFF");
    } else {
        this->_modComplexeONClicked(true);
    }
}

void MainWindow::_clavierBasicStateChange(int cochee){
    if(cochee==0){ //a été décochée
        ui->widget_clavierBasic->hide();
        //FIXME :quand le clavier est caché on ne peut plus rien saisir !
        ui->inputLine->setEnabled(true);
    } else if (cochee==2) { //a été cochée
        ui->widget_clavierBasic->show();
        ui->inputLine->setEnabled(false);
    }
}

void MainWindow::_clavierAvanceStateChange(int cochee){
    if(cochee==0){ //a été décochée
        ui->widget_clavierAvance->hide();
    } else if (cochee==2) { //a été cochée
        ui->widget_clavierAvance->show();
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

MainWindow::~MainWindow()
{
    delete ui;
}
