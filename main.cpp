#include <QCoreApplication>
#include <QDebug>
#include "HammingCode/Hamming.h"
#include "Conversiones/Conversiones.h"
#include "Gráfico/GraficoNRZI.h"


int main(int argc, char *argv[]) {
//    Conversiones prueba = *new Conversiones();
//
//    cout << prueba.Verificar_Octal(45713)<< endl;
//    cout << prueba.Verificar_Octal(43857)<< endl;
//    cout << prueba.Octal_Binario(645)<< endl;
//    cout << prueba.Octal_Decimal(645)<< endl;
//    cout << prueba.Octal_Hexadecimal(645)<< endl;
//
//    mostrarGrafico("011110100110001");

    QCoreApplication a(argc, argv);
    qDebug() << "Hello World";
    return QCoreApplication::exec();
}
