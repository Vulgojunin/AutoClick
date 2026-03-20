#include <QtWidgets/QApplication>
#include "core/Controller.h"
#include "ui/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Controller controller;
    MainWindow window(&controller);
    
    window.setWindowTitle("Bento AutoClicker");
    window.show();

    return app.exec();
}