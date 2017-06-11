/*************************************************************************************
// Autor: Francisco José González García
// Fichero: Skyline.cpp

// Contiene la definición de los métodos y funciones necesarias para usar la clase 
// "SkyLine".
*************************************************************************************/

using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>
#include "skyline.h"

// Mezcla en un vector de salida dos vectores-C de datos de tipo double
// Pre: los vectores de entrada están ordenados.
int MezclarUnico(double *v1, int util_v1, double *v2, int util_v2, double *vs)
{
	int i = 0, j = 0, util_vs = 0;
	while (i < util_v1 && j < util_v2)
		if (v1[i] < v2[j])
		{
			vs[util_vs] = v1[i];

			util_vs++;
			i++;
		}
		else if (v2[j] < v1[i])
		{
			vs[util_vs] = v2[j];

			util_vs++;
			j++;
		}
		else
			i++;

	if (i == util_v1)
		for (int k = j; k < util_v2; k++)
		{
			vs[util_vs] = v2[k];
			util_vs++;
		}
	else
		for (int k = i; k < util_v1; k++)
		{
			vs[util_vs] = v1[k];
			util_vs++;
		}
	return util_vs;
}

// Comprueba si los datos pasados como argumentos son válidos.
bool SkyLine::es_valido(double abscisa, double altura, int i)
{
	bool valido = true;
	if (i > 0)
		valido = abscisa > abscisas[i - 1];
	if (valido)
	{
		if (i != n - 1)
			valido = altura >= 0;
		else
			valido = altura == 0;
	}
	return valido;
}

void SkyLine::limpiar()
{
	delete[] abscisas;
	delete[] alturas;
	n = 0;
}

// Método privado que copia el contenido de un skyline
// pasada como parámetro en el skyline objeto.
void SkyLine::copiar_desde(const SkyLine &copia)
{
	n = copia.n;
	abscisas = new double[n];
	alturas = new double[n];

	for (int i = 0; i < n; i++)
	{
		abscisas[i] = copia.abscisas[i];
		alturas[i] = copia.alturas[i];
	}
}

// Destructor.
SkyLine::~SkyLine()
{
	limpiar();
}

// Constructor que crea un edificio a partir de dos valores
// para las abscisas y un tercero para la altura.
SkyLine::SkyLine(double x1, double x2, double y1)
	: n(2)
{
	if (x1 < x2)
	{
		abscisas = new double[n];
		alturas = new double[n];

		abscisas[0] = x1;
		alturas[0] = y1;
		abscisas[1] = x2;
		alturas[1] = 0;
	}
	else
		SkyLine();
}

// Constructor de copia.
SkyLine::SkyLine(const SkyLine &copia)
{
	copiar_desde(copia);
}

// Sobrecarga de operador de asignación.
SkyLine &SkyLine::operator=(const SkyLine &copia)
{
	if (this != &copia)
	{
		limpiar();
		copiar_desde(copia);
	}
	return *this;
}

// Devuelve la altura de un skyline dado cualquier punto del mismo.
double SkyLine::Altura(double x) const
{
	double altura = 0;
	if (n != 0 && (x >= abscisas[0] && x < abscisas[n - 1]))
	{
		for (int i = 0; i < n; i++)
			if (x < abscisas[i] && x >= abscisas[i - 1])
				altura = alturas[i - 1];
	}

	return altura;
}

// Sobrecarga del operador suma.
// Devuelve un skyline con las abscisas como la mezcla de los dos
// skylines de entrada y las alturas como la máxima entre ambos.
SkyLine SkyLine::operator+(const SkyLine &sky2) const
{
	SkyLine suma;
	double altura1, altura2;
	suma.abscisas = new double[n + sky2.n];
	suma.alturas = new double[n + sky2.n];
	suma.n = MezclarUnico(abscisas, n, sky2.abscisas, sky2.n, suma.abscisas);

	for (int i = 0; i < suma.n; i++)
	{
		altura1 = Altura(suma.abscisas[i]);
		altura2 = sky2.Altura(suma.abscisas[i]);

		if (altura1 > altura2)
			suma.alturas[i] = altura1;
		else
			suma.alturas[i] = altura2;
	}
	suma.simplificar();
	return suma;
}

// Sobrecarga del operador de inserción.
// Obtiene en un flujo de salida el contenido del skyline en formato texto.
ostream &operator<<(ostream &flujo, const SkyLine &salida)
{
	flujo << "\nNumero de abscisas: " << salida.n << endl;

	for (int i = 0; i < salida.n; i++)
		flujo << "( " << salida.abscisas[i] << ", "
			  << salida.alturas[i] << " )" << endl;
}

// Sobrecarga del operador de extracción.
// Obtiene desde un flujo de entrada el contenido de un skyline.
istream &operator>>(istream &flujo, SkyLine &entrada)
{
	double abscisa, altura;
	bool valido = true;
	entrada.limpiar();

	cout << "\nIntroducir numero de abscisas: ";
	flujo >> entrada.n;

	entrada.abscisas = new double[entrada.n];
	entrada.alturas = new double[entrada.n];

	for (int i = 0; i < entrada.n && valido; i++)
	{
		cout << "\nIntroduzca valor de abscisa y altura: ";
		flujo >> abscisa;
		flujo >> altura;
		valido = entrada.es_valido(abscisa, altura, i);

		if (valido)
		{
			entrada.abscisas[i] = abscisa;
			entrada.alturas[i] = altura;
		}
		else
			cout << "\nPunto no valido. Fin de la entrada de datos." << endl;
	}

	return flujo;
}

// Desde un fichero de entrada carga los datos
// en un objeto del tipo SkyLine.
// Devuelve si la operación ha tenido éxito.
int cargar(char *fichero, SkyLine &sky)
{
	ifstream inData;
	inData.open(fichero);
	if (!inData)
	{
		cout << "Error: no se pudo abrir " << fichero << endl;
		return (1);
	}
	char cadena[14];
	inData >> cadena;
	if (!strcmp(cadena, "MP-SKYLINE-1.0"))
		inData >> sky;

	inData.close();
	return 0;
}

// Guarda en un fichero de salida los datos de una
// skyline según el formato establecido.
// Devuelve si ha tenido éxito.
int salvar(char *fichero, SkyLine &sky)
{
	ofstream Outdata;
	Outdata.open(fichero);
	if (!Outdata)
	{
		cout << "Error: no se pudo abrir " << fichero << endl;
		return (1);
	}
	Outdata << "MP-SKYLINE-1.0" << endl;
	Outdata << sky;

	Outdata.close();

	return 0;
}

// Simplifica el skyline eliminando los puntos donde
// las alturas se repiten, dejando solo uno de ellos.
void SkyLine::simplificar()
{
	int quitados = 0, cont = 0;

	for (int i = 0; i < n; i++)
		if (i == 0 || alturas[i] != alturas[i - 1])
		{
			abscisas[cont] = abscisas[i];
			alturas[cont] = alturas[i];
			cont++;
		}
		else
			quitados++;

	n -= quitados;
}