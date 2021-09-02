
#include "Hamming.h"

Hamming::Hamming() {
    tipoPardida = false;
}

std::vector<bool> Hamming::agregarBitsDeParidad(std::vector<bool> vectorMsj) {
    int posEnMsjConParidad = 0;
    int exponente = 0;
    int posEnMsj = 0;
    std::vector<bool> msjConParidad;
    while(posEnMsj < vectorMsj.size()){
        if (posEnMsjConParidad == 0) {
            msjConParidad.push_back(false);
            posEnMsjConParidad++;
        }else if (posEnMsjConParidad == pow(2, exponente)){
            msjConParidad.push_back(false);
            exponente++;
            posEnMsjConParidad++;
        }else{
            msjConParidad.push_back(vectorMsj[posEnMsj]);
            posEnMsj++;
            posEnMsjConParidad++;
        }
    }
    return msjConParidad;
}

std::vector<bool> Hamming::modificarBitEnPos(std::vector<bool> vectorMsj, int pos) {
    if(pos < 0 or pos >= vectorMsj.size()){
        throw std::domain_error( "ERROR: Posición inválida");
    }else{
        vectorMsj[pos] = !vectorMsj[pos];
        return vectorMsj;
    }
}

std::vector<bool> Hamming::establecerValoresDeParidad(std::vector<bool> msj) {
    int exponente = 0;
    for (int i = 1; i < msj.size(); i++) {

        //Si el bit no es de paridad pasar al siguiente
        if (i != pow(2,exponente)) {
            continue;
        }

        exponente++;
        int n = log2(i);
        int one_count = 0;

        //Encontrar los bits que tengan un 1 en la n-aba
        //posición del bit de posición
        for (int j = i + 1; j < msj.size(); ++j) {
            if (j & (1 << n)) {
                if (msj[j] == 1) {
                    one_count++;
                }
            }
        }
        msj = setParidad(msj, one_count, i);
    }
    msj = establecerValoresDeParidadTotal(msj);
    return msj;
}

std::vector<bool> Hamming::establecerValoresDeParidadTotal(std::vector<bool> msj) {
    bool bit = false;
    int cont = 0;
    for (int i = 0; i < msj.size(); ++i) {
        if(msj[i])
            cont++;
    }
    msj = setParidad(msj, cont, 0);
    return msj;
}

std::vector<int> Hamming::revisarParidad(std::vector<bool> msj) {
    int exp = 0;
    std::vector<int> bitsDeParidadConError;
    for (int i = 1; i < msj.size(); i++) {

        //Si el bit no es de paridad pasar al siguiente
        if (i != pow(2, exp)) {
            continue;
        }
        exp++;
        int n = log2(i);
        int cont = 0;

        if(msj[i] == 1) //Si el bit de paridad es un uno, lo cuenta
            cont++;

        for (int j = i + 1; j < msj.size(); ++j) { //Encontrar los bits que tengan un 1 en la n-aba posición del bit de posición
            if (j & (1 << n)) {
                if (msj[j] == 1) {
                    cont++;
                }
            }
        }
        if (!numeroUnosCumpleParidad(cont)){ //Verifica si el valor del bit de paridad es acorde con el tipo de paridad
            bitsDeParidadConError.push_back(i);
        }
    }
    return bitsDeParidadConError;
}

void Hamming::cambiarTipoParidad() {
    tipoPardida = !tipoPardida;
}


void Hamming::print(std::vector<bool> vector) {
    std::cout << "[ ";
    for (int i = 0; i < vector.size(); ++i) {
        std::cout << vector[i] <<" ";
    }
    std::cout << "]" <<std::endl;
}

bool Hamming::numeroUnosCumpleParidad(int count) {
    if ((count%2 == 0 and !tipoPardida) or (count%2 == 1 and tipoPardida))
        return true;
    return false;
}

std::vector<bool> Hamming::setParidad(std::vector<bool> msj, int one_count, int pos) {
    bool bit = false;
    if (!tipoPardida){
        bit = true;
    }
    if (one_count%2 != 0){
        msj[pos] = bit;
    }else{
        msj[pos] = !bit;
    }
    return msj;
}


