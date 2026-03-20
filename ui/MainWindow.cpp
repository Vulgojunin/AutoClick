#include "MainWindow.h"
#include "core/Controller.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QFormLayout>

MainWindow::MainWindow(Controller* controller, QWidget* parent)
    : QMainWindow(parent), m_controller(controller) 
{
    QWidget* central = new QWidget(this);
    setCentralWidget(central);
    QVBoxLayout* mainLayout = new QVBoxLayout(central);

    // --- 1. BARRA DE STATUS ---
    m_lblStatus = new QLabel("IDLE", this);
    m_lblStatus->setFixedHeight(40);
    m_lblStatus->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(m_lblStatus);

    // --- 2. GRUPO DE CONFIGURAÇÕES ---
    QGroupBox* configGroup = new QGroupBox("Configurações de Clique", this);
    QFormLayout* form = new QFormLayout(configGroup);

    // Delay (Slider + SpinBox juntos)
    QHBoxLayout* delayLayout = new QHBoxLayout();
    m_sliderDelay = new QSlider(Qt::Horizontal, this);
    m_sliderDelay->setRange(1, 1000);
    m_spinDelay = new QSpinBox(this);
    m_spinDelay->setRange(1, 1000);
    m_spinDelay->setSuffix(" ms");
    
    delayLayout->addWidget(m_sliderDelay);
    delayLayout->addWidget(m_spinDelay);
    form->addRow("Intervalo:", delayLayout);

    // Botão do Mouse
    m_comboMouseBtn = new QComboBox(this);
    m_comboMouseBtn->addItems({"Esquerdo", "Direito", "Meio"});
    form->addRow("Botão:", m_comboMouseBtn);

    mainLayout->addWidget(configGroup);

    // --- 3. BOTÕES DE AÇÃO ---
    QHBoxLayout* actionLayout = new QHBoxLayout();
    m_btnStart = new QPushButton("INICIAR", this);
    m_btnPause = new QPushButton("PAUSAR", this);
    m_btnStop  = new QPushButton("PARAR", this);
    
    actionLayout->addWidget(m_btnStart);
    actionLayout->addWidget(m_btnPause);
    actionLayout->addWidget(m_btnStop);
    mainLayout->addLayout(actionLayout);

    setupStyles(); // Aplica as cores
    
    // Conexões Sincronizadas
    connect(m_sliderDelay, &QSlider::valueChanged, m_spinDelay, &QSpinBox::setValue);
    connect(m_spinDelay, QOverload<int>::of(&QSpinBox::valueChanged), [this](int val){
        m_sliderDelay->setValue(val);
        m_controller->updateDelay(val);
    });

    connect(m_btnStart, &QPushButton::clicked, [this](){ m_controller->requestStart(); });
    connect(m_btnStop,  &QPushButton::clicked, [this](){ m_controller->requestStop(); });

    if (m_controller) m_controller->registerObserver(this);
    resize(400, 300);
}

void MainWindow::setupStyles() {
    // Cores modernas (CSS Style)
    m_lblStatus->setStyleSheet("background-color: #333; color: white; font-size: 18px; border-radius: 5px;");
    m_btnStart->setStyleSheet("background-color: #27ae60; color: white; font-weight: bold; height: 40px;");
    m_btnPause->setStyleSheet("background-color: #f1c40f; color: black; font-weight: bold; height: 40px;");
    m_btnStop->setStyleSheet("background-color: #c0392b; color: white; font-weight: bold; height: 40px;");
}

void MainWindow::onStatusChanged(Status s) {
    switch(s) {
        case Status::Running:
            m_lblStatus->setText("RUNNING");
            m_lblStatus->setStyleSheet("background-color: #27ae60; color: white; font-weight: bold;");
            break;
        case Status::Idle:
            m_lblStatus->setText("IDLE");
            setupStyles(); // Volta ao original
            break;
        case Status::Paused:
            m_lblStatus->setText("PAUSED");
            m_lblStatus->setStyleSheet("background-color: #f1c40f; color: black;");
            break;
    }
}

MainWindow::~MainWindow() {}