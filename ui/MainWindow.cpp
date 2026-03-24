#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "application/use_cases/AppCommand.h"
#include "application/use_cases/AppTypes.h"
#include <QFile>
#include <QCoreApplication>
#include <QDir>
#include <QMetaObject>
#include <QMessageBox>
#include <QMouseEvent>
#include <QDebug>

#ifdef _WIN32
#include <windows.h>
#endif

MainWindow::MainWindow(Controller* controller, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_controller(controller)
    , m_startVK(VK_F6) 
    , m_stopVK(VK_F7)
{
    ui->setupUi(this);
    
    // Configurações da Janela (Sem bordas e Transparente)
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->resize(800, 650);
    
    loadStyleSheet();

    // 1. Populando os menus
    ui->comboBoxButton->clear();
    ui->comboBoxButton->addItem("Botão Esquerdo", "leftclick");
    ui->comboBoxButton->addItem("Botão Direito", "rightclick");

    ui->comboBoxType->clear();
    ui->comboBoxType->addItem("Clique Fixo (Normal)", "fixed");
    ui->comboBoxType->addItem("Clique Jitter (Aleatório)", "jitter");

    ui->radioInfinite->setChecked(true);
    ui->pushButtonStop->setEnabled(false);

    m_controller->subscribe(this);

    // 2. Conexões dos Botões de Controle
    connect(ui->pushButtonStart, &QPushButton::clicked, this, &MainWindow::onStartClicked);
    connect(ui->pushButtonStop, &QPushButton::clicked, this, &MainWindow::onStopClicked);

    // 3. Conexões da "Barra de Título" (Fechar e Minimizar)
    connect(ui->btnClose, &QPushButton::clicked, this, &MainWindow::close);
    connect(ui->btnMinimize, &QPushButton::clicked, this, &MainWindow::showMinimized);

    updateGlobalHotkeys();
}

MainWindow::~MainWindow() {
#ifdef _WIN32
    UnregisterHotKey((HWND)winId(), 1);
    UnregisterHotKey((HWND)winId(), 2);
#endif
    if (m_controller) m_controller->unsubscribe(this);
    delete ui;
}

void MainWindow::loadStyleSheet() {
    QString cssPath = QCoreApplication::applicationDirPath() + "/style.qss";
    QFile file(cssPath);
    
    if (file.open(QFile::ReadOnly)) {
        QString styleData = QLatin1String(file.readAll());
        this->setStyleSheet(styleData);
        file.close();
        qDebug() << "Visual Bento PRO carregado!";
    } else {
        qDebug() << "ERRO: style.qss nao encontrado em:" << cssPath;
        this->setStyleSheet("QMainWindow { background-color: #1a1d22; border: 2px solid #00d2ff; }");
    }
}

// Permitir ARRASTAR a janela clicando na barra de título ou fundo
void MainWindow::mousePressEvent(QMouseEvent *event) {
    m_dragPosition = event->globalPosition().toPoint() - frameGeometry().topLeft();
    event->accept();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPosition().toPoint() - m_dragPosition);
        event->accept();
    }
}

// F5 para atualizar o visual em tempo real
void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_F5) {
        loadStyleSheet();
    }
}

void MainWindow::updateGlobalHotkeys() {
#ifdef _WIN32
    UnregisterHotKey((HWND)winId(), 1);
    UnregisterHotKey((HWND)winId(), 2);
    RegisterHotKey((HWND)winId(), 1, 0, m_startVK);
    RegisterHotKey((HWND)winId(), 2, 0, m_stopVK);
#endif
}

bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, qintptr *result) {
#ifdef _WIN32
    MSG* msg = static_cast<MSG*>(message);
    if (msg->message == WM_HOTKEY) {
        if (msg->wParam == 1 && ui->pushButtonStart->isEnabled()) onStartClicked();
        else if (msg->wParam == 2 && ui->pushButtonStop->isEnabled()) onStopClicked();
        return true;
    }
#endif
    return QMainWindow::nativeEvent(eventType, message, result);
}

void MainWindow::onStartClicked() {
    long long total = (ui->spinBoxHours->value() * 3600000ULL) + 
                      (ui->spinBoxMins->value()  * 60000ULL) + 
                      (ui->spinBoxSecs->value()  * 1000ULL) + 
                       ui->spinBoxMs->value();

    if (total <= 0 && ui->spinBoxMs->value() == 0) {
        QMessageBox::warning(this, "Aviso", "Defina um intervalo!");
        return;
    }

    CommandData data;
    data.intervalMs = (total > 0) ? (int)total : 100;
    data.actionName = ui->comboBoxButton->currentData().toString().toStdString();
    data.strategyName = ui->comboBoxType->currentData().toString().toStdString();
    data.isInfinite = ui->radioInfinite->isChecked();
    data.repeatTimes = ui->spinBoxTimes->value();
    data.jitterMs = 15; 

    m_controller->handleCommand(AppCommand::StartClicking, data);
}

void MainWindow::onStopClicked() {
    CommandData empty;
    m_controller->handleCommand(AppCommand::StopClicking, empty);
}

void MainWindow::onExecutionStarted() {
    QMetaObject::invokeMethod(this, [this]() {
        ui->pushButtonStart->setEnabled(false);
        ui->pushButtonStop->setEnabled(true);
    });
}

void MainWindow::onExecutionStopped() {
    QMetaObject::invokeMethod(this, [this]() {
        ui->pushButtonStart->setEnabled(true);
        ui->pushButtonStop->setEnabled(false);
    });
}

void MainWindow::onStartKeyChanged(int i) { Q_UNUSED(i); updateGlobalHotkeys(); }
void MainWindow::onStopKeyChanged(int i) { Q_UNUSED(i); updateGlobalHotkeys(); }