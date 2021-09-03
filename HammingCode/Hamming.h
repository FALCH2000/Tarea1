
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
     * @brief Devuelve la posición de los bits de paridad de una cadena de bits
     * @param vectorMsj
     * @return
     */
    std::vector<int> posDeBitsDeParidad(std::vector<bool> vectorMsj);
    /**
     * @brief Recibe la posición de un bit de paridad y devuelve la posición de los bits que verifica,
     * si retorna -1, la pos de entrada no es de un bit de paridad o es muy grande
     * @param msj
     * @param posBitParidad
     * @return
     */
    std::vector<int> posQueVerificaUnBitDeParidad(std::vector<bool> msj, int posBitParidad);
    /**
     * @brief Establece los valores de los bits de paridad de forma que cumpla con
     * el tipo de paridad
     * @param msj
     * @return
     */
    std::vector<bool> establecerValoresDeParidad(std::vector<bool> msj);
    /**
     * @brief Altera el bit en la posición de entrada
     * @param vectorMsj
     * @param pos
     * @return
     */
    std::vector<bool> modificarBitEnPos(std::vector<bool> vectorMsj, int pos);
    /**
     * @brief Devuelve un vector con la posición de los bits de paridad que
     * detectaron un error.
     * @param msj
     * @return
     */
    std::vector<int> bitsDeParidadQueDetectanError(std::vector<bool> msj);
    /**
     * @brief Devuelve la posición del bit cambiado, -1 signigica que no hubo error
     * @param msj
     * @return
     */
    int seekError(std::vector<bool> msj);
    /**
     * @brief Cambia el tipo de paridad
     */
    void cambiarTipoParidad();
    void print(std::vector<bool> vector);
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
    /**
     * @brief Revisa la paridad de toda la cadena de bits
     * @param msj
     * @return
     */
    bool revisarParidadGeneral(std::vector<bool> msj);
};


#endif //TAREA_1_HAMMING_H
