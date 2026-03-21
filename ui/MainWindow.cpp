#include "MainWindow.h"
#include "ui_MainWindow.h" // Arquivo gerado automaticamente pelo Qt

MainWindow::MainWindow(Controller* controller, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_controller(controller) // Inicializa o nosso membro com o que veio do main.cpp
{
    ui->setupUi(this);
    
    // Configurações iniciais da janela (título, ícone, etc.)
    setWindowTitle("Bento AutoClicker PRO");
}

MainWindow::~MainWindow() {
    delete ui;
}