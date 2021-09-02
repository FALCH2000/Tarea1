
#ifndef TAREA_1_HAMMING_H
#define TAREA_1_HAMMING_H
#include <iostream>
#include <vector>
#include <valarray>

class Hamming {
public:
    Hamming();
    /**
     * @brief Agrega los bits de paridad al vector de paridad
     * @return
     */
    std::vector<bool> agregarBitsDeParidad(std::vector<bool> vectorMsj);
    /**
     * @brief Altera el bit en la posición de entrada
     * @param vectorMsj
     * @param pos
     * @return
     */
    std::vector<bool> modificarBitEnPos(std::vector<bool> vectorMsj, int pos);
    /**
     * @brief Establece los valores de los bits de paridad de forma que cumpla con
     * el tipo de paridad
     * @param msj
     * @return
     */
    std::vector<bool> establecerValoresDeParidad(std::vector<bool> msj);
    /**
     * @brief Verifica si hay un error en la cadena de bits.
     * Devuelve un vector con la posición de los bits de paridad que
     * detectaron un error. (LA SUMA DE LOS ELEMENTOS DEL VECTOR DETERMINAN
     * LA POSICIÓN DEL ERROR)
     * @param msj
     * @return
     */
    std::vector<int> revisarParidad(std::vector<bool> msj);
    void print(std::vector<bool> vector);
    /**
     * @brief Cambia el tipo de paridad
     */
    void cambiarTipoParidad();
private:
    bool tipoPardida;
    /**
     * @brief Establece el valor del primer bit, el bit de la paridad total
     * @param msj
     * @return
     */
    std::vector<bool> establecerValoresDeParidadTotal(std::vector<bool> msj);
    /**
     * @brief Setea el valor del bit
     * @param msj
     * @param ont_count
     * @param pos
     * @return
     */
    std::vector<bool> setParidad(std::vector<bool> msj, int ont_count, int pos);
    /**
     * @brief Verifica si el número de 1 cumple con el tipo de paridad
     * @param count
     * @return
     */
    bool numeroUnosCumpleParidad(int count);
};


#endif //TAREA_1_HAMMING_H
