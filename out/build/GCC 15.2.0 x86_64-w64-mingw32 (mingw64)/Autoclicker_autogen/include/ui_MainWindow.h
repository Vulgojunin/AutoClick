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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
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
    QSpinBox *spinBoxInterval;
    QComboBox *comboBox;
    QComboBox *comboBoxStrategy;
    QSpinBox *spinBoxJitter;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonStop;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(300, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        spinBoxInterval = new QSpinBox(centralwidget);
        spinBoxInterval->setObjectName("spinBoxInterval");
        spinBoxInterval->setMaximum(99999);
        spinBoxInterval->setValue(100);

        verticalLayout->addWidget(spinBoxInterval);

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");

        verticalLayout->addWidget(comboBox);

        comboBoxStrategy = new QComboBox(centralwidget);
        comboBoxStrategy->setObjectName("comboBoxStrategy");

        verticalLayout->addWidget(comboBoxStrategy);

        spinBoxJitter = new QSpinBox(centralwidget);
        spinBoxJitter->setObjectName("spinBoxJitter");

        verticalLayout->addWidget(spinBoxJitter);

        pushButtonStart = new QPushButton(centralwidget);
        pushButtonStart->setObjectName("pushButtonStart");

        verticalLayout->addWidget(pushButtonStart);

        pushButtonStop = new QPushButton(centralwidget);
        pushButtonStop->setObjectName("pushButtonStop");

        verticalLayout->addWidget(pushButtonStop);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Bento AutoClicker PRO", nullptr));
        spinBoxInterval->setSuffix(QCoreApplication::translate("MainWindow", " ms", nullptr));
        spinBoxJitter->setSuffix(QCoreApplication::translate("MainWindow", " ms (Jitter)", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pushButtonStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
