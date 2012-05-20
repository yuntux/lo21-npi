#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include "TypeDonnee.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Initialisation de la calculatrice
    _modAngle = degre;
    _modConstante = entier;
    _modComplexe = false;

    //FIXME : comment lier la pile d'affichage à la QListveiw étant donné que QStack n'hérite pas de QAstractmodelitem ?
    //ui->listView_2->setModel(_pileAffichage);
    _pileStockageReelle.append(3.14);
    _pileStockageReelle.append(3.14);
    _pileStockageReelle.append(3.14);

    Complexe c1(2,3);
    Complexe c2(4,5);
    Complexe c3(6,7);
    _pileStockageComplexe.append(c1);
    _pileStockageComplexe.append(c2);
    _pileStockageComplexe.append(c3);

    _pileAffichage.append("premier élement de la pile affichage");
    _pileAffichage.append("deuxième élement de la pile affichage");
    _pileAffichage.append("troisième élement de la pile affichage");




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

    //CONNEXIONS CLAVIER AVANCE
    connect(ui->FACTORIEL, SIGNAL(clicked()), this, SLOT(FACTORIELClicked()));
    connect(ui->ADDITIONNER, SIGNAL(clicked()), this, SLOT(ADDITIONNERClicked()));
    connect(ui->SOUSTRAIRE, SIGNAL(clicked()), this, SLOT(SOUSTRAIREClicked()));
    connect(ui->MULTIPLIER, SIGNAL(clicked()), this, SLOT(MULTIPLIERClicked()));
    connect(ui->DIVISER, SIGNAL(clicked()), this, SLOT(FACTORIELClicked()));

    //CONNEXIONS POUR CHANGEMENT DE MOD
    connect(ui->_clavierBasic, SIGNAL(stateChanged(int)), this, SLOT(_clavierBasicStateChange(int)));
    connect(ui->_clavierAvance, SIGNAL(stateChanged(int)), this, SLOT(_clavierAvanceStateChange(int)));
    connect(ui->_modComplexeOFF, SIGNAL(toggled(bool)), this, SLOT(_modComplexeOFFClicked(bool)));
    connect(ui->_modComplexeON, SIGNAL(toggled(bool)), this, SLOT(_modComplexeONClicked(bool)));
    connect(ui->_modDegres, SIGNAL(toggled(bool)), this, SLOT(_modDegresToggled(bool)));
    connect(ui->_modRadians, SIGNAL(toggled(bool)), this, SLOT(_modRadiansToggled(bool)));

    //this->saveToFile();
    this->loadFromFile();
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
    //la première ligne contient _modAngle
    line = in.readLine();
    if (line=="degre") {
        _modAngle=degre;
        ui->_modDegres->setChecked(true);
    } else if (line=="radian") {
        _modAngle=radian;
        ui->_modRadians->setChecked(true);
    }
    //la deuxième ligne contient _mdoComplexe
    line = in.readLine();
    if (line=="complexeOFF") {
        _modComplexe=false;
        ui->_modComplexeOFF->setChecked(true);
    } else if (line=="complexeON") {
        _modComplexe=true;
        ui->_modComplexeON->setChecked(true);
    }
    //la deuxième ligne contient _modConstante
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
    } else {
        ui->widget_clavierBasic->hide();
        ui->_clavierBasic->setCheckState(Qt::Unchecked);
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
    do {
        line = in.readLine();
    } while (!line.isNull());
ui->inputLine->setText("FIN");
}

void MainWindow::_modDegresToggled(bool b){
    if(b){
        _modAngle=degre;
        ui->inputLine->setText("DegresON");
    } else {
        this->_modRadiansToggled(true);
    }
}

void MainWindow::_modRadiansToggled(bool b){
    if(b){
        _modAngle=radian;
        ui->inputLine->setText("RadiansON");
    } else {
        this->_modDegresToggled(true);
    }
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
