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

    void onExecutionStarted() override;
    void onExecutionStopped() override;

protected:
    bool nativeEvent(const QByteArray &eventType, void *message, qintptr *result) override;

private slots:
    void onStartClicked();
    void onStopClicked();
    
    // Novos slots para escutar a mudança das hotkeys na UI
    void onStartKeyChanged(int index);
    void onStopKeyChanged(int index);

private:
    Ui::MainWindow *ui;
    Controller* m_controller;

    // Variáveis para armazenar as hotkeys atuais do Windows
    int m_startVK;
    int m_stopVK;

    // Função auxiliar para atualizar o registro no Windows
    void updateGlobalHotkeys();
};

#endif // MAINWINDOW_H