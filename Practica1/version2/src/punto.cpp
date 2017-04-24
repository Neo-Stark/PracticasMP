#include <iostream>
#include <cmath>
using namespace std;
#include "punto.h"


Punto::Punto():x(0),y(0) {
}

Punto::Punto(double px, double py):x(px),y(py) {
}

double Punto::getX() {
	return x;
}

double Punto::getY() {
	return y;
}

void Punto::setX(double px) {
	x = px;
}

void Punto::setY(double py) {
	y = py;
}

string Punto::toString() {
    return "(" + to_string(x) + ", " + to_string(y) +  ")"; // devuelve un string con el formato (x,y)
}

double Punto::distancia(Punto p2){
    return sqrt(pow(x - p2.x,2) - 
                pow(y - p2.y,2));
}


Punto Punto::puntoMedio(Punto p2){
    Punto medio;
    medio.x = abs(x - p2.x) / 2;
    medio.y = abs(y - p2.y) / 2;

    return medio;
}