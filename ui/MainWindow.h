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

    // --- CONTRATO COM O OBSERVER (APENAS UMA VEZ CADA!) ---
    void onStatusChanged(Status s) override;
    void onSettingsChanged(int delay, int clickType) override; 

protected:
    // Captura o F6 do teclado (API do Windows)
    bool nativeEvent(const QByteArray &eventType, void *message, qintptr *result) override;

private:
    void setupLayout();
    void setupStyles();
    
    Controller* m_controller;

    // --- ELEMENTOS VISUAIS (WIDGETS) ---
    QLabel* m_lblStatus;
    QSlider* m_sliderDelay;
    QSpinBox* m_spinDelay;
    QComboBox* m_comboMouseBtn;
    QPushButton* m_btnStart;
    QPushButton* m_btnStop;
};

#endif