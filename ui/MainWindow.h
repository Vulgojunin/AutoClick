#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include "core/interfaces/IControllerObserver.h"

class Controller;

class MainWindow : public QMainWindow, public IControllerObserver {
    Q_OBJECT

public:
    explicit MainWindow(Controller* controller, QWidget* parent = nullptr);
    ~MainWindow();

    // Implementação da Interface
    void onStatusChanged(Status s) override;
    void onSettingsChanged(int delay, int clickType) override {}

private:
    void setupStyles(); // Onde a mágica visual acontece
    
    Controller* m_controller;

    // Widgets de Controle
    QPushButton *m_btnStart, *m_btnStop, *m_btnPause;
    QSlider* m_sliderDelay;
    QSpinBox* m_spinDelay;
    QComboBox* m_comboMouseBtn;
    QLabel* m_lblStatus;
};

#endif