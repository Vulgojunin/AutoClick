#include "MainWindow.h"
#include "core/Controller.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QFormLayout>
#include <windows.h> // Essencial para RegisterHotKey

MainWindow::MainWindow(Controller* controller, QWidget* parent)
    : QMainWindow(parent), m_controller(controller) 
{
    setupLayout();
    setupStyles();

    // Registra o F6 no Windows (ID 100)
    RegisterHotKey((HWND)winId(), 100, 0, VK_F6);

    if (m_controller) m_controller->registerObserver(this);
    resize(400, 320);
}

void MainWindow::setupLayout() {
    QWidget* central = new QWidget(this);
    setCentralWidget(central);
    QVBoxLayout* mainLayout = new QVBoxLayout(central);

    m_lblStatus = new QLabel("IDLE", this);
    m_lblStatus->setAlignment(Qt::AlignCenter);
    m_lblStatus->setFixedHeight(40);
    mainLayout->addWidget(m_lblStatus);

    QGroupBox* configGroup = new QGroupBox("Configurações", this);
    QFormLayout* form = new QFormLayout(configGroup);

    QHBoxLayout* delayLayout = new QHBoxLayout();
    m_sliderDelay = new QSlider(Qt::Horizontal, this);
    m_sliderDelay->setRange(10, 1000); // Mínimo 10ms para segurança
    m_spinDelay = new QSpinBox(this);
    m_spinDelay->setRange(10, 1000);
    m_spinDelay->setSuffix(" ms");
    
    delayLayout->addWidget(m_sliderDelay);
    delayLayout->addWidget(m_spinDelay);
    form->addRow("Intervalo:", delayLayout);

    m_comboMouseBtn = new QComboBox(this);
    m_comboMouseBtn->addItems({"Esquerdo", "Direito"});
    form->addRow("Botão:", m_comboMouseBtn);

    mainLayout->addWidget(configGroup);

    QHBoxLayout* actionLayout = new QHBoxLayout();
    m_btnStart = new QPushButton("INICIAR", this);
    m_btnStop  = new QPushButton("PARAR", this);
    actionLayout->addWidget(m_btnStart);
    actionLayout->addWidget(m_btnStop);
    mainLayout->addLayout(actionLayout);

    // Conexões
    connect(m_sliderDelay, &QSlider::valueChanged, m_spinDelay, &QSpinBox::setValue);
    connect(m_spinDelay, QOverload<int>::of(&QSpinBox::valueChanged), [this](int val){
        m_sliderDelay->setValue(val);
        m_controller->updateDelay(val);
    });

    connect(m_btnStart, &QPushButton::clicked, [this](){ m_controller->requestStart(); });
    connect(m_btnStop,  &QPushButton::clicked, [this](){ m_controller->requestStop(); });
}

void MainWindow::setupStyles() {
    m_lblStatus->setStyleSheet("background-color: #333; color: white; font-size: 16px; border-radius: 4px;");
    m_btnStart->setStyleSheet("background-color: #2ecc71; color: white; font-weight: bold; height: 35px;");
    m_btnStop->setStyleSheet("background-color: #e74c3c; color: white; font-weight: bold; height: 35px;");
}

void MainWindow::onStatusChanged(Status s) {
    if (s == Status::Running) {
        m_lblStatus->setText("RUNNING (F6 para parar)");
        m_lblStatus->setStyleSheet("background-color: #2ecc71; color: white; font-weight: bold;");
        m_btnStart->setEnabled(false);
    } else {
        m_lblStatus->setText("IDLE (F6 para iniciar)");
        m_lblStatus->setStyleSheet("background-color: #333; color: white;");
        m_btnStart->setEnabled(true);
    }
}

bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, qintptr *result) {
    MSG* msg = static_cast<MSG*>(message);
    if (msg->message == WM_HOTKEY && msg->wParam == 100) {
        m_controller->toggleExecution();
        return true;
    }
    return QMainWindow::nativeEvent(eventType, message, result);
}

MainWindow::~MainWindow() {
    UnregisterHotKey((HWND)winId(), 100);
}

void MainWindow::onSettingsChanged(int delay, int clickType) {
    // Por enquanto deixamos vazio, só para o compilador parar de reclamar.
    // No futuro, se o delay mudar por um atalho, atualizamos o Slider aqui.
    m_spinDelay->setValue(delay);
    m_sliderDelay->setValue(delay);
}