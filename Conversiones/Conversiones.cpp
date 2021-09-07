#include "Conversiones.h"
#include <iostream>
#include <math.h>
#include <list>



using namespace std;

Conversiones::Conversiones() {
}

//--------------------------------------------------------------------------------------------------------

bool Conversiones::Verificar_Octal(int numero){
    bool resultado = true;

    while(numero != 0){
        if(numero%10 >=8){
            numero = 0;
            resultado = false;
        }else{
            numero = numero/10;
        }
        
    }
    return resultado;
}

//------------------------------------------------------------------------------------------------------

int Conversiones::Octal_Decimal(int numero){
    int resultado = 0;
    int exponente = 0;
    int multiplicador = 0;

    while(numero != 0){
        multiplicador = pow(8,exponente);
        resultado += numero%10*multiplicador;
        exponente++;
        numero = numero/10;
    }

    return resultado;
}




    //---------------------------------------------------------------------------------------------------------

    string Conversiones::Octal_Hexadecimal(int numero){
    list <string> numeros;
    numero = Octal_Decimal(numero);

    while(numero > 15){
        numeros.push_front(to_string(numero%16));
        numero = numero/16;
    }

    numeros.push_front(to_string(numero));

    

    return Resultado_hexa(numeros);
}
//-----------------------------------------------------------------------------------------------------
string Conversiones::Octal_Binario(int numero){
    list <string> numeros;
    numero = Octal_Decimal(numero);

    while(numero > 1){
        numeros.push_front(to_string(numero%2));
        numero = numero/2;
    }

    numeros.push_front(to_string(numero));

    

    return Resultado_hexa(numeros);
}

//---------------------------------------------------------------------------------------------------------
    string Conversiones::Resultado_hexa( const list<string> & Lista ){

        string resultado = "";

            list<string>::const_iterator pos;
            pos = Lista.begin();
            while( pos != Lista.end())
        {

            if(*pos == "10"){
                resultado += "A";
            }else if(*pos == "11"){
                resultado += "B";
            }else if(*pos == "12"){
                resultado += "C";
            }else if(*pos == "13"){
                resultado += "D";
            }else if(*pos == "14"){
                resultado += "E";
            }else if(*pos == "15"){
                resultado += "F";
            }else{
                resultado += *pos;
            }
            
            pos++;
        }
    return resultado;

    }
