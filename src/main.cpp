#include <QApplication>
#include <QCoreApplication>
#include <QDir> // Adicionado para controlar o caminho
#include "ui/MainWindow.h"
#include "controller/Controller.h"
#include "core/engine/Engine.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // ==========================================================
    // O PULO DO GATO: FORÇAR O DIRETÓRIO
    // Isso garante que o programa ache a pasta /icons/ e o /style.qss
    // independente de onde você chame o .exe
    // ==========================================================
    QDir::setCurrent(QCoreApplication::applicationDirPath());
    QCoreApplication::addLibraryPath("./");

    // 1. Instancia o motor (Engine)
    Engine engine;

    // 2. Instancia o Controller
    Controller controller(&engine);

    // 3. Instancia a Janela
    MainWindow window(&controller);
    
    window.show();

    return app.exec();
}