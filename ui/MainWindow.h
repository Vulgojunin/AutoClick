#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPoint>
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
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private slots:
    void onStartClicked();
    void onStopClicked();
    void onStartKeyChanged(int index);
    void onStopKeyChanged(int index);

private:
    Ui::MainWindow *ui;
    Controller* m_controller;

    int m_startVK; 
    int m_stopVK;  
    QPoint m_dragPosition; 

    void updateGlobalHotkeys();
    void loadStyleSheet();
};

#endif // MAINWINDOW_H