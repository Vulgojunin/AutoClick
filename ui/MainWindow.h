#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controller/Controller.h"
#include "core/interfaces/IControllerObserver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public IControllerObserver {
    Q_OBJECT

public:
    explicit MainWindow(Controller* controller, QWidget *parent = nullptr);
    ~MainWindow();

    // Contrato do Observer
    void onExecutionStarted() override;
    void onExecutionStopped() override;

private slots:
    // CORREÇÃO: Lambdas extraídas para métodos privados (Clean Code)
    void onStartClicked();
    void onStopClicked();

private:
    Ui::MainWindow *ui;
    Controller* m_controller;
};

#endif // MAINWINDOW_H