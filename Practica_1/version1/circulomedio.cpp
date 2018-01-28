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

const double PI = 3.14159265;
class Punto {
private:
    double x; // coordenada x del punto
    double y; // coordenada y del punto

public:
    Punto(); //constructor. Pone a 0 las dos coordenadas
    Punto(double px, double py); // constructor. Inicializa un punto con dos valores x y
    double getX(); 
    double getY(); 
    void setX(double newXValue); 
    void setY(double newYValue); 
    string toString(); ///<  devuelve el contenido del punto como un string
    double distancia(Punto p2); // calcula la distancia a otro punto
    Punto puntoMedio(Punto p2); //devuelve el punto medio entre el objeto implicito y p2
};

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


class Circulo {
private:
    Punto centro; // Centro del círculo
    double radio; // radio del círculo

public:
    Circulo(); // Constructor: Pone a 0 el punto y el radio
    Circulo(Punto centro, double rradio); // Constructor: Inicializa el círculo con un centro y un radio
    void set(Punto centro, double rradio); // Asigna el centro y el radio a un circulo
    Punto getCentro(); 
    double getRadio(); 
    string toString(); // devuelve el contenido del circulo como un string
    double area(); // Devuelve el área de un círculo
    double distancia (Circulo c2);
    bool interior (Punto p); // true si p está contenido en el círculo
};

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
 
