#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "application/use_cases/AppCommand.h"
#include "application/use_cases/AppTypes.h"
#include "core/actions/MacroRecorder.h" // Importando o Gravador de Macro
#include <QMetaObject>
#include <QMessageBox>

#ifdef _WIN32
#include <windows.h>
#endif

MainWindow::MainWindow(Controller* controller, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_controller(controller)
    , m_startVK(VK_F6) // Valores padrão iniciais
    , m_stopVK(VK_F7)
{
    ui->setupUi(this);
    setWindowTitle("Bento AutoClicker PRO");

    // ==========================================================
    // INJEÇÃO DO TEMA VISUAL DARK/NEON (QSS)
    // ==========================================================
    this->setStyleSheet(R"(
        /* Fundo da Janela Principal */
        QMainWindow, QWidget#centralwidget {
            background-color: #1a1e24;
            font-family: 'Segoe UI', Arial, sans-serif;
            font-size: 13px;
        }

        /* Títulos dos Cards (GroupBox) */
        QGroupBox {
            background-color: #242931;
            border: 1px solid #333945;
            border-radius: 10px;
            margin-top: 20px;
            padding-top: 15px;
            color: #1dd3b0; /* Verde/Ciano da imagem */
            font-weight: bold;
            font-size: 14px;
        }
        QGroupBox::title {
            subcontrol-origin: margin;
            subcontrol-position: top left;
            padding: 0 10px;
            left: 10px;
            top: -5px;
        }

        /* Textos padrão */
        QLabel {
            color: #a0a5b5;
        }
        QLabel#labelMacroInfo {
            color: #d1d5db;
            font-style: italic;
            margin-top: 5px;
        }

        /* Caixas de Texto, SpinBoxes e ComboBoxes */
        QSpinBox, QComboBox {
            background-color: #1a1e24;
            color: #ffffff;
            border: 1px solid #333945;
            border-radius: 5px;
            padding: 5px;
            selection-background-color: #1dd3b0;
            selection-color: #1a1e24;
        }
        QSpinBox::up-button, QSpinBox::down-button {
            background-color: #2b303a;
            border-radius: 3px;
            width: 16px;
        }
        QComboBox::drop-down {
            border: none;
            width: 20px;
        }

        /* O Botão Start Brilhante */
        QPushButton#pushButtonStart {
            background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #00b4db, stop:1 #0083b0);
            color: white;
            border: none;
            border-radius: 8px;
            font-size: 16px;
            font-weight: bold;
        }
        QPushButton#pushButtonStart:hover {
            background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #1dd3b0, stop:1 #00b4db);
        }
        QPushButton#pushButtonStart:disabled {
            background-color: #333945;
            color: #6c727e;
        }

        /* O Botão Stop */
        QPushButton#pushButtonStop {
            background-color: transparent;
            color: #ff4d4d;
            border: 1px solid #ff4d4d;
            border-radius: 8px;
            font-size: 16px;
            font-weight: bold;
        }
        QPushButton#pushButtonStop:hover {
            background-color: rgba(255, 77, 77, 0.1);
        }
        QPushButton#pushButtonStop:disabled {
            border: 1px solid #333945;
            color: #6c727e;
        }

        /* Barra de Status */
        QStatusBar {
            background-color: #15181d;
            color: #a0a5b5;
        }
    )");
    // ==========================================================

    // 1. Populando Ações (Com a Macro)
    ui->comboBox->clear();
    ui->comboBox->addItem("Clique Esquerdo", "leftclick");
    ui->comboBox->addItem("Clique Direito", "rightclick");
    ui->comboBox->addItem("Tocar Macro", "macro");

    // 2. Populando Estratégias
    ui->comboBoxStrategy->clear();
    ui->comboBoxStrategy->addItem("Fixo (Normal)", "fixed");
    ui->comboBoxStrategy->addItem("Jitter (Aleatório)", "jitter");

    // 3. Populando as Hotkeys (F1 a F12)
    ui->comboBoxStartKey->clear();
    ui->comboBoxStopKey->clear();
    for (int i = 1; i <= 12; ++i) {
        QString keyName = QString("F%1").arg(i);
        ui->comboBoxStartKey->addItem(keyName);
        ui->comboBoxStopKey->addItem(keyName);
    }
    
    // Setando F6 (índice 5) pro Start e F7 (índice 6) pro Stop como padrão
    ui->comboBoxStartKey->setCurrentIndex(5);
    ui->comboBoxStopKey->setCurrentIndex(6);

    // 4. Estado inicial da UI
    ui->pushButtonStart->setEnabled(true);
    ui->pushButtonStop->setEnabled(false);
    statusBar()->showMessage("Pronto. Use as Hotkeys para Iniciar/Parar. F8 para gravar Macro.");

    // Inscrevendo no Observer da Engine
    m_controller->subscribe(this);

    // 5. Conexões dos Botões
    connect(ui->pushButtonStart, &QPushButton::clicked, this, &MainWindow::onStartClicked);
    connect(ui->pushButtonStop, &QPushButton::clicked, this, &MainWindow::onStopClicked);

    // 6. Conexões dos ComboBoxes de Hotkey
    connect(ui->comboBoxStartKey, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onStartKeyChanged);
    connect(ui->comboBoxStopKey, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onStopKeyChanged);

    // Registra as teclas iniciais no Windows (Incluindo o F8 da Macro)
    updateGlobalHotkeys();
}

