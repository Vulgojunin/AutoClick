/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxInterval;
    QHBoxLayout *hLayout;
    QLabel *lH;
    QSpinBox *spinBoxHours;
    QLabel *lM;
    QSpinBox *spinBoxMins;
    QLabel *lS;
    QSpinBox *spinBoxSecs;
    QLabel *lMs;
    QSpinBox *spinBoxMs;
    QGroupBox *groupBoxOptions;
    QVBoxLayout *vLayoutOpt;
    QComboBox *comboBoxButton;
    QComboBox *comboBoxType;
    QGroupBox *groupBoxRepeat;
    QVBoxLayout *vLayoutRep;
    QRadioButton *radioInfinite;
    QHBoxLayout *hLayoutRep;
    QRadioButton *radioRepeat;
    QSpinBox *spinBoxTimes;
    QLabel *lT;
    QHBoxLayout *hLayoutBtns;
    QPushButton *pushButtonStop;
    QPushButton *pushButtonStart;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(420, 380);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        groupBoxInterval = new QGroupBox(centralwidget);
        groupBoxInterval->setObjectName("groupBoxInterval");
        hLayout = new QHBoxLayout(groupBoxInterval);
        hLayout->setObjectName("hLayout");
        lH = new QLabel(groupBoxInterval);
        lH->setObjectName("lH");

        hLayout->addWidget(lH);

        spinBoxHours = new QSpinBox(groupBoxInterval);
        spinBoxHours->setObjectName("spinBoxHours");

        hLayout->addWidget(spinBoxHours);

        lM = new QLabel(groupBoxInterval);
        lM->setObjectName("lM");

        hLayout->addWidget(lM);

        spinBoxMins = new QSpinBox(groupBoxInterval);
        spinBoxMins->setObjectName("spinBoxMins");

        hLayout->addWidget(spinBoxMins);

        lS = new QLabel(groupBoxInterval);
        lS->setObjectName("lS");

        hLayout->addWidget(lS);

        spinBoxSecs = new QSpinBox(groupBoxInterval);
        spinBoxSecs->setObjectName("spinBoxSecs");

        hLayout->addWidget(spinBoxSecs);

        lMs = new QLabel(groupBoxInterval);
        lMs->setObjectName("lMs");

        hLayout->addWidget(lMs);

        spinBoxMs = new QSpinBox(groupBoxInterval);
        spinBoxMs->setObjectName("spinBoxMs");
        spinBoxMs->setMaximum(999);

        hLayout->addWidget(spinBoxMs);


        verticalLayout->addWidget(groupBoxInterval);

        groupBoxOptions = new QGroupBox(centralwidget);
        groupBoxOptions->setObjectName("groupBoxOptions");
        vLayoutOpt = new QVBoxLayout(groupBoxOptions);
        vLayoutOpt->setObjectName("vLayoutOpt");
        comboBoxButton = new QComboBox(groupBoxOptions);
        comboBoxButton->setObjectName("comboBoxButton");

        vLayoutOpt->addWidget(comboBoxButton);

        comboBoxType = new QComboBox(groupBoxOptions);
        comboBoxType->setObjectName("comboBoxType");

        vLayoutOpt->addWidget(comboBoxType);


        verticalLayout->addWidget(groupBoxOptions);

        groupBoxRepeat = new QGroupBox(centralwidget);
        groupBoxRepeat->setObjectName("groupBoxRepeat");
        vLayoutRep = new QVBoxLayout(groupBoxRepeat);
        vLayoutRep->setObjectName("vLayoutRep");
        radioInfinite = new QRadioButton(groupBoxRepeat);
        radioInfinite->setObjectName("radioInfinite");

        vLayoutRep->addWidget(radioInfinite);

        hLayoutRep = new QHBoxLayout();
        hLayoutRep->setObjectName("hLayoutRep");
        radioRepeat = new QRadioButton(groupBoxRepeat);
        radioRepeat->setObjectName("radioRepeat");

        hLayoutRep->addWidget(radioRepeat);

        spinBoxTimes = new QSpinBox(groupBoxRepeat);
        spinBoxTimes->setObjectName("spinBoxTimes");
        spinBoxTimes->setMaximum(999999);

        hLayoutRep->addWidget(spinBoxTimes);

        lT = new QLabel(groupBoxRepeat);
        lT->setObjectName("lT");

        hLayoutRep->addWidget(lT);


        vLayoutRep->addLayout(hLayoutRep);


        verticalLayout->addWidget(groupBoxRepeat);

        hLayoutBtns = new QHBoxLayout();
        hLayoutBtns->setObjectName("hLayoutBtns");
        pushButtonStop = new QPushButton(centralwidget);
        pushButtonStop->setObjectName("pushButtonStop");

        hLayoutBtns->addWidget(pushButtonStop);

        pushButtonStart = new QPushButton(centralwidget);
        pushButtonStart->setObjectName("pushButtonStart");

        hLayoutBtns->addWidget(pushButtonStart);


        verticalLayout->addLayout(hLayoutBtns);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        groupBoxInterval->setTitle(QCoreApplication::translate("MainWindow", "Click Interval", nullptr));
        lH->setText(QCoreApplication::translate("MainWindow", "H:", nullptr));
        lM->setText(QCoreApplication::translate("MainWindow", "M:", nullptr));
        lS->setText(QCoreApplication::translate("MainWindow", "S:", nullptr));
        lMs->setText(QCoreApplication::translate("MainWindow", "Ms:", nullptr));
        groupBoxOptions->setTitle(QCoreApplication::translate("MainWindow", "Click Options", nullptr));
        groupBoxRepeat->setTitle(QCoreApplication::translate("MainWindow", "Click Repeat", nullptr));
        radioInfinite->setText(QCoreApplication::translate("MainWindow", "Repeat until stopped", nullptr));
        radioRepeat->setText(QCoreApplication::translate("MainWindow", "Repeat", nullptr));
        lT->setText(QCoreApplication::translate("MainWindow", "times", nullptr));
        pushButtonStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
