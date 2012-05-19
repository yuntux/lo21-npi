#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include "TypeDonnee.h"

enum MesureAngle { degre, radian};
enum TypeConstante { entier, reel, rationnel};
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    enum MesureAngle _modAngles;
    enum TypeConstante _modConstante;
    bool _modComplexe;
    QStack<std::string> _pileAffichage;
    QStack<float> _pileStockageReelle;
    QStack<Complexe> _pileStockageComplexe; //ATTENTION : vider la pile float lors du passage en  mode complexes

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
   void num0Clicked();
   void num1Clicked();
   void num2Clicked();
   void num3Clicked();
   void num4Clicked();
   void num5Clicked();
   void num6Clicked();
   void num7Clicked();
   void num8Clicked();
   void num9Clicked();
   void POINTClicked();
   void ESPACEClicked();
   void FACTORIELClicked();
   void ADDITIONNERClicked();
   void SOUSTRAIREClicked();
   void MULTIPLIERClicked();
   void DIVISERClicked();
   void _clavierBasicStateChange(int);
   void _clavierAvanceStateChange(int);
   void _modComplexeONClicked(bool);
   void _modComplexeOFFClicked(bool);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
