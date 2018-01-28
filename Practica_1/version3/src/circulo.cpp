#include <string>
using namespace std;
#include "punto.h"
#include "circulo.h"

const double PI = 3.14159265;

Circulo::Circulo():centro(0,0), radio(0) {
}

Circulo::Circulo(Punto p, double rradio):centro(p),radio(rradio) {
}

void Circulo::set(Punto p, double rradio) {
	radio = rradio;
	centro = p;
}


Punto Circulo::getCentro()  {
	return centro;
}

double Circulo::getRadio()  {
	return radio;
}

string Circulo::toString() {
    return "Radio: " + to_string(radio) +
            " Centro: " + centro.toString();
}

double Circulo::area() {
    return PI * radio * radio;
}

// devuelve la distancia entre sus centros
double Circulo::distancia (Circulo c2){
    return centro.distancia(c2.centro);
	
}

//Comprueba si un punto es interior al círculo
bool Circulo::interior (Punto p){
    return (centro.getX() - p.getX() && centro.getY() - p.getY()) <= radio; 
}
