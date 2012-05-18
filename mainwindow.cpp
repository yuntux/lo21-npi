#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStack>
#include "TypeDonnee.h"


enum MesureAngle { degre, radian};
enum TypeConstante { entier, reel, rationnel};


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    enum MesureAngle _modAngles;
    enum TypeConstante _modConstante;
    bool _modComplexe;
    QStack<std::string> _pileAffichage;
    QStack<float> _pileStockageReelle;
    QStack<Complexe> _pileStockageComplexe; //ATTENTION : vider la pile float lors du passage en  mode complexes

    ui->setupUi(this);
    connect(ui->num0, SIGNAL(clicked()), this, SLOT(num0Clicked()));

}

void MainWindow::num0Clicked(){
    QString temp = ui->inputLine->text();
    temp= temp+"0";
    ui->inputLine->setText(temp);
}

MainWindow::~MainWindow()
{
    delete ui;
}
