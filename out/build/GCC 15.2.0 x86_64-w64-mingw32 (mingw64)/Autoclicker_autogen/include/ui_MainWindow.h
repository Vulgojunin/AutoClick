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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayoutMain;
    QWidget *titleBar;
    QHBoxLayout *hLayoutTitle;
    QLabel *labelTitle;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnMinimize;
    QPushButton *btnClose;
    QGroupBox *groupBoxInterval;
    QHBoxLayout *hLayoutInterval;
    QLabel *labelH;
    QSpinBox *spinBoxHours;
    QLabel *labelM;
    QSpinBox *spinBoxMins;
    QLabel *labelS;
    QSpinBox *spinBoxSecs;
    QLabel *labelMs;
    QSpinBox *spinBoxMs;
    QGroupBox *groupBoxOptions;
    QVBoxLayout *vLayoutOptions;
    QComboBox *comboBoxButton;
    QComboBox *comboBoxType;
    QGroupBox *groupBoxRepeat;
    QVBoxLayout *vLayoutRepeat;
    QRadioButton *radioInfinite;
    QHBoxLayout *hLayoutRepeatTimes;
    QRadioButton *radioRepeat;
    QSpinBox *spinBoxTimes;
    QLabel *labelTimes;
    QHBoxLayout *hLayoutButtons;
    QPushButton *pushButtonStop;
    QPushButton *pushButtonStart;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(500, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutMain = new QVBoxLayout(centralwidget);
        verticalLayoutMain->setSpacing(10);
        verticalLayoutMain->setObjectName("verticalLayoutMain");
        verticalLayoutMain->setContentsMargins(35, 20, 35, 35);
        titleBar = new QWidget(centralwidget);
        titleBar->setObjectName("titleBar");
        titleBar->setMinimumSize(QSize(0, 40));
        hLayoutTitle = new QHBoxLayout(titleBar);
        hLayoutTitle->setContentsMargins(0, 0, 0, 0);
        hLayoutTitle->setObjectName("hLayoutTitle");
        labelTitle = new QLabel(titleBar);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setStyleSheet(QString::fromUtf8("font-weight: bold; color: #00d2ff; margin-left: 10px;"));

        hLayoutTitle->addWidget(labelTitle);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hLayoutTitle->addItem(horizontalSpacer);

        btnMinimize = new QPushButton(titleBar);
        btnMinimize->setObjectName("btnMinimize");

        hLayoutTitle->addWidget(btnMinimize);

        btnClose = new QPushButton(titleBar);
        btnClose->setObjectName("btnClose");

        hLayoutTitle->addWidget(btnClose);


        verticalLayoutMain->addWidget(titleBar);

        groupBoxInterval = new QGroupBox(centralwidget);
        groupBoxInterval->setObjectName("groupBoxInterval");
        hLayoutInterval = new QHBoxLayout(groupBoxInterval);
        hLayoutInterval->setObjectName("hLayoutInterval");
        labelH = new QLabel(groupBoxInterval);
        labelH->setObjectName("labelH");

        hLayoutInterval->addWidget(labelH);

        spinBoxHours = new QSpinBox(groupBoxInterval);
        spinBoxHours->setObjectName("spinBoxHours");

        hLayoutInterval->addWidget(spinBoxHours);

        labelM = new QLabel(groupBoxInterval);
        labelM->setObjectName("labelM");

        hLayoutInterval->addWidget(labelM);

        spinBoxMins = new QSpinBox(groupBoxInterval);
        spinBoxMins->setObjectName("spinBoxMins");

        hLayoutInterval->addWidget(spinBoxMins);

        labelS = new QLabel(groupBoxInterval);
        labelS->setObjectName("labelS");

        hLayoutInterval->addWidget(labelS);

        spinBoxSecs = new QSpinBox(groupBoxInterval);
        spinBoxSecs->setObjectName("spinBoxSecs");

        hLayoutInterval->addWidget(spinBoxSecs);

        labelMs = new QLabel(groupBoxInterval);
        labelMs->setObjectName("labelMs");

        hLayoutInterval->addWidget(labelMs);

        spinBoxMs = new QSpinBox(groupBoxInterval);
        spinBoxMs->setObjectName("spinBoxMs");
        spinBoxMs->setMaximum(999);

        hLayoutInterval->addWidget(spinBoxMs);


        verticalLayoutMain->addWidget(groupBoxInterval);

        groupBoxOptions = new QGroupBox(centralwidget);
        groupBoxOptions->setObjectName("groupBoxOptions");
        vLayoutOptions = new QVBoxLayout(groupBoxOptions);
        vLayoutOptions->setObjectName("vLayoutOptions");
        comboBoxButton = new QComboBox(groupBoxOptions);
        comboBoxButton->setObjectName("comboBoxButton");

        vLayoutOptions->addWidget(comboBoxButton);

        comboBoxType = new QComboBox(groupBoxOptions);
        comboBoxType->setObjectName("comboBoxType");

        vLayoutOptions->addWidget(comboBoxType);


        verticalLayoutMain->addWidget(groupBoxOptions);

        groupBoxRepeat = new QGroupBox(centralwidget);
        groupBoxRepeat->setObjectName("groupBoxRepeat");
        vLayoutRepeat = new QVBoxLayout(groupBoxRepeat);
        vLayoutRepeat->setObjectName("vLayoutRepeat");
        radioInfinite = new QRadioButton(groupBoxRepeat);
        radioInfinite->setObjectName("radioInfinite");

        vLayoutRepeat->addWidget(radioInfinite);

        hLayoutRepeatTimes = new QHBoxLayout();
        hLayoutRepeatTimes->setObjectName("hLayoutRepeatTimes");
        radioRepeat = new QRadioButton(groupBoxRepeat);
        radioRepeat->setObjectName("radioRepeat");

        hLayoutRepeatTimes->addWidget(radioRepeat);

        spinBoxTimes = new QSpinBox(groupBoxRepeat);
        spinBoxTimes->setObjectName("spinBoxTimes");
        spinBoxTimes->setMaximum(999999);

        hLayoutRepeatTimes->addWidget(spinBoxTimes);

        labelTimes = new QLabel(groupBoxRepeat);
        labelTimes->setObjectName("labelTimes");

        hLayoutRepeatTimes->addWidget(labelTimes);


        vLayoutRepeat->addLayout(hLayoutRepeatTimes);


        verticalLayoutMain->addWidget(groupBoxRepeat);

        hLayoutButtons = new QHBoxLayout();
        hLayoutButtons->setSpacing(20);
        hLayoutButtons->setObjectName("hLayoutButtons");
        pushButtonStop = new QPushButton(centralwidget);
        pushButtonStop->setObjectName("pushButtonStop");

        hLayoutButtons->addWidget(pushButtonStop);

        pushButtonStart = new QPushButton(centralwidget);
        pushButtonStart->setObjectName("pushButtonStart");

        hLayoutButtons->addWidget(pushButtonStart);


        verticalLayoutMain->addLayout(hLayoutButtons);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "A AutoClick", nullptr));
        labelTitle->setText(QCoreApplication::translate("MainWindow", "\342\232\241 A AutoClick", nullptr));
        btnMinimize->setText(QCoreApplication::translate("MainWindow", "\342\200\223", nullptr));
        btnClose->setText(QCoreApplication::translate("MainWindow", "\342\234\225", nullptr));
        groupBoxInterval->setTitle(QCoreApplication::translate("MainWindow", "Click Interval", nullptr));
        labelH->setText(QCoreApplication::translate("MainWindow", "H:", nullptr));
        labelM->setText(QCoreApplication::translate("MainWindow", "M:", nullptr));
        labelS->setText(QCoreApplication::translate("MainWindow", "S:", nullptr));
        labelMs->setText(QCoreApplication::translate("MainWindow", "Ms:", nullptr));
        groupBoxOptions->setTitle(QCoreApplication::translate("MainWindow", "Click Options", nullptr));
        groupBoxRepeat->setTitle(QCoreApplication::translate("MainWindow", "Click Repeat", nullptr));
        radioInfinite->setText(QCoreApplication::translate("MainWindow", "Repeat until stopped", nullptr));
        radioRepeat->setText(QCoreApplication::translate("MainWindow", "Repeat", nullptr));
        labelTimes->setText(QCoreApplication::translate("MainWindow", "times", nullptr));
        pushButtonStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
