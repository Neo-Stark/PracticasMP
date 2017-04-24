/**
   @file circulomedio.cpp
   @brief Calcula círculo con centro en medio de dos círculos y radio la mitad de la distancia
   @warning Módulo no definitivo (creado para ser modificado)

// si quieres utilizar la funcion to_string(), recuerde agregar -std=c++0x a las opciones del compilador

**/

#include <iostream>
#include <cmath> 
#include <string>
using namespace std;
#include "punto.h"
#include "circulo.h"


int main()
{
    Circulo c[3];
    double x, y;
    double radio;

	// leer datos para circulo 1
	
	// leer datos para circulo 2
	for(int i=0; i < 2; i++){
        cin >> x >> y >> radio;
        Punto centro(x,y);
        c[i].set(centro,radio);
    }
 
    
    // realizar los cálculos
    Punto centro = c[0].getCentro().puntoMedio(c[1].getCentro());
    radio = abs(c[0].getRadio() - c[1].getRadio()) / 2;
    c[2].set(centro, radio);

	// mostrar resultados
    
   
    cout << "\nLos circulos son\n";
	cout << "Circulo 1 -> " << c[0].toString() << ", area: " << c[0].area() << endl;
	cout << "Circulo 2 -> " << c[1].toString() << ", area: " << c[1].area() << endl;
	cout << "Circulo 3 -> " << c[2].toString() << ", area: " << c[2].area() << endl;  
    
    cout << endl;
}

/* Fin: circulomedio.cpp */
 
