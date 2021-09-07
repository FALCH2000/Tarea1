#include <QDebug>
#include <QApplication>
#include "Interfaz/mainwindow.h"
#include "Conversiones/Conversiones.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
