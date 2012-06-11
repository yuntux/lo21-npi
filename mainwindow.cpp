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
    _pileStockageReelle.append(3.14);
    _pileStockageReelle.append(3.14);
    _pileStockageReelle.append(3.14);

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
}

void MainWindow::CClicked(){
    //on retire le dernier cractère entré : celui le plus à gauche
    QString newstring = ui->inputLine->text().remove(ui->inputLine->text().size()-1, 1);
    ui->inputLine->setText(newstring);
}

void MainWindow::ENTERClicked(){

    bool expr = verifInput(ui->inputLine->text());
    if(expr==true)
    {

        Expression* ex1 = new Expression(ui->inputLine->text());
        traitement_expr(ex1->getExpr());
        /*_pileStockage.push(ex1);
        Constante* ex2 = _pileStockage.top();
        qDebug()<<"\nexpression : "<<ex2->afficher();*/
        ui->inputLine->setText("");
    }
   else
    {
        QStringList list = ui->inputLine->text().split(" ");
        ui->inputLine->setText("");


float res=0;
float res2;
float res3;
bool reel_pur=false;
bool rat=false;
int i = 1;
int j=0;

if(!_modComplexe)
{
    foreach(QString temp, list)
    {

        if(temp=="+")
        {
            if(_modConstante==entier)
            {
                Constante *e1 = _pileStockage.pop();
                Constante *e2 = _pileStockage.pop();
                _pileStockage.push(e1->addition(e2));
                Constante *e3 = _pileStockage.top();
                qDebug()<<e3->afficher();
            }
            else if(_modConstante==reel)
            {
                Constante *re1 = _pileStockage.pop();
                Constante *re2 = _pileStockage.pop();
                _pileStockage.push(re1->addition(re2));
                Constante *e3 = _pileStockage.top();
                qDebug()<<e3->afficher();
            }
            else if(_modConstante==rationnel)
            {
                Constante *ra1 = _pileStockage.pop();
                Constante *ra2 = _pileStockage.pop();
                _pileStockage.push(ra1->addition(ra2));
                Constante *ra3 = _pileStockage.top();
                qDebug()<<ra3->afficher();
            }
        }

        else if(temp=="*")
        {
            if(_modConstante==entier)
            {
                Constante *e1 = _pileStockage.pop();
                Constante *e2 = _pileStockage.pop();
                _pileStockage.push(e1->produit(e2));
                Constante *e3 = _pileStockage.top();
                qDebug()<<e3->afficher();
            }
            else if(_modConstante==reel)
            {
                Constante *re1 = _pileStockage.pop();
                Constante *re2 = _pileStockage.pop();
                _pileStockage.push(re1->produit(re2));
                Constante *e3 = _pileStockage.top();
                qDebug()<<e3->afficher();
            }
            else if(_modConstante==rationnel)
            {
                Constante *ra1 = _pileStockage.pop();
                Constante *ra2 = _pileStockage.pop();
                _pileStockage.push(ra1->produit(ra2));
                Constante *ra3 = _pileStockage.top();
                qDebug()<<ra3->afficher();
            }
        }

        else if(temp=="/")
        {
            if(_modConstante==entier)
            {
                Constante *e1 = _pileStockage.pop();
                Constante *e2 = _pileStockage.pop();
                _pileStockage.push(e2->division(e1));
                Constante *e3 = _pileStockage.top();
                qDebug()<<e3->afficher();
            }
            else if(_modConstante==reel)
            {
                Constante *re1 = _pileStockage.pop();
                Constante *re2 = _pileStockage.pop();
                _pileStockage.push(re2->division(re1));
                Constante *e3 = _pileStockage.top();
                qDebug()<<e3->afficher();
            }
            else if(_modConstante==rationnel)
            {
                Constante *ra1 = _pileStockage.pop();
                Constante *ra2 = _pileStockage.pop();
                _pileStockage.push(ra2->division(ra1));
                Constante *ra3 = _pileStockage.top();
                qDebug()<<ra3->afficher();
            }
        }

        else if(temp=="-")
        {
            if(_modConstante==entier)
            {
                Constante *e1 = _pileStockage.pop();
                Constante *e2 = _pileStockage.pop();
                _pileStockage.push(e2->soustraction(e1));
                Constante *e3 = _pileStockage.top();
                qDebug()<<e3->afficher();
            }
            else if(_modConstante==reel)
            {
                Constante *re1 = _pileStockage.pop();
                Constante *re2 = _pileStockage.pop();
                _pileStockage.push(re2->soustraction(re1));
                Constante *e3 = _pileStockage.top();
                qDebug()<<e3->afficher();
            }
            else if(_modConstante==rationnel)
            {
                Constante *ra1 = _pileStockage.pop();
                Constante *ra2 = _pileStockage.pop();
                _pileStockage.push(ra2->soustraction(ra1));
                Constante *ra3 = _pileStockage.top();
                qDebug()<<ra3->afficher();
            }
        }


        else if(temp=="!")
        {
            if(_modConstante==entier)
            {
                Constante *e = _pileStockage.pop();
                _pileStockage.push(e->fact());
                Constante *ra3 = _pileStockage.top();
                qDebug()<<ra3->afficher();
            }



        }

        else if(temp=="SIN")
        {
            if(_modConstante==entier || _modConstante==reel || _modConstante==rationnel)
            {
                if(_modAngle==degre)
                {
                Constante *e = _pileStockage.pop();
                _pileStockage.push(e->sinus(true));
                Constante *ra3 = _pileStockage.top();
                qDebug()<<ra3->afficher();
                }
                else
                {
                Constante *e = _pileStockage.pop();
                _pileStockage.push(e->sinus(false));
                Constante *ra3 = _pileStockage.top();
                qDebug()<<ra3->afficher();
                }

            }
        }

        else if(temp=="COS")
        {
            if(_modConstante==entier || _modConstante==reel || _modConstante==rationnel)
            {
                Constante *e = _pileStockage.pop();
                _pileStockage.push(e->cosinus(true));
                Constante *ra3 = _pileStockage.top();
                qDebug()<<ra3->afficher();
            }
        }

     /*   else if(temp=="TAN")
        {
            if(_modConstante==entier || _modConstante==reel || _modConstante==rationnel)
            {
                Constante *e = _pileStockage.pop();
                _pileStockage.push(e->tangente());
                Constante *ra3 = _pileStockage.top();
                qDebug()<<ra3->afficher();
            }
        }*/
            /*float t,val;
            if(_modAngle==degre)
            {
                val=_pileStockageReelle.pop();
                val=val*PI/180;
                t=tan(val);
                empiler(t);
                qDebug()<<_pileStockageReelle.top();
            }
            else
            {
            t=tan(_pileStockageReelle.pop());
            empiler(t);
            qDebug()<<_pileStockageReelle.top();
            }
        }

        else if(temp=="SINH")
        {
            float sh,val;
            if(_modAngle==degre)
            {
                val=_pileStockageReelle.pop();
                val=val*PI/180;
                sh=sinh(val);
                empiler(sh);
                qDebug()<<_pileStockageReelle.top();
            }
            else
            {
            sh=sinh(_pileStockageReelle.pop());
            empiler(sh);
            qDebug()<<_pileStockageReelle.top();
            }
        }

        else if(temp=="COSH")
        {
            float ch,val;
            if(_modAngle==degre)
            {
                val=_pileStockageReelle.pop();
                val=val*PI/180;
                ch=cosh(val);
                empiler(ch);
                qDebug()<<_pileStockageReelle.top();
            }
            else
            {
            ch=cosh(_pileStockageReelle.pop());
            empiler(ch);
            qDebug()<<_pileStockageReelle.top();
            }
        }


        else if(temp=="TANH")
        {
            float th,val;
            if(_modAngle==degre)
            {
                val=_pileStockageReelle.pop();
                val=val*PI/180;
                th=tanh(val);
                empiler(th);
                qDebug()<<_pileStockageReelle.top();
            }
            else
            {
            th=tanh(_pileStockageReelle.pop());
            empiler(th);
            qDebug()<<_pileStockageReelle.top();
            }
        }

        else if(temp=="LN")
        {
            float l;
            l=log(_pileStockageReelle.pop());
            empiler(l);
            qDebug()<<_pileStockageReelle.top();
        }

        else if(temp=="LOG")
        {
            float lo;
            lo=log10(_pileStockageReelle.pop());
            empiler(lo);
            qDebug()<<_pileStockageReelle.top();
        }

        else if(temp=="POW")
        {
            float p;
            float p1=_pileStockageReelle.pop();
            p=pow(_pileStockageReelle.pop(),p1);
            empiler(p);
            qDebug()<<_pileStockageReelle.top();
        }

        else if(temp=="SQR")
        {
            float sq,sq1;
            sq=_pileStockageReelle.pop();
            sq1=pow(sq,2);
            empiler(sq1);
            qDebug()<<_pileStockageReelle.top();
        }

        else if(temp=="CUBE")
        {
            float cu,cu1;
            cu=_pileStockageReelle.pop();
            cu1=pow(cu,3);
            empiler(cu1);
            qDebug()<<_pileStockageReelle.top();
        }

        else if(temp=="SQRT")
        {
            float sq;
            sq=sqrt(_pileStockageReelle.pop());
            empiler(sq);
            qDebug()<<_pileStockageReelle.top();
        }

        else if(temp.at(0)=='\'')
        {
            QString s1;
            while(list.at(i).at(0)!='\'')
            {
                i++;

            }
            int k=i+1;
            while(list.at(k).at(0)!='\'')
            {
                k++;
            }

            traitement_expr(i+1,k,list);
            i=k;
            qDebug()<<"\ni = "<<i;
            qDebug()<<"\nk = "<<k;


                //_pileAffichage.push(s1);
                //qDebug()<<_pileAffichage.top();
        }

         else if(temp.at(0)=='-' && temp.at(1)>='0' && temp.at(1)<='9')
        {
            QString s;
            for(int i=1;i<temp.size();i++)
                s=s+temp.at(i);

            res=s.toDouble();
            res=-res;
            empiler(res);
            qDebug()<<"\n"<<_pileStockageReelle.top();
        }
*/
        else if(temp[0]>='0' && temp[0]<='9')
        {
            if(_modConstante==rationnel)
            {
                for(int i=0;i<temp.size();i++)
                {
                    if(temp[i]=='/')
                        rat=true;
                }
                if(rat==true)
                {
                    QStringList list2 = temp.split('/');

                        int a,b;
                        a=list2.at(0).toInt();
                        b=list2.at(1).toInt();
                        Rationnel *r = new Rationnel(a,b);
                        _pileStockage.push(r);

                        Rationnel *r1=new Rationnel(_pileStockage.top());
                        qDebug()<<"\nNumérateur : "<<r1->getNumerateur();
                        qDebug()<<"\nDénominateur : "<<r1->getDenominateur();
                }
                else
                {
                    int value;
                    value=temp.toInt();
                    Rationnel *r = new Rationnel(value,1);
                    _pileStockage.push(r);

                    Rationnel *r1=new Rationnel(_pileStockage.top());
                    qDebug()<<"\nNumérateur : "<<r1->getNumerateur();
                    qDebug()<<"\nDénominateur : "<<r1->getDenominateur();
                }

            }

            else if(_modConstante==entier)
            {
                int value = temp.toInt();
                Entier *e = new Entier(value);
                _pileStockage.push(e);
                Entier *e1 = new Entier(_pileStockage.top());
                qDebug()<<"\nvaleur entier : "<<e1->getValeur();
            }
            else if(_modConstante==reel)
            {
                float value = temp.toDouble();
                Reel *re= new Reel(value);
                _pileStockage.push(re);
                Reel *re1=new Reel(_pileStockage.top());
                qDebug()<<"\nvaleur réel : "<<re1->getValeur();
            }
            rat=false;
        }

    }
}}}
/*
else
{
    foreach(QString temp, list)
    {
            if(temp.at(0)=='+')
            {
                Complexe c;
                c=sum_comp(_pileStockageComplexe,2);

                qDebug()<<"\nsomme partie réelle= "<<c.getPartieReelle();
                qDebug()<<"\nsomme partie imaginaire= "<<c.getPartieImaginaire();
            }

            else if(temp.at(0)=='*')
            {
                Complexe c;
                c=prod_comp(_pileStockageComplexe);

                qDebug()<<"\nproduit partie réelle= "<<c.getPartieReelle();
                qDebug()<<"\nproduit partie imaginaire= "<<c.getPartieImaginaire();
            }

            else if(temp.at(0)=='/')
            {
                //res2=divise(_pileStockageComplexe);

                qDebug()<<"\nquotient = "<<res2;
            }

            else if(temp.at(0)=='-')
            {
                Complexe c;
                c=diff_comp(_pileStockageComplexe);
                qDebug()<<"\ndiff partie réelle= "<<c.getPartieReelle();
                qDebug()<<"\ndiff partie imaginaire= "<<c.getPartieImaginaire();

            }



            else if(temp.at(0)=='!')
            {
                res2=fact(_pileStockageReelle.pop());
                empiler(res2);
                qDebug()<<"\nfactoriel : "<<_pileStockageReelle.top();
            }

            else if(temp[0]>='0' && temp[0]<='9')
            {

                for(int i=0;i<temp.size();i++)
                {
                    if(temp[i]=='$')
                        reel_pur=true;

                }

                if(reel_pur==true)
                {
                QStringList list2 = temp.split('$');


                    Complexe c(list2.at(0).toDouble(),list2.at(1).toDouble());
                    _pileStockageComplexe.push(c);
                    Complexe c1;
                    c1=_pileStockageComplexe.top();

                    qDebug()<<"\nPartie réelle : "<<c1.getPartieReelle();
                    qDebug()<<"\nPartie imaginaire : "<<c1.getPartieImaginaire();

                }
                else
                {
                    Complexe c(temp.toDouble(),0);
                    _pileStockageComplexe.push(c);
                    Complexe c1;
                    c1=_pileStockageComplexe.top();

                    qDebug()<<"\nPartie réelle : "<<c1.getPartieReelle();
                    qDebug()<<"\nPartie imaginaire : "<<c1.getPartieImaginaire();
                }
                reel_pur=false;
            }




    }


}*/

        //on regarde le premier caractÃ?re
          /*  if (temp[i]=='\'') {
                //c'est une expression
                //on fusionne les strings suivante jusqu'Ã  rencontrer' Ã  la fin d'une string
                //il faut vÃ©rifier que le denier caractÃ?re est bien un '
                //on empile
            } else if (temp[i]=='+' || temp[i]=='-' || temp[i]=='*' || temp[i]=='/') {
                //c'est un opÃ©rateur
                //on vÃ©rifie que temp.size()==1
                //on dÃ©pile les deux derniers
                //on effectue le calcul
                //on rempile le rÃ©sultat
            } else if (temp[i]>='0' && temp[i]<='9') {
                //c'est un chiffre

            } else if (temp[i]=='$'){
                //c'est l'oprÃ©rateur de sÃ©paration des complexes
            } else if (temp[i]=='/') {
                //on a un problÃ?me car on ne sait pas diffÃ©rencier l'opÃ©rateur diviser du sÃ©parateur de rationnel en entrÃ©e
            }

    }*/




    /*if(_modComplexe)
        {
            while(temp[i]!=NULL)
            {
                while(temp[i]!=' ')
                {
                if(temp[i]>='0' && temp[i]<='9')
                {
                    res=temp[i].toAscii()-48;
                    _pileStockageComplexe.push(res);


                }
                else if(temp[i]=='+' || temp[i]=='-' || temp[i]=='*' || temp[i]=='/')
                {
                  /*  if(temp[i]=='+')
                        qDebug()<<"\nsomme : "<<sum(_pileStockageComplexe,2)<<"\n";
                    if(temp[i]=='*')
                        qDebug()<<"\nproduit : "<<prod(_pileStockageComplexe)<<"\n";
                    if(temp[i]=='/')
                        qDebug()<<"\ndivision : "<<divise(_pileStockageComplexe)<<"\n";*/
       /*         }

                i++;
            }
        }
        }
    else
        {
            while(temp[i]!=NULL)
            {

                while(temp[i]>='0' && temp[i]<='9' && temp[i]!=' ')
                {

                    res2=pow(10,res)*(temp[i].toAscii()-48);
                    res=res+1;
                    res3=res3+res2;
                    qDebug()<<"\n"<<res3;

                    i++;

                }
                _pileStockageReelle.push(res3);
                res3=0;
                res=0;
                qDebug()<<"\ntest : "<<_pileStockageReelle.top();
               if(temp[i]=='+' || temp[i]=='-' || temp[i]=='*' || temp[i]=='/')
                {
                    if(temp[i]=='+')
                        qDebug()<<"\nsomme : "<<sum(_pileStockageReelle,2)<<"\n";
                    if(temp[i]=='*')
                        qDebug()<<"\nproduit : "<<prod(_pileStockageReelle)<<"\n";
                    if(temp[i]=='/')
                        qDebug()<<"\ndivision : "<<divise(_pileStockageReelle)<<"\n";
                }

                i++;

  }
}
 //   for(int i=0; i<list.size(); i++)
        //non1'exp1'non2'exp2'non3
//        ui->inputLine->setText(ui->inputLine->text()+list.at(i)+"    ");
}
}
*/
//qDebug()<<"\nj = "<<j;

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::empiler(float r)
{
    _pileStockageReelle.push(r);
}


