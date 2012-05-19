/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat May 19 16:16:06 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_propos;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLineEdit *inputLine;
    QListWidget *listWidget;
    QGridLayout *_clavierBasicLayout;
    QPushButton *num7;
    QPushButton *num8;
    QPushButton *num4;
    QPushButton *num5;
    QPushButton *num9;
    QPushButton *num6;
    QPushButton *num2;
    QPushButton *num1;
    QPushButton *num3;
    QPushButton *num0;
    QPushButton *POINT;
    QPushButton *EVAL;
    QPushButton *ESPACE;
    QPushButton *ENTER;
    QPushButton *CE;
    QGridLayout *_clavierAvanceLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_8;
    QPushButton *pushButton_20;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QPushButton *pushButton_25;
    QPushButton *pushButton_26;
    QPushButton *pushButton_27;
    QPushButton *pushButton_28;
    QPushButton *pushButton_29;
    QPushButton *pushButton_30;
    QPushButton *FACTORIEL;
    QPushButton *DIVISER;
    QPushButton *MULTIPLIER;
    QPushButton *SOUSTRAIRE;
    QPushButton *ADDITIONNER;
    QPushButton *pushButton_4;
    QPushButton *pushButton_31;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_4;
    QRadioButton *_modComplexeON;
    QRadioButton *_modComplexeOFF;
    QGroupBox *groupBox;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QGroupBox *groupBox_3;
    QCheckBox *_clavierBasic;
    QCheckBox *_clavierAvance;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(958, 723);
        action_propos = new QAction(MainWindow);
        action_propos->setObjectName(QString::fromUtf8("action_propos"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        inputLine = new QLineEdit(centralWidget);
        inputLine->setObjectName(QString::fromUtf8("inputLine"));
        inputLine->setEnabled(false);

        gridLayout->addWidget(inputLine, 2, 0, 1, 1);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 1, 0, 1, 1);

        _clavierBasicLayout = new QGridLayout();
        _clavierBasicLayout->setSpacing(6);
        _clavierBasicLayout->setObjectName(QString::fromUtf8("_clavierBasicLayout"));
        num7 = new QPushButton(centralWidget);
        num7->setObjectName(QString::fromUtf8("num7"));

        _clavierBasicLayout->addWidget(num7, 0, 0, 1, 1);

        num8 = new QPushButton(centralWidget);
        num8->setObjectName(QString::fromUtf8("num8"));

        _clavierBasicLayout->addWidget(num8, 0, 1, 1, 1);

        num4 = new QPushButton(centralWidget);
        num4->setObjectName(QString::fromUtf8("num4"));

        _clavierBasicLayout->addWidget(num4, 1, 0, 1, 1);

        num5 = new QPushButton(centralWidget);
        num5->setObjectName(QString::fromUtf8("num5"));

        _clavierBasicLayout->addWidget(num5, 1, 1, 1, 1);

        num9 = new QPushButton(centralWidget);
        num9->setObjectName(QString::fromUtf8("num9"));

        _clavierBasicLayout->addWidget(num9, 0, 2, 1, 1);

        num6 = new QPushButton(centralWidget);
        num6->setObjectName(QString::fromUtf8("num6"));

        _clavierBasicLayout->addWidget(num6, 1, 2, 1, 1);

        num2 = new QPushButton(centralWidget);
        num2->setObjectName(QString::fromUtf8("num2"));

        _clavierBasicLayout->addWidget(num2, 2, 1, 1, 1);

        num1 = new QPushButton(centralWidget);
        num1->setObjectName(QString::fromUtf8("num1"));

        _clavierBasicLayout->addWidget(num1, 2, 0, 1, 1);

        num3 = new QPushButton(centralWidget);
        num3->setObjectName(QString::fromUtf8("num3"));

        _clavierBasicLayout->addWidget(num3, 2, 2, 1, 1);

        num0 = new QPushButton(centralWidget);
        num0->setObjectName(QString::fromUtf8("num0"));

        _clavierBasicLayout->addWidget(num0, 3, 0, 1, 1);

        POINT = new QPushButton(centralWidget);
        POINT->setObjectName(QString::fromUtf8("POINT"));

        _clavierBasicLayout->addWidget(POINT, 3, 1, 1, 1);

        EVAL = new QPushButton(centralWidget);
        EVAL->setObjectName(QString::fromUtf8("EVAL"));

        _clavierBasicLayout->addWidget(EVAL, 4, 1, 1, 1);

        ESPACE = new QPushButton(centralWidget);
        ESPACE->setObjectName(QString::fromUtf8("ESPACE"));

        _clavierBasicLayout->addWidget(ESPACE, 3, 2, 1, 1);

        ENTER = new QPushButton(centralWidget);
        ENTER->setObjectName(QString::fromUtf8("ENTER"));

        _clavierBasicLayout->addWidget(ENTER, 4, 0, 1, 1);

        CE = new QPushButton(centralWidget);
        CE->setObjectName(QString::fromUtf8("CE"));

        _clavierBasicLayout->addWidget(CE, 4, 2, 1, 1);


        gridLayout->addLayout(_clavierBasicLayout, 4, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        _clavierAvanceLayout = new QGridLayout();
        _clavierAvanceLayout->setSpacing(6);
        _clavierAvanceLayout->setObjectName(QString::fromUtf8("_clavierAvanceLayout"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        _clavierAvanceLayout->addWidget(pushButton_2, 0, 0, 1, 1);

        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        _clavierAvanceLayout->addWidget(pushButton_8, 1, 0, 1, 1);

        pushButton_20 = new QPushButton(centralWidget);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));

        _clavierAvanceLayout->addWidget(pushButton_20, 1, 4, 1, 1);

        pushButton_21 = new QPushButton(centralWidget);
        pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));

        _clavierAvanceLayout->addWidget(pushButton_21, 1, 2, 1, 1);

        pushButton_22 = new QPushButton(centralWidget);
        pushButton_22->setObjectName(QString::fromUtf8("pushButton_22"));

        _clavierAvanceLayout->addWidget(pushButton_22, 0, 2, 1, 1);

        pushButton_23 = new QPushButton(centralWidget);
        pushButton_23->setObjectName(QString::fromUtf8("pushButton_23"));

        _clavierAvanceLayout->addWidget(pushButton_23, 0, 3, 1, 1);

        pushButton_24 = new QPushButton(centralWidget);
        pushButton_24->setObjectName(QString::fromUtf8("pushButton_24"));

        _clavierAvanceLayout->addWidget(pushButton_24, 1, 3, 1, 1);

        pushButton_25 = new QPushButton(centralWidget);
        pushButton_25->setObjectName(QString::fromUtf8("pushButton_25"));

        _clavierAvanceLayout->addWidget(pushButton_25, 0, 1, 1, 1);

        pushButton_26 = new QPushButton(centralWidget);
        pushButton_26->setObjectName(QString::fromUtf8("pushButton_26"));

        _clavierAvanceLayout->addWidget(pushButton_26, 1, 1, 1, 1);

        pushButton_27 = new QPushButton(centralWidget);
        pushButton_27->setObjectName(QString::fromUtf8("pushButton_27"));

        _clavierAvanceLayout->addWidget(pushButton_27, 2, 0, 1, 1);

        pushButton_28 = new QPushButton(centralWidget);
        pushButton_28->setObjectName(QString::fromUtf8("pushButton_28"));

        _clavierAvanceLayout->addWidget(pushButton_28, 2, 1, 1, 1);

        pushButton_29 = new QPushButton(centralWidget);
        pushButton_29->setObjectName(QString::fromUtf8("pushButton_29"));

        _clavierAvanceLayout->addWidget(pushButton_29, 2, 2, 1, 1);

        pushButton_30 = new QPushButton(centralWidget);
        pushButton_30->setObjectName(QString::fromUtf8("pushButton_30"));

        _clavierAvanceLayout->addWidget(pushButton_30, 2, 3, 1, 1);

        FACTORIEL = new QPushButton(centralWidget);
        FACTORIEL->setObjectName(QString::fromUtf8("FACTORIEL"));

        _clavierAvanceLayout->addWidget(FACTORIEL, 3, 0, 1, 1);

        DIVISER = new QPushButton(centralWidget);
        DIVISER->setObjectName(QString::fromUtf8("DIVISER"));

        _clavierAvanceLayout->addWidget(DIVISER, 3, 2, 1, 1);

        MULTIPLIER = new QPushButton(centralWidget);
        MULTIPLIER->setObjectName(QString::fromUtf8("MULTIPLIER"));

        _clavierAvanceLayout->addWidget(MULTIPLIER, 3, 1, 1, 1);

        SOUSTRAIRE = new QPushButton(centralWidget);
        SOUSTRAIRE->setObjectName(QString::fromUtf8("SOUSTRAIRE"));

        _clavierAvanceLayout->addWidget(SOUSTRAIRE, 3, 3, 1, 1);

        ADDITIONNER = new QPushButton(centralWidget);
        ADDITIONNER->setObjectName(QString::fromUtf8("ADDITIONNER"));

        _clavierAvanceLayout->addWidget(ADDITIONNER, 3, 4, 1, 1);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        _clavierAvanceLayout->addWidget(pushButton_4, 0, 4, 1, 1);

        pushButton_31 = new QPushButton(centralWidget);
        pushButton_31->setObjectName(QString::fromUtf8("pushButton_31"));

        _clavierAvanceLayout->addWidget(pushButton_31, 2, 4, 1, 1);


        horizontalLayout->addLayout(_clavierAvanceLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        _modComplexeON = new QRadioButton(groupBox_4);
        _modComplexeON->setObjectName(QString::fromUtf8("_modComplexeON"));
        _modComplexeON->setGeometry(QRect(10, 20, 143, 20));
        _modComplexeON->setChecked(true);
        _modComplexeOFF = new QRadioButton(groupBox_4);
        _modComplexeOFF->setObjectName(QString::fromUtf8("_modComplexeOFF"));
        _modComplexeOFF->setGeometry(QRect(10, 40, 143, 20));

        verticalLayout_2->addWidget(groupBox_4);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(0, 10, 161, 20));
        radioButton_2->setChecked(true);
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(0, 30, 161, 20));
        radioButton_2->raise();
        radioButton->raise();
        groupBox_4->raise();

        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(0, 20, 143, 20));
        radioButton_3->setChecked(true);
        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(0, 40, 143, 20));
        radioButton_5 = new QRadioButton(groupBox_2);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setGeometry(QRect(0, 60, 143, 20));

        verticalLayout_2->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        _clavierBasic = new QCheckBox(groupBox_3);
        _clavierBasic->setObjectName(QString::fromUtf8("_clavierBasic"));
        _clavierBasic->setGeometry(QRect(10, 20, 143, 20));
        _clavierBasic->setChecked(true);
        _clavierAvance = new QCheckBox(groupBox_3);
        _clavierAvance->setObjectName(QString::fromUtf8("_clavierAvance"));
        _clavierAvance->setGeometry(QRect(10, 40, 143, 20));
        _clavierAvance->setChecked(true);

        verticalLayout_2->addWidget(groupBox_3);


        horizontalLayout->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 958, 22));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        MainWindow->insertToolBarBreak(mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menu->menuAction());
        menu->addAction(action_propos);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        action_propos->setText(QApplication::translate("MainWindow", "\303\200 propos", 0, QApplication::UnicodeUTF8));
        num7->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        num7->setShortcut(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        num8->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        num8->setShortcut(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        num4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        num4->setShortcut(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        num5->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        num5->setShortcut(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        num9->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        num9->setShortcut(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        num6->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        num6->setShortcut(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        num2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        num2->setShortcut(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        num1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        num1->setShortcut(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        num3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        num3->setShortcut(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        num0->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        num0->setShortcut(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        POINT->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        POINT->setShortcut(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        EVAL->setText(QApplication::translate("MainWindow", "EVAL", 0, QApplication::UnicodeUTF8));
        ESPACE->setText(QApplication::translate("MainWindow", "_", 0, QApplication::UnicodeUTF8));
        ESPACE->setShortcut(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
        ENTER->setText(QApplication::translate("MainWindow", "ENTRER", 0, QApplication::UnicodeUTF8));
        ENTER->setShortcut(QApplication::translate("MainWindow", "Enter", 0, QApplication::UnicodeUTF8));
        CE->setText(QApplication::translate("MainWindow", "CE", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "POW", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("MainWindow", "MOD", 0, QApplication::UnicodeUTF8));
        pushButton_20->setText(QApplication::translate("MainWindow", "SQR", 0, QApplication::UnicodeUTF8));
        pushButton_21->setText(QApplication::translate("MainWindow", "COSH", 0, QApplication::UnicodeUTF8));
        pushButton_22->setText(QApplication::translate("MainWindow", "SINH", 0, QApplication::UnicodeUTF8));
        pushButton_23->setText(QApplication::translate("MainWindow", "LN", 0, QApplication::UnicodeUTF8));
        pushButton_24->setText(QApplication::translate("MainWindow", "LOG", 0, QApplication::UnicodeUTF8));
        pushButton_25->setText(QApplication::translate("MainWindow", "SIN", 0, QApplication::UnicodeUTF8));
        pushButton_26->setText(QApplication::translate("MainWindow", "COS", 0, QApplication::UnicodeUTF8));
        pushButton_27->setText(QApplication::translate("MainWindow", "SIGN", 0, QApplication::UnicodeUTF8));
        pushButton_28->setText(QApplication::translate("MainWindow", "TAN", 0, QApplication::UnicodeUTF8));
        pushButton_29->setText(QApplication::translate("MainWindow", "TANH", 0, QApplication::UnicodeUTF8));
        pushButton_30->setText(QApplication::translate("MainWindow", "INV", 0, QApplication::UnicodeUTF8));
        FACTORIEL->setText(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        FACTORIEL->setShortcut(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        DIVISER->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        DIVISER->setShortcut(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        MULTIPLIER->setText(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        MULTIPLIER->setShortcut(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        SOUSTRAIRE->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        SOUSTRAIRE->setShortcut(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        ADDITIONNER->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        ADDITIONNER->setShortcut(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MainWindow", "SQRT", 0, QApplication::UnicodeUTF8));
        pushButton_31->setText(QApplication::translate("MainWindow", "CUBE", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Mode complexe", 0, QApplication::UnicodeUTF8));
        _modComplexeON->setText(QApplication::translate("MainWindow", "Activ\303\251s", 0, QApplication::UnicodeUTF8));
        _modComplexeOFF->setText(QApplication::translate("MainWindow", "D\303\251sactiv\303\251s", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Unit\303\251 de mesure", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("MainWindow", "Degr\303\251s", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("MainWindow", "Radians", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Type des constantes", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("MainWindow", "Enti\303\250res", 0, QApplication::UnicodeUTF8));
        radioButton_4->setText(QApplication::translate("MainWindow", "Rationnelles", 0, QApplication::UnicodeUTF8));
        radioButton_5->setText(QApplication::translate("MainWindow", "R\303\251elles", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Affichage claviers", 0, QApplication::UnicodeUTF8));
        _clavierBasic->setText(QApplication::translate("MainWindow", "&Basic", 0, QApplication::UnicodeUTF8));
        _clavierAvance->setText(QApplication::translate("MainWindow", "&Avanc\303\251", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
