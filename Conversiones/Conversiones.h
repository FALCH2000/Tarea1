

#include <iostream>
#include <list>

#ifndef CONVERSIONES_H
#define	CONVERSIONES_H

using namespace std;

class Conversiones {
public:
    Conversiones();
    int Octal_Decimal(int numero);
    string Octal_Hexadecimal(int numero);
    string Resultado_hexa( const list<string> & Lista );
    string Octal_Binario(int numero);
    bool Verificar_Octal(int numero);
    


private:

};

#endif	/* CONVERSIONES_H */