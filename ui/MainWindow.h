#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
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

    // Atualiza os botões quando o clique inicia ou para
    void onExecutionStarted() override;
    void onExecutionStopped() override;

protected:
    // Ouve as hotkeys F6/F7 em segundo plano
    bool nativeEvent(const QByteArray &eventType, void *message, qintptr *result) override;
    // Ouve o F5 para atualizar o visual na hora
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void onStartClicked();
    void onStopClicked();
    void onStartKeyChanged(int index);
    void onStopKeyChanged(int index);

private:
    Ui::MainWindow *ui;
    Controller* m_controller;

    int m_startVK; // F6
    int m_stopVK;  // F7

    void updateGlobalHotkeys();
    void loadStyleSheet(); // Carrega o design do style.qss
};

#endif // MAINWINDOW_H