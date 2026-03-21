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
#include <QtWidgets/QCheckBox>
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
    QSpinBox *intervalSpin;
    QComboBox *actionCombo;
    QCheckBox *jitterCheck;
    QSpinBox *jitterSpin;
    QPushButton *startBtn;
    QPushButton *stopBtn;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 300);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        intervalSpin = new QSpinBox(centralwidget);
        intervalSpin->setObjectName("intervalSpin");
        intervalSpin->setMaximum(999999);
        intervalSpin->setValue(1000);

        verticalLayout->addWidget(intervalSpin);

        actionCombo = new QComboBox(centralwidget);
        actionCombo->setObjectName("actionCombo");

        verticalLayout->addWidget(actionCombo);

        jitterCheck = new QCheckBox(centralwidget);
        jitterCheck->setObjectName("jitterCheck");

        verticalLayout->addWidget(jitterCheck);

        jitterSpin = new QSpinBox(centralwidget);
        jitterSpin->setObjectName("jitterSpin");

        verticalLayout->addWidget(jitterSpin);

        startBtn = new QPushButton(centralwidget);
        startBtn->setObjectName("startBtn");

        verticalLayout->addWidget(startBtn);

        stopBtn = new QPushButton(centralwidget);
        stopBtn->setObjectName("stopBtn");

        verticalLayout->addWidget(stopBtn);

        MainWindow->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Autoclicker Bento v1.0", nullptr));
        intervalSpin->setSuffix(QCoreApplication::translate("MainWindow", " ms", nullptr));
        jitterCheck->setText(QCoreApplication::translate("MainWindow", "Ativar Jitter (Humano)", nullptr));
        jitterSpin->setSuffix(QCoreApplication::translate("MainWindow", " ms", nullptr));
        startBtn->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        stopBtn->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