void MainWindow::traitement_expr(QString s)
{
    QString s2;

    QStringList list = s.split('\'');
    foreach(QString temp, list)
    {
        qDebug()<<"\n"<<temp;
        if(temp!=NULL && temp!=" ")
        {
            Expression* expr = new Expression(temp);
            _pileStockage.push(expr);
            Constante* ex2 = _pileStockage.top();
            qDebug()<<"\nexpression : "<<ex2->afficher();
        }
    }

}

bool MainWindow::verifInput(QString s)
{
    int i = 0;
/*    while (s[i] != NULL)
    {
        if(s[i]=='\'')
            return true;
        i++;
    }*/
    return false;
}

void traiter_contenu_inputLine (QString s){
    bool dans_une_exp = false;
    QString chaine;
    for (int i=0; i<s.length();i++){
        if(s.at(i) == '\''){
            if (dans_une_exp){
                //on était déjà dans une epxression donc on est sur le quote de sortie
//                ajout_pile_affichage(chaine); //cette fonction doit concat avec la chaine d'avant ?
                dans_une_exp = false;
                chaine = "";
            } else {
                //on rencontre le quote d'ouverture d'une chaine, ce qui était avant doit etre empilé/calculé
//              fonction_calcul(chaine);
                dans_une_exp = true;
                chaine = "";
            }
        } else {
            //qu'on soit ou non dans une chaine on ajoute ce caractère à la sous-chaine en cours
            chaine = chaine + s.at(i);
        }
    }
}
