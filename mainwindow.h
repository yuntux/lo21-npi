#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include "pile.h"


enum MesureAngle { degre, radian};
enum TypeConstante { entier, reel, rationnel};
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    enum MesureAngle _modAngle;
    enum TypeConstante _modConstante;
    bool _modComplexe;

    void afficheur_pile(Pile p);
    Pile _pileStockage;
    QStack<QString> _pileAffichage;
    QStack<float> _pileStockageReelle;
    QStack<Complexe> _pileStockageComplexe; //ATTENTION : vider la pile float lors du passage en  mode complexes

    void saveToFile();
    void loadFromFile();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void empiler(float r);

public slots:
   void POWClicked();
   void SINClicked();
   void COSClicked();
   void TANClicked();
   void SINHClicked();
   void COSHClicked();
   void TANHClicked();
   void MODClicked();
   void SIGNClicked();
   void LNClicked();
   void LOGClicked();
   void INVClicked();
   void SQRClicked();
   void SQRTClicked();
   void CUBEClicked();
   void QUOTEClicked();
   void CClicked();
   void CEClicked();
   void DOLLARClicked();
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
   void _modRadiansToggled(bool);
   void _modDegresToggled(bool);
   void _modReel(bool);
   void _modRationnel(bool);
   void _modEntier(bool);

   void ENTERClicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