MainWindow::~MainWindow() {
#ifdef _WIN32
    // Limpeza rigorosa dos Hooks no Windows para não travar o teclado
    UnregisterHotKey((HWND)winId(), 1);
    UnregisterHotKey((HWND)winId(), 2);
    UnregisterHotKey((HWND)winId(), 3); // Limpa o F8 também
#endif

    if (m_controller) {
        m_controller->unsubscribe(this);
    }
    delete ui;
}

// =========================================================================
// LÓGICA DE ATUALIZAÇÃO DAS HOTKEYS
// =========================================================================
void MainWindow::updateGlobalHotkeys() {
#ifdef _WIN32
    // Sempre desregistra as antigas antes de aplicar as novas para não acumular lixo
    UnregisterHotKey((HWND)winId(), 1);
    UnregisterHotKey((HWND)winId(), 2);
    UnregisterHotKey((HWND)winId(), 3);

    // Registra as novas
    RegisterHotKey((HWND)winId(), 1, 0, m_startVK); // Dinâmico (Start)
    RegisterHotKey((HWND)winId(), 2, 0, m_stopVK);  // Dinâmico (Stop)
    RegisterHotKey((HWND)winId(), 3, 0, VK_F8);     // Fixo (Gravar Macro)
#endif
}

void MainWindow::onStartKeyChanged(int index) {
    m_startVK = VK_F1 + index;
    updateGlobalHotkeys();
}

void MainWindow::onStopKeyChanged(int index) {
    m_stopVK = VK_F1 + index;
    updateGlobalHotkeys();
}

// =========================================================================
// INTERCEPTADOR DO WINDOWS (Lida com Start, Stop e Gravação de Macro)
// =========================================================================
bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, qintptr *result) {
#ifdef _WIN32
    Q_UNUSED(eventType);
    Q_UNUSED(result);
    
    MSG* msg = static_cast<MSG*>(message);
    if (msg->message == WM_HOTKEY) {
        if (msg->wParam == 1) { 
            if (ui->pushButtonStart->isEnabled()) onStartClicked();
        } 
        else if (msg->wParam == 2) { 
            if (ui->pushButtonStop->isEnabled()) onStopClicked();
        } 
        else if (msg->wParam == 3) { 
            // ID 3 (F8): Lógica do Gravador de Macro
            auto& recorder = MacroRecorder::getInstance();
            if (recorder.isRecording()) {
                recorder.stopRecording();
                statusBar()->showMessage("Macro Gravada com Sucesso! Selecione 'Tocar Macro' e inicie.");
            } else {
                recorder.startRecording();
                statusBar()->showMessage("GRAVANDO MACRO... Faça seus movimentos e pressione F8 para parar.");
            }
        }
        return true;
    }
#endif
    return QMainWindow::nativeEvent(eventType, message, result);
}

void MainWindow::onStartClicked() {
    CommandData data;
    data.intervalMs = ui->spinBoxInterval->value();

    if (data.intervalMs <= 0) {
        QMessageBox::warning(this, "Atenção", "O intervalo deve ser maior que zero!");
        return;
    }

    if (m_startVK == m_stopVK) {
        QMessageBox::warning(this, "Atenção", "A tecla de Start e Stop não podem ser a mesma!");
        return;
    }

    data.actionName = ui->comboBox->currentData().toString().toStdString();
    data.strategyName = ui->comboBoxStrategy->currentData().toString().toStdString();
    data.jitterMs = ui->spinBoxJitter->value(); 

    if (data.strategyName == "jitter" && data.jitterMs >= data.intervalMs) {
        QMessageBox::warning(this, "Atenção", "O Jitter não pode ser maior ou igual ao intervalo!");
        return;
    }

    // Alerta de UX: Se escolheu macro mas não gravou nada
    if (data.actionName == "macro" && MacroRecorder::getInstance().getMacro().empty()) {
        QMessageBox::warning(this, "Atenção", "Você escolheu Tocar Macro, mas ainda não gravou nada!\nPressione F8 para gravar.");
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

void MainWindow::onExecutionStarted() {
    QMetaObject::invokeMethod(this, [this]() {
        ui->pushButtonStart->setEnabled(false);
        ui->pushButtonStop->setEnabled(true);
        statusBar()->showMessage("Rodando! Pressione a tecla de Stop para parar.");
    });
}

void MainWindow::onExecutionStopped() {
    QMetaObject::invokeMethod(this, [this]() {
        ui->pushButtonStart->setEnabled(true);
        ui->pushButtonStop->setEnabled(false);
        statusBar()->showMessage("Parado. Pronto para outra.");
    });
}