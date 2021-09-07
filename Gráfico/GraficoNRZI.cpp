#include "GraficoNRZI.h"
#pragma push_macro("slots")
#undef slots
#include "matplotlibcpp.h"
#pragma pop_macro("slots")
#include <vector>
#include <iostream>

void Grafico::mostrarGrafico(std::string codigo){
    std::vector<int> ejeX = {-1};
    std::vector<float> ejeY = {-1.25, 1.25};
    std::vector<float> posX = {-0.25, -0.25};

    std::vector<int> vectorNulo = {0};
    std::vector<int> vectorVacio;

    int valorX = 0;
    int valorY = 1;

    std::vector<int> puntosX = {0};
    std::vector<int> puntosY = {1};

    for (char caracter: codigo) {
        if (caracter == '0') {
        valorX += 1;
        puntosX.push_back(valorX);
        puntosY.push_back(valorY);
        } else if (caracter == '1') {
        valorY *= -1;
        puntosX.push_back(valorX);
        puntosY.push_back(valorY);
        valorX += 1;
        puntosX.push_back(valorX);
        puntosY.push_back(valorY);
        } else {
            throw std::invalid_argument("Todos los caracteres deben ser binarios");
        }
    }

    for (int i = 0; i < puntosX.size(); ++i) {
    ejeX.push_back(i);
    vectorNulo.push_back(0);
    }

    plt::figure_size(900, 600);
    plt::title("Representación NRZI para: " + codigo);
    plt::xlabel("Tiempo");
    plt::ylabel("Amplitud");

    plt::xticks(vectorVacio);
    plt::yticks(vectorVacio);

    plt::xlim(-1, valorX + 1);

    plt::plot(puntosX, puntosY, "ok-");
    plt::plot(ejeX, vectorNulo, "C7--");
    plt::plot(posX, ejeY, "C7--");

    plt::show();
}