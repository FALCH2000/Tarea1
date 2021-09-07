#pragma once

#pragma push_macro("slots")
#undef slots
#include "matplotlibcpp.h"
#pragma pop_macro("slots")
#include <vector>
#include <iostream>

namespace plt = matplotlibcpp;

class Grafico{
public:
    void mostrarGrafico(std::string codigo);
};