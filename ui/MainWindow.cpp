#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "application/use_cases/AppCommand.h"
#include "application/use_cases/AppTypes.h"
#include <QMetaObject>
#include <QMessageBox> // Para alertas de validação

MainWindow::MainWindow(Controller* controller, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_controller(controller)
{
    ui->setupUi(this);
    setWindowTitle("Bento AutoClicker PRO");

    // 1. Populando Ações com Data Oculta
    ui->comboBox->clear();
    ui->comboBox->addItem("Clique Esquerdo", "leftclick");
    ui->comboBox->addItem("Clique Direito", "rightclick");

    // 2. Populando Estratégias com Data Oculta (Fim do Hardcode)
    ui->comboBoxStrategy->clear();
    ui->comboBoxStrategy->addItem("Fixo (Normal)", "fixed");
    ui->comboBoxStrategy->addItem("Jitter (Aleatório)", "jitter");

    // 3. Estado inicial
    ui->pushButtonStart->setEnabled(true);
    ui->pushButtonStop->setEnabled(false);
    statusBar()->showMessage("Pronto."); // UX Visual

    // 4. Inscrição segura no Observer
    m_controller->subscribe(this);

    // 5. Conexões limpas (sem lambdas gigantes)
    connect(ui->pushButtonStart, &QPushButton::clicked, this, &MainWindow::onStartClicked);
    connect(ui->pushButtonStop, &QPushButton::clicked, this, &MainWindow::onStopClicked);
}

MainWindow::~MainWindow() {
    // CORREÇÃO CRÍTICA: Previne o crash Use-After-Free
    if (m_controller) {
        m_controller->unsubscribe(this);
    }
    delete ui;
}

void MainWindow::onStartClicked() {
    CommandData data;
    data.intervalMs = ui->spinBoxInterval->value();

    // VALIDAÇÃO: Impede falhas matemáticas na Engine
    if (data.intervalMs <= 0) {
        QMessageBox::warning(this, "Atenção", "O intervalo deve ser maior que zero!");
        return;
    }

    // Coleta limpa de dados
    data.actionName = ui->comboBox->currentData().toString().toStdString();
    data.strategyName = ui->comboBoxStrategy->currentData().toString().toStdString();
    
    // Coleta do Jitter (só será usado se a strategy for jitter)
    data.jitterMs = ui->spinBoxJitter->value(); 

    // Opcional: Validar se jitter não é maior que o intervalo (UX avançada)
    if (data.strategyName == "jitter" && data.jitterMs >= data.intervalMs) {
        QMessageBox::warning(this, "Atenção", "O Jitter não pode ser maior ou igual ao intervalo!");
        return;
    }

    statusBar()->showMessage("Iniciando...");
    m_controller->handleCommand(AppCommand::StartClicking, data);
}

void MainWindow::onStopClicked() {
    CommandData emptyData;
    m_controller->handleCommand(AppCommand::StopClicking, emptyData);
    statusBar()->showMessage("Parando...");
}

// =========================================================================
// IMPLEMENTAÇÃO DO OBSERVER (Reatividade Thread-Safe)
// =========================================================================

void MainWindow::onExecutionStarted() {
    QMetaObject::invokeMethod(this, [this]() {
        ui->pushButtonStart->setEnabled(false);
        ui->pushButtonStop->setEnabled(true);
        statusBar()->showMessage("Rodando (Metralhadora ativada!)"); // UX
    });
}

void MainWindow::onExecutionStopped() {
    QMetaObject::invokeMethod(this, [this]() {
        ui->pushButtonStart->setEnabled(true);
        ui->pushButtonStop->setEnabled(false);
        statusBar()->showMessage("Parado. Pronto para outra."); // UX
    });
}