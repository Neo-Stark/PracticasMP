using namespace std;
#include <iostream>
#include "MiCadenaClasica.h"

int main(){
	char c[100];
	char c1[100];
	char c_copia[100];
	bool es_palindromo;
	int comparar;
	int p, l;

	cout << "\nIntroducir cadena de caracteres 1 --> " ;
	lee_linea(c, 100);
	cout << "\nIntroducir cadena de caracteres 2 --> ";
	lee_linea(c1,100);
	cout << "Introducir una posición de inicio y una longitud para la subcadena. " << endl;
	while(p<=0)
		cin >> p;
	cin >> l;
	
	comparar = comparar_cadenas(c,c1);
	es_palindromo= palindromo(c);
	copiar_cadena(c_copia,c);
	
	if(es_palindromo)
		cout << "La cadena 1 es palindromo" << endl;
	else
		cout << "La cadena 1 no es palindromo" << endl;
	
	cout << "Longitud cadena 1 --> " << longitud_cadena(c) << endl;
	cout << "Longitud cadena 2 --> " << longitud_cadena(c1) << endl;
	
	if(comparar>0)
		cout << "La cadena 1 es mayor que la cadena 2. " << endl;
	else if(comparar<0)
		cout << "La cadena 1 es menor que la cadena 2. " << endl;
	else
		cout << "Las dos cadenas son iguales. " << endl;
	
	cout << "Cadena 1: " << c << " Copia cadena 1: " << c_copia << endl;
	
	encadenar_cadena(c,c1);
	cout << "Cadenas 1 y 2 encadenadas: " << c << endl;
	
	invertir_cadena(c1,c_copia);
	cout << "Cadena 2 invertida: " << c_copia << endl;
	subcadena(c1,c_copia,p,l);
	cout << "Subcadena: " << c_copia << endl;
}
