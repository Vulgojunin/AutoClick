#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "application/use_cases/AppCommand.h"
#include "application/use_cases/AppTypes.h"
#include <QFile>
#include <QMetaObject>
#include <QMessageBox>

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
    
    // Trava a janela no tamanho ideal
    setFixedSize(420, 380);
    
    // Carrega o design externo
    loadStyleSheet();

    // Configura as opções do Mouse
    ui->comboBoxButton->clear();
    ui->comboBoxButton->addItem("Esquerdo", "leftclick");
    ui->comboBoxButton->addItem("Direito", "rightclick");

    // Estado inicial
    ui->radioInfinite->setChecked(true);
    ui->pushButtonStop->setEnabled(false);
    statusBar()->showMessage("Bento PRO: F6 Inicia | F7 Para | F5 Designer");

    m_controller->subscribe(this);

    // Conecta os botões
    connect(ui->pushButtonStart, &QPushButton::clicked, this, &MainWindow::onStartClicked);
    connect(ui->pushButtonStop, &QPushButton::clicked, this, &MainWindow::onStopClicked);

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

// Carrega o design sem precisar compilar
void MainWindow::loadStyleSheet() {
    QFile file("style.qss");
    if (file.open(QFile::ReadOnly)) {
        this->setStyleSheet(QLatin1String(file.readAll()));
        file.close();
    }
}

// Atualiza o visual ao apertar F5
void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_F5) {
        loadStyleSheet();
        statusBar()->showMessage("Visual atualizado com sucesso!", 1500);
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
    // Soma o tempo de todas as caixinhas
    long long total = (ui->spinBoxHours->value() * 3600000ULL) + 
                      (ui->spinBoxMins->value()  * 60000ULL) + 
                      (ui->spinBoxSecs->value()  * 1000ULL) + 
                       ui->spinBoxMs->value();

    if (total <= 0) {
        QMessageBox::warning(this, "Aviso", "Intervalo inválido!");
        return;
    }

    CommandData data;
    data.intervalMs = (int)total;
    data.actionName = ui->comboBoxButton->currentData().toString().toStdString();
    data.isInfinite = ui->radioInfinite->isChecked();
    data.repeatTimes = ui->spinBoxTimes->value();

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

// Slots auxiliares
void MainWindow::onStartKeyChanged(int i) { Q_UNUSED(i); updateGlobalHotkeys(); }
void MainWindow::onStopKeyChanged(int i) { Q_UNUSED(i); updateGlobalHotkeys(); }