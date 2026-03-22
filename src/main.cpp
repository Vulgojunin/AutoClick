#include <QApplication>
#include "ui/MainWindow.h"
#include "controller/Controller.h"
#include "core/engine/Engine.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // 1. Instancia o motor (Engine)
    Engine engine;

    // 2. Instancia o Controller passando o endereço da Engine
    // Agora o construtor 'Controller(Engine*)' é satisfeito
    Controller controller(&engine);

    // 3. Instancia a Janela passando o Controller
    MainWindow window(&controller);
    
    window.show();

    return app.exec();
}