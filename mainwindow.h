#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
