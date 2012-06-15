/**
 * \file constante.h
 * \brief Calculatrice en polonais inversé. Classe de la GUI QT-MainWindow
 * \author Aurélien DUMAINE
 * \author Simon LANCELOT
 * \version 0.1
 * \date juin 2012
 *
 * Licence : GNU/GPL version 3 (http://www.gnu.org/copyleft/gpl.html)
 * Dépot Git : http://code.google.com/p/lo21-npi/
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include "pile.h"
#define PI 3.14159265

enum MesureAngle { degre, radian};
//enum TypeConstante { entier, reel, rationnel};
namespace Ui {
    class MainWindow;
}

    Constante* stringToConstante(QString s);

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    void closeEvent(QCloseEvent *event);
private:
    enum MesureAngle _modAngle;
    enum Type _modConstante;
    bool _modComplexe;

    Pile _pileStockage;
    QStack<QString> _pileAffichage;
    QStack<float> _pileStockageReelle;
    QStack<Complexe> _pileStockageComplexe; //ATTENTION : vider la pile float lors du passage en  mode complexes

    void loadFromFile();


public:
    explicit MainWindow(QWidget *parent = 0);
    void traitement_expr(QString s);
    bool dernier_element_expression(QString chaine);
    ~MainWindow();
    void empiler(float r);
    MesureAngle getAngle(){return _modAngle;}
    bool verifInput(QString s);
    void traiter_bloc_expression(QString s);
    void traiter_bloc_calcul(QString s);


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

   void retablirClicked();
   void annulerClicked();
   void ENTERClicked();
   void EVALClicked();
   void vider_pileClicked();
   void supprimer_tete_pileClicked();
   void dupliquer_tete_pileClicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
