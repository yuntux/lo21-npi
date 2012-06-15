/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Jun 15 13:04:02 2012
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
#include <QtGui/QListView>
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
    QWidget *widget_clavierBasic;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *_clavierBasicLayout;
    QPushButton *num7;
    QPushButton *num8;
    QPushButton *num9;
    QPushButton *num4;
    QPushButton *num5;
    QPushButton *num6;
    QPushButton *num1;
    QPushButton *num2;
    QPushButton *num3;
    QPushButton *num0;
    QPushButton *ENTER;
    QPushButton *DOLLAR;
    QPushButton *C;
    QPushButton *CE;
    QPushButton *SOUSTRAIRE;
    QPushButton *ADDITIONNER;
    QPushButton *DIVISER;
    QPushButton *MULTIPLIER;
    QPushButton *FACTORIEL;
    QPushButton *ESPACE;
    QPushButton *POINT;
    QPushButton *QUOTE;
    QPushButton *EVAL;
    QWidget *widget_clavierAvance;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *_clavierAvanceLayout;
    QPushButton *POW;
    QPushButton *SIN;
    QPushButton *SINH;
    QPushButton *LN;
    QPushButton *SQRT;
    QPushButton *MOD;
    QPushButton *COS;
    QPushButton *COSH;
    QPushButton *LOG;
    QPushButton *SQR;
    QPushButton *SIGN;
    QPushButton *TAN;
    QPushButton *TANH;
    QPushButton *INV;
    QPushButton *CUBE;
    QLineEdit *inputLine;
    QListView *listView;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_4;
    QRadioButton *_modComplexeON;
    QRadioButton *_modComplexeOFF;
    QGroupBox *groupBox;
    QRadioButton *_modDegres;
    QRadioButton *_modRadians;
    QGroupBox *groupBox_2;
    QRadioButton *_modEntiers;
    QRadioButton *_modRationnels;
    QRadioButton *_modReels;
    QGroupBox *groupBox_3;
    QCheckBox *_clavierBasic;
    QCheckBox *_clavierAvance;
    QPushButton *annuler;
    QPushButton *retablir;
    QPushButton *vider_pile;
    QPushButton *supprimer_tete_pile;
    QPushButton *dupliquer_tete_pile;
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
        widget_clavierBasic = new QWidget(centralWidget);
        widget_clavierBasic->setObjectName(QString::fromUtf8("widget_clavierBasic"));
        horizontalLayout_2 = new QHBoxLayout(widget_clavierBasic);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        _clavierBasicLayout = new QGridLayout();
        _clavierBasicLayout->setSpacing(6);
        _clavierBasicLayout->setObjectName(QString::fromUtf8("_clavierBasicLayout"));
        num7 = new QPushButton(widget_clavierBasic);
        num7->setObjectName(QString::fromUtf8("num7"));

        _clavierBasicLayout->addWidget(num7, 2, 0, 1, 1);

        num8 = new QPushButton(widget_clavierBasic);
        num8->setObjectName(QString::fromUtf8("num8"));

        _clavierBasicLayout->addWidget(num8, 2, 1, 1, 1);

        num9 = new QPushButton(widget_clavierBasic);
        num9->setObjectName(QString::fromUtf8("num9"));

        _clavierBasicLayout->addWidget(num9, 2, 2, 1, 1);

        num4 = new QPushButton(widget_clavierBasic);
        num4->setObjectName(QString::fromUtf8("num4"));

        _clavierBasicLayout->addWidget(num4, 3, 0, 1, 1);

        num5 = new QPushButton(widget_clavierBasic);
        num5->setObjectName(QString::fromUtf8("num5"));

        _clavierBasicLayout->addWidget(num5, 3, 1, 1, 1);

        num6 = new QPushButton(widget_clavierBasic);
        num6->setObjectName(QString::fromUtf8("num6"));

        _clavierBasicLayout->addWidget(num6, 3, 2, 1, 1);

        num1 = new QPushButton(widget_clavierBasic);
        num1->setObjectName(QString::fromUtf8("num1"));

        _clavierBasicLayout->addWidget(num1, 4, 0, 1, 1);

        num2 = new QPushButton(widget_clavierBasic);
        num2->setObjectName(QString::fromUtf8("num2"));

        _clavierBasicLayout->addWidget(num2, 4, 1, 1, 1);

        num3 = new QPushButton(widget_clavierBasic);
        num3->setObjectName(QString::fromUtf8("num3"));

        _clavierBasicLayout->addWidget(num3, 4, 2, 1, 1);

        num0 = new QPushButton(widget_clavierBasic);
        num0->setObjectName(QString::fromUtf8("num0"));

        _clavierBasicLayout->addWidget(num0, 5, 0, 1, 2);

        ENTER = new QPushButton(widget_clavierBasic);
        ENTER->setObjectName(QString::fromUtf8("ENTER"));

        _clavierBasicLayout->addWidget(ENTER, 7, 0, 1, 1);

        DOLLAR = new QPushButton(widget_clavierBasic);
        DOLLAR->setObjectName(QString::fromUtf8("DOLLAR"));

        _clavierBasicLayout->addWidget(DOLLAR, 7, 2, 1, 1);

        C = new QPushButton(widget_clavierBasic);
        C->setObjectName(QString::fromUtf8("C"));

        _clavierBasicLayout->addWidget(C, 8, 1, 1, 1);

        CE = new QPushButton(widget_clavierBasic);
        CE->setObjectName(QString::fromUtf8("CE"));

        _clavierBasicLayout->addWidget(CE, 8, 2, 1, 1);

        SOUSTRAIRE = new QPushButton(widget_clavierBasic);
        SOUSTRAIRE->setObjectName(QString::fromUtf8("SOUSTRAIRE"));

        _clavierBasicLayout->addWidget(SOUSTRAIRE, 3, 3, 1, 1);

        ADDITIONNER = new QPushButton(widget_clavierBasic);
        ADDITIONNER->setObjectName(QString::fromUtf8("ADDITIONNER"));

        _clavierBasicLayout->addWidget(ADDITIONNER, 2, 3, 1, 1);

        DIVISER = new QPushButton(widget_clavierBasic);
        DIVISER->setObjectName(QString::fromUtf8("DIVISER"));

        _clavierBasicLayout->addWidget(DIVISER, 4, 3, 1, 1);

        MULTIPLIER = new QPushButton(widget_clavierBasic);
        MULTIPLIER->setObjectName(QString::fromUtf8("MULTIPLIER"));

        _clavierBasicLayout->addWidget(MULTIPLIER, 5, 3, 1, 1);

        FACTORIEL = new QPushButton(widget_clavierBasic);
        FACTORIEL->setObjectName(QString::fromUtf8("FACTORIEL"));

        _clavierBasicLayout->addWidget(FACTORIEL, 7, 3, 1, 1);

        ESPACE = new QPushButton(widget_clavierBasic);
        ESPACE->setObjectName(QString::fromUtf8("ESPACE"));

        _clavierBasicLayout->addWidget(ESPACE, 8, 3, 1, 1);

        POINT = new QPushButton(widget_clavierBasic);
        POINT->setObjectName(QString::fromUtf8("POINT"));

        _clavierBasicLayout->addWidget(POINT, 5, 2, 1, 1);

        QUOTE = new QPushButton(widget_clavierBasic);
        QUOTE->setObjectName(QString::fromUtf8("QUOTE"));

        _clavierBasicLayout->addWidget(QUOTE, 7, 1, 1, 1);

        EVAL = new QPushButton(widget_clavierBasic);
        EVAL->setObjectName(QString::fromUtf8("EVAL"));

        _clavierBasicLayout->addWidget(EVAL, 8, 0, 1, 1);


        horizontalLayout_2->addLayout(_clavierBasicLayout);


        gridLayout->addWidget(widget_clavierBasic, 3, 0, 1, 1);

        widget_clavierAvance = new QWidget(centralWidget);
        widget_clavierAvance->setObjectName(QString::fromUtf8("widget_clavierAvance"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_clavierAvance->sizePolicy().hasHeightForWidth());
        widget_clavierAvance->setSizePolicy(sizePolicy);
        widget_clavierAvance->setMinimumSize(QSize(0, 0));
        horizontalLayout_3 = new QHBoxLayout(widget_clavierAvance);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        _clavierAvanceLayout = new QGridLayout();
        _clavierAvanceLayout->setSpacing(6);
        _clavierAvanceLayout->setObjectName(QString::fromUtf8("_clavierAvanceLayout"));
        POW = new QPushButton(widget_clavierAvance);
        POW->setObjectName(QString::fromUtf8("POW"));

        _clavierAvanceLayout->addWidget(POW, 0, 0, 1, 1);

        SIN = new QPushButton(widget_clavierAvance);
        SIN->setObjectName(QString::fromUtf8("SIN"));

        _clavierAvanceLayout->addWidget(SIN, 0, 1, 1, 1);

        SINH = new QPushButton(widget_clavierAvance);
        SINH->setObjectName(QString::fromUtf8("SINH"));

        _clavierAvanceLayout->addWidget(SINH, 0, 2, 1, 1);

        LN = new QPushButton(widget_clavierAvance);
        LN->setObjectName(QString::fromUtf8("LN"));

        _clavierAvanceLayout->addWidget(LN, 0, 3, 1, 1);

        SQRT = new QPushButton(widget_clavierAvance);
        SQRT->setObjectName(QString::fromUtf8("SQRT"));
        SQRT->setAutoExclusive(false);
        SQRT->setAutoDefault(false);
        SQRT->setDefault(false);
        SQRT->setFlat(false);

        _clavierAvanceLayout->addWidget(SQRT, 0, 4, 1, 1);

        MOD = new QPushButton(widget_clavierAvance);
        MOD->setObjectName(QString::fromUtf8("MOD"));

        _clavierAvanceLayout->addWidget(MOD, 1, 0, 1, 1);

        COS = new QPushButton(widget_clavierAvance);
        COS->setObjectName(QString::fromUtf8("COS"));

        _clavierAvanceLayout->addWidget(COS, 1, 1, 1, 1);

        COSH = new QPushButton(widget_clavierAvance);
        COSH->setObjectName(QString::fromUtf8("COSH"));

        _clavierAvanceLayout->addWidget(COSH, 1, 2, 1, 1);

        LOG = new QPushButton(widget_clavierAvance);
        LOG->setObjectName(QString::fromUtf8("LOG"));

        _clavierAvanceLayout->addWidget(LOG, 1, 3, 1, 1);

        SQR = new QPushButton(widget_clavierAvance);
        SQR->setObjectName(QString::fromUtf8("SQR"));

        _clavierAvanceLayout->addWidget(SQR, 1, 4, 1, 1);

        SIGN = new QPushButton(widget_clavierAvance);
        SIGN->setObjectName(QString::fromUtf8("SIGN"));

        _clavierAvanceLayout->addWidget(SIGN, 2, 0, 1, 1);

        TAN = new QPushButton(widget_clavierAvance);
        TAN->setObjectName(QString::fromUtf8("TAN"));

        _clavierAvanceLayout->addWidget(TAN, 2, 1, 1, 1);

        TANH = new QPushButton(widget_clavierAvance);
        TANH->setObjectName(QString::fromUtf8("TANH"));

        _clavierAvanceLayout->addWidget(TANH, 2, 2, 1, 1);

        INV = new QPushButton(widget_clavierAvance);
        INV->setObjectName(QString::fromUtf8("INV"));

        _clavierAvanceLayout->addWidget(INV, 2, 3, 1, 1);

        CUBE = new QPushButton(widget_clavierAvance);
        CUBE->setObjectName(QString::fromUtf8("CUBE"));

        _clavierAvanceLayout->addWidget(CUBE, 2, 4, 1, 1);


        horizontalLayout_3->addLayout(_clavierAvanceLayout);


        gridLayout->addWidget(widget_clavierAvance, 2, 0, 1, 1);

        inputLine = new QLineEdit(centralWidget);
        inputLine->setObjectName(QString::fromUtf8("inputLine"));
        inputLine->setEnabled(false);

        gridLayout->addWidget(inputLine, 1, 0, 1, 1);

        listView = new QListView(centralWidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        sizePolicy.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy);

        gridLayout->addWidget(listView, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);

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
        _modDegres = new QRadioButton(groupBox);
        _modDegres->setObjectName(QString::fromUtf8("_modDegres"));
        _modDegres->setGeometry(QRect(10, 10, 161, 20));
        _modDegres->setChecked(true);
        _modRadians = new QRadioButton(groupBox);
        _modRadians->setObjectName(QString::fromUtf8("_modRadians"));
        _modRadians->setGeometry(QRect(10, 30, 161, 20));

        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        _modEntiers = new QRadioButton(groupBox_2);
        _modEntiers->setObjectName(QString::fromUtf8("_modEntiers"));
        _modEntiers->setGeometry(QRect(10, 20, 143, 20));
        _modEntiers->setChecked(true);
        _modRationnels = new QRadioButton(groupBox_2);
        _modRationnels->setObjectName(QString::fromUtf8("_modRationnels"));
        _modRationnels->setGeometry(QRect(10, 40, 143, 20));
        _modReels = new QRadioButton(groupBox_2);
        _modReels->setObjectName(QString::fromUtf8("_modReels"));
        _modReels->setGeometry(QRect(10, 60, 143, 20));

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

        annuler = new QPushButton(centralWidget);
        annuler->setObjectName(QString::fromUtf8("annuler"));

        verticalLayout_2->addWidget(annuler);

        retablir = new QPushButton(centralWidget);
        retablir->setObjectName(QString::fromUtf8("retablir"));

        verticalLayout_2->addWidget(retablir);

        vider_pile = new QPushButton(centralWidget);
        vider_pile->setObjectName(QString::fromUtf8("vider_pile"));

        verticalLayout_2->addWidget(vider_pile);

        supprimer_tete_pile = new QPushButton(centralWidget);
        supprimer_tete_pile->setObjectName(QString::fromUtf8("supprimer_tete_pile"));

        verticalLayout_2->addWidget(supprimer_tete_pile);

        dupliquer_tete_pile = new QPushButton(centralWidget);
        dupliquer_tete_pile->setObjectName(QString::fromUtf8("dupliquer_tete_pile"));

        verticalLayout_2->addWidget(dupliquer_tete_pile);


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
        num9->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        num9->setShortcut(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        num4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        num4->setShortcut(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        num5->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        num5->setShortcut(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        num6->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        num6->setShortcut(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        num1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        num1->setShortcut(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        num2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        num2->setShortcut(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        num3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        num3->setShortcut(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        num0->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        num0->setShortcut(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        ENTER->setText(QApplication::translate("MainWindow", "ENTRER", 0, QApplication::UnicodeUTF8));
        DOLLAR->setText(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        DOLLAR->setShortcut(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        C->setText(QApplication::translate("MainWindow", "C", 0, QApplication::UnicodeUTF8));
        C->setShortcut(QApplication::translate("MainWindow", "Backspace", 0, QApplication::UnicodeUTF8));
        CE->setText(QApplication::translate("MainWindow", "CE", 0, QApplication::UnicodeUTF8));
        SOUSTRAIRE->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        SOUSTRAIRE->setShortcut(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        ADDITIONNER->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        ADDITIONNER->setShortcut(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        DIVISER->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        DIVISER->setShortcut(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        MULTIPLIER->setText(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        MULTIPLIER->setShortcut(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        FACTORIEL->setText(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        FACTORIEL->setShortcut(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        ESPACE->setText(QApplication::translate("MainWindow", "_", 0, QApplication::UnicodeUTF8));
        ESPACE->setShortcut(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
        POINT->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        POINT->setShortcut(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        QUOTE->setText(QApplication::translate("MainWindow", "'", 0, QApplication::UnicodeUTF8));
        QUOTE->setShortcut(QApplication::translate("MainWindow", "'", 0, QApplication::UnicodeUTF8));
        EVAL->setText(QApplication::translate("MainWindow", "EVAL", 0, QApplication::UnicodeUTF8));
        POW->setText(QApplication::translate("MainWindow", "POW", 0, QApplication::UnicodeUTF8));
        SIN->setText(QApplication::translate("MainWindow", "SIN", 0, QApplication::UnicodeUTF8));
        SINH->setText(QApplication::translate("MainWindow", "SINH", 0, QApplication::UnicodeUTF8));
        LN->setText(QApplication::translate("MainWindow", "LN", 0, QApplication::UnicodeUTF8));
        SQRT->setText(QApplication::translate("MainWindow", "SQRT", 0, QApplication::UnicodeUTF8));
        MOD->setText(QApplication::translate("MainWindow", "MOD", 0, QApplication::UnicodeUTF8));
        COS->setText(QApplication::translate("MainWindow", "COS", 0, QApplication::UnicodeUTF8));
        COSH->setText(QApplication::translate("MainWindow", "COSH", 0, QApplication::UnicodeUTF8));
        LOG->setText(QApplication::translate("MainWindow", "LOG", 0, QApplication::UnicodeUTF8));
        SQR->setText(QApplication::translate("MainWindow", "SQR", 0, QApplication::UnicodeUTF8));
        SIGN->setText(QApplication::translate("MainWindow", "SIGN", 0, QApplication::UnicodeUTF8));
        TAN->setText(QApplication::translate("MainWindow", "TAN", 0, QApplication::UnicodeUTF8));
        TANH->setText(QApplication::translate("MainWindow", "TANH", 0, QApplication::UnicodeUTF8));
        INV->setText(QApplication::translate("MainWindow", "INV", 0, QApplication::UnicodeUTF8));
        CUBE->setText(QApplication::translate("MainWindow", "CUBE", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Mode complexe", 0, QApplication::UnicodeUTF8));
        _modComplexeON->setText(QApplication::translate("MainWindow", "Activ\303\251s", 0, QApplication::UnicodeUTF8));
        _modComplexeOFF->setText(QApplication::translate("MainWindow", "D\303\251sactiv\303\251s", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Unit\303\251 de mesure", 0, QApplication::UnicodeUTF8));
        _modDegres->setText(QApplication::translate("MainWindow", "Degr\303\251s", 0, QApplication::UnicodeUTF8));
        _modRadians->setText(QApplication::translate("MainWindow", "Radians", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Type des constantes", 0, QApplication::UnicodeUTF8));
        _modEntiers->setText(QApplication::translate("MainWindow", "Enti\303\250res", 0, QApplication::UnicodeUTF8));
        _modRationnels->setText(QApplication::translate("MainWindow", "Rationnelles", 0, QApplication::UnicodeUTF8));
        _modReels->setText(QApplication::translate("MainWindow", "R\303\251elles", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Affichage claviers", 0, QApplication::UnicodeUTF8));
        _clavierBasic->setText(QApplication::translate("MainWindow", "&Basic", 0, QApplication::UnicodeUTF8));
        _clavierAvance->setText(QApplication::translate("MainWindow", "&Avanc\303\251", 0, QApplication::UnicodeUTF8));
        annuler->setText(QApplication::translate("MainWindow", "Annuler", 0, QApplication::UnicodeUTF8));
        retablir->setText(QApplication::translate("MainWindow", "R\303\251tablir", 0, QApplication::UnicodeUTF8));
        vider_pile->setText(QApplication::translate("MainWindow", "Vider Pile", 0, QApplication::UnicodeUTF8));
        supprimer_tete_pile->setText(QApplication::translate("MainWindow", "Supprimer la t\303\252te", 0, QApplication::UnicodeUTF8));
        dupliquer_tete_pile->setText(QApplication::translate("MainWindow", "Dupliquer la t\303\252te", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
