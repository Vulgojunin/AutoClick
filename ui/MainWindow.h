#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controller/Controller.h" // Inclui o controller para a UI conhecê-lo

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    // O construtor agora EXIGE um ponteiro para o Controller
    explicit MainWindow(Controller* controller, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Controller* m_controller; // Variável para guardar o controller
};

#endif // MAINWINDOW_H