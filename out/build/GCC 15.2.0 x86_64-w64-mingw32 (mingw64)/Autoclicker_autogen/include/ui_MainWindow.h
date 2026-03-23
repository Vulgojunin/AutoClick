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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
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
    QVBoxLayout *verticalLayout_main;
    QGroupBox *groupBoxInterval;
    QFormLayout *formLayoutInterval;
    QLabel *labelInterval;
    QSpinBox *spinBoxInterval;
    QLabel *labelJitter;
    QSpinBox *spinBoxJitter;
    QGroupBox *groupBoxOptions;
    QFormLayout *formLayoutOptions;
    QLabel *labelBotao;
    QComboBox *comboBox;
    QLabel *labelEstrategia;
    QComboBox *comboBoxStrategy;
    QGroupBox *groupBoxHotkeys;
    QFormLayout *formLayoutHotkeys;
    QLabel *labelStartKey;
    QComboBox *comboBoxStartKey;
    QLabel *labelStopKey;
    QComboBox *comboBoxStopKey;
    QLabel *labelMacroInfo;
    QHBoxLayout *horizontalLayoutButtons;
    QPushButton *pushButtonStop;
    QPushButton *pushButtonStart;
    QSpacerItem *verticalSpacer;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(380, 520);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_main = new QVBoxLayout(centralwidget);
        verticalLayout_main->setSpacing(15);
        verticalLayout_main->setObjectName("verticalLayout_main");
        verticalLayout_main->setContentsMargins(20, 20, 20, 20);
        groupBoxInterval = new QGroupBox(centralwidget);
        groupBoxInterval->setObjectName("groupBoxInterval");
        formLayoutInterval = new QFormLayout(groupBoxInterval);
        formLayoutInterval->setObjectName("formLayoutInterval");
        labelInterval = new QLabel(groupBoxInterval);
        labelInterval->setObjectName("labelInterval");

        formLayoutInterval->setWidget(0, QFormLayout::ItemRole::LabelRole, labelInterval);

        spinBoxInterval = new QSpinBox(groupBoxInterval);
        spinBoxInterval->setObjectName("spinBoxInterval");
        spinBoxInterval->setMaximum(99999);
        spinBoxInterval->setValue(100);

        formLayoutInterval->setWidget(0, QFormLayout::ItemRole::FieldRole, spinBoxInterval);

        labelJitter = new QLabel(groupBoxInterval);
        labelJitter->setObjectName("labelJitter");

        formLayoutInterval->setWidget(1, QFormLayout::ItemRole::LabelRole, labelJitter);

        spinBoxJitter = new QSpinBox(groupBoxInterval);
        spinBoxJitter->setObjectName("spinBoxJitter");

        formLayoutInterval->setWidget(1, QFormLayout::ItemRole::FieldRole, spinBoxJitter);


        verticalLayout_main->addWidget(groupBoxInterval);

        groupBoxOptions = new QGroupBox(centralwidget);
        groupBoxOptions->setObjectName("groupBoxOptions");
        formLayoutOptions = new QFormLayout(groupBoxOptions);
        formLayoutOptions->setObjectName("formLayoutOptions");
        labelBotao = new QLabel(groupBoxOptions);
        labelBotao->setObjectName("labelBotao");

        formLayoutOptions->setWidget(0, QFormLayout::ItemRole::LabelRole, labelBotao);

        comboBox = new QComboBox(groupBoxOptions);
        comboBox->setObjectName("comboBox");

        formLayoutOptions->setWidget(0, QFormLayout::ItemRole::FieldRole, comboBox);

        labelEstrategia = new QLabel(groupBoxOptions);
        labelEstrategia->setObjectName("labelEstrategia");

        formLayoutOptions->setWidget(1, QFormLayout::ItemRole::LabelRole, labelEstrategia);

        comboBoxStrategy = new QComboBox(groupBoxOptions);
        comboBoxStrategy->setObjectName("comboBoxStrategy");

        formLayoutOptions->setWidget(1, QFormLayout::ItemRole::FieldRole, comboBoxStrategy);


        verticalLayout_main->addWidget(groupBoxOptions);

        groupBoxHotkeys = new QGroupBox(centralwidget);
        groupBoxHotkeys->setObjectName("groupBoxHotkeys");
        formLayoutHotkeys = new QFormLayout(groupBoxHotkeys);
        formLayoutHotkeys->setObjectName("formLayoutHotkeys");
        labelStartKey = new QLabel(groupBoxHotkeys);
        labelStartKey->setObjectName("labelStartKey");

        formLayoutHotkeys->setWidget(0, QFormLayout::ItemRole::LabelRole, labelStartKey);

        comboBoxStartKey = new QComboBox(groupBoxHotkeys);
        comboBoxStartKey->setObjectName("comboBoxStartKey");

        formLayoutHotkeys->setWidget(0, QFormLayout::ItemRole::FieldRole, comboBoxStartKey);

        labelStopKey = new QLabel(groupBoxHotkeys);
        labelStopKey->setObjectName("labelStopKey");

        formLayoutHotkeys->setWidget(1, QFormLayout::ItemRole::LabelRole, labelStopKey);

        comboBoxStopKey = new QComboBox(groupBoxHotkeys);
        comboBoxStopKey->setObjectName("comboBoxStopKey");

        formLayoutHotkeys->setWidget(1, QFormLayout::ItemRole::FieldRole, comboBoxStopKey);

        labelMacroInfo = new QLabel(groupBoxHotkeys);
        labelMacroInfo->setObjectName("labelMacroInfo");
        labelMacroInfo->setAlignment(Qt::AlignCenter);

        formLayoutHotkeys->setWidget(2, QFormLayout::ItemRole::SpanningRole, labelMacroInfo);


        verticalLayout_main->addWidget(groupBoxHotkeys);

        horizontalLayoutButtons = new QHBoxLayout();
        horizontalLayoutButtons->setObjectName("horizontalLayoutButtons");
        pushButtonStop = new QPushButton(centralwidget);
        pushButtonStop->setObjectName("pushButtonStop");
        pushButtonStop->setMinimumSize(QSize(0, 40));

        horizontalLayoutButtons->addWidget(pushButtonStop);

        pushButtonStart = new QPushButton(centralwidget);
        pushButtonStart->setObjectName("pushButtonStart");
        pushButtonStart->setMinimumSize(QSize(0, 40));

        horizontalLayoutButtons->addWidget(pushButtonStart);


        verticalLayout_main->addLayout(horizontalLayoutButtons);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_main->addItem(verticalSpacer);

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
        groupBoxInterval->setTitle(QCoreApplication::translate("MainWindow", "\342\217\261 Click Interval", nullptr));
        labelInterval->setText(QCoreApplication::translate("MainWindow", "Intervalo (ms):", nullptr));
        labelJitter->setText(QCoreApplication::translate("MainWindow", "Jitter (ms):", nullptr));
        groupBoxOptions->setTitle(QCoreApplication::translate("MainWindow", "\360\237\226\261 Click Options", nullptr));
        labelBotao->setText(QCoreApplication::translate("MainWindow", "Bot\303\243o do Mouse:", nullptr));
        labelEstrategia->setText(QCoreApplication::translate("MainWindow", "Estrat\303\251gia:", nullptr));
        groupBoxHotkeys->setTitle(QCoreApplication::translate("MainWindow", "\342\214\250 Hotkeys & Macro", nullptr));
        labelStartKey->setText(QCoreApplication::translate("MainWindow", "Iniciar (Start):", nullptr));
        labelStopKey->setText(QCoreApplication::translate("MainWindow", "Parar (Stop):", nullptr));
        labelMacroInfo->setText(QCoreApplication::translate("MainWindow", "Gravar Macro: Pressione F8", nullptr));
        pushButtonStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
