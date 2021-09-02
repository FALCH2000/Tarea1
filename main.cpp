#include <QCoreApplication>
#include <QDebug>
#include "HammingCode/Hamming.h"

int main(int argc, char *argv[]) {
//    QCoreApplication a(argc, argv);
//    qDebug() << "Hello World";
//    return QCoreApplication::exec();
    std::vector<bool> vector {1,1,1,1,1};
    Hamming hamming;
    hamming.cambiarTipoParidad();
    hamming.print(vector);
    vector = hamming.agregarBitsDeParidad(vector);
    hamming.print(vector);
    vector = hamming.establecerValoresDeParidad(vector);
    hamming.print(vector);
//    vector = hamming.modificarBitEnPos(vector, 3);
//    hamming.print(vector);
    std::vector<int> errorEnPos = hamming.revisarParidad(vector);
    std::cout << "Error en posicion: ";

}
