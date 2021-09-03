#include <QCoreApplication>
#include <QDebug>
#include "HammingCode/Hamming.h"

int main(int argc, char *argv[]) {
//    QCoreApplication a(argc, argv);
//    qDebug() << "Hello World";
//    return QCoreApplication::exec();
// EJEMPLO HAMMING
Hamming hamming;
//hamming.cambiarTipoParidad(); //Cambia el tipo de paridad
std::vector<bool> vec{1,1,1};
std::cout << "Entrada:" << std::endl;
hamming.print(vec);
vec = hamming.agregarBitsDeParidad(vec);
std::cout << "Agregar los bits de paridad (no tienen ningún valor):" << std::endl;
hamming.print(vec);
vec = hamming.establecerValoresDeParidad(vec);
std::cout << "Establecer el valor de los bits de paridad:" << std::endl;
hamming.print(vec);
vec = hamming.modificarBitEnPos(vec, 2);
std::cout << "Alterar un bit:" << std::endl;
hamming.print(vec);
int posError = hamming.seekError(vec);
std::cout << "Error en posición: " << posError << std::endl;
std::cout << "------ Pa las tablas ------" << std::endl;

std:: vector<int> posBitsParidad = hamming.posDeBitsDeParidad(vec);
std::cout << "Posiciones de los bits de paridad:" << std::endl;
for (int & i : posBitsParidad)
    std::cout << i << ' ';
std::cout<<""<<std::endl;
std:: vector<int> posBitsQueVerifica = hamming.posQueVerificaUnBitDeParidad(vec, 2);
std::cout << "Posiciones que verfica el bit de paridad en pos 2" << std::endl;
for (int & i : posBitsQueVerifica)
    std::cout << i << ' ';
std::cout<<""<<std::endl;





}
