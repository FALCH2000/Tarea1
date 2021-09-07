#include <QDebug>
#include <QApplication>
#include "Interfaz/mainwindow.h"
#include "HammingCode/Hamming.h"
#include "Conversiones/Conversiones.h"
#include "Gráfico/GraficoNRZI.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
