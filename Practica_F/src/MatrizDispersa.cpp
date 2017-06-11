/*************************************************************************************
// Autor: Francisco José González García
// Fichero: MatrizDispersa.cpp

// Contiene la definición de los métodos y funciones necesarias para usar la clase 
// "MatrizDinamica".
*************************************************************************************/
using namespace std;
#include <iostream>
#include <fstream>
#include "matrizDispersa.h"
#include <cstdlib>
#include <cstring>

// Añade un nuevo valor a un vector-C de datos de tipo Valor.
// Reservando la memoria necesaria en cada llamada.
void AniadeValor(const Valor *vi, int i, Valor *vs, int &ns)
{
	Valor *ptr_n = new Valor[ns + 1];

	for (int j = 0; j < ns; j++)
		ptr_n[j] = vs[j];

	delete[] vs;

	vs = ptr_n;
	vs[ns] = vi[i];
	ns++;
}

// Recibe dos vectores-C de datos de tipo Valor, devuelve un tercero
// añadiendo los valores de cada posición de ambos vectores y sumándolos
// si estas coinciden.
int combinarSuma(const Valor *v1, int n1, const Valor *v2, int n2, Valor *v3)
{
	bool iguales = false;
	int n3 = 0, x = 0;

	for (int i = 0; i < n1; i++)
	{
		AniadeValor(v1, i, v3, n3);
	}

	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < n1 && !iguales; j++)
		{
			iguales = v2[i].fila == v3[j].fila &&
					  v2[i].columna == v3[j].columna;
			x = j;
		}

		if (iguales)
		{
			v3[x].valor += v2[i].valor;
			if (v3[x].valor == 0)
			{
				for (int j = x; j < n3 - 1; j++)
					v3[j] = v3[j + 1];
				n3--;
			}
			iguales = false;
		}
		else
		{
			AniadeValor(v2, i, v3, n3);
		}
	}
	return n3;
}

// Destructor.
MatrizDispersa::~MatrizDispersa()
{
	delete[] valores;
	valores = 0;
}

// Constructor MatrizDispersa que construye la matriz a partir de
// tres vectores-C de datos de tipo Valor.
MatrizDispersa::MatrizDispersa(int nfil, int ncol, Valor *v1, int n1,
							   Valor *v2, int n2, Valor *v3, int n3)
	: nfilas(nfil), ncolumnas(ncol)
{
	valores = new Valor[n1 + n2 + n3];

	for (int i = 0; i < n1; i++)
		AniadeValor(v1, i, valores, numero_valores);

	for (int i = 0; i < n2; i++)
		AniadeValor(v2, i, valores, numero_valores);

	for (int i = 0; i < n3; i++)
		AniadeValor(v3, i, valores, numero_valores);
}

// Método privado que copia una matriz dada
// en el objeto que llama al método.
void MatrizDispersa::copiar_desde(const MatrizDispersa &copia)
{
	nfilas = copia.nfilas;
	ncolumnas = copia.ncolumnas;
	numero_valores = 0;
	valores = new Valor[copia.numero_valores];

	for (int i = 0; i < copia.numero_valores; i++)
		AniadeValor(copia.valores, i, valores, numero_valores);
}

// Constructor de copia.
MatrizDispersa::MatrizDispersa(const MatrizDispersa &copia)
{
	copiar_desde(copia);
}

// Sobrecarga del operador de asignación.
MatrizDispersa &MatrizDispersa::operator=(const MatrizDispersa &copia)
{
	if (this != &copia)
	{
		delete[] valores;
		copiar_desde(copia);
	}

	return *this;
}

// Devuelve el valor de una posición de la matriz
// dada una fila y una columna.
// Pre: los valores de fila y columna son siempre válidos.
double MatrizDispersa::obtenerValor(int fila, int col)
{
	double valor = 0;
	bool encontrado = false;

	for (int i = 0; i < numero_valores && !encontrado; i++)
	{
		encontrado = fila == valores[i].fila && col == valores[i].columna;
		if (encontrado)
			valor = valores[i].valor;
	}
	return valor;
}

// Asigna un valor dada una fila y columna de la matriz
// Si existía un valor anteriormente lo sustituye.
void MatrizDispersa::asignarValor(int fila, int col, double valor)
{
	bool es_cero = valor == 0;
	bool existe_valor = false;
	int pos;

	for (int i = 0; i < numero_valores && !existe_valor; i++)
		if (fila == valores[i].fila && col == valores[i].columna)
		{
			existe_valor = valores[i].valor != 0;
			pos = i;
		}

	if (es_cero)
	{
		if (existe_valor)
		{
			for (int i = pos; i < numero_valores - 1; i++)
				valores[i] = valores[i + 1];
			numero_valores--;
		}
	}
	else
	{
		if (existe_valor)
			valores[pos].valor = valor;
		else
		{
			valores[numero_valores].valor = valor;
			valores[numero_valores].fila = fila;
			valores[numero_valores].columna = col;
			numero_valores++;
		}
	}
}

// Sobrecarga del operador suma
// Hace uso de la función externa combinarSuma
// para obtener una matriz de salida con los valores sumados.
// Pre: las matrices sumadas tienen el mismo número de filas y columnas.
MatrizDispersa MatrizDispersa::operator+(const MatrizDispersa &copia)
{
	MatrizDispersa suma;
	suma.numero_valores = combinarSuma(valores, numero_valores, copia.valores, copia.numero_valores, suma.valores);
	suma.nfilas = nfilas;
	suma.ncolumnas = ncolumnas;

	return suma;
}

// Sobrecarga del operador de inserción.
// Obtiene en un flujo de salida el contenido de la matriz en formato texto.
ostream &operator<<(ostream &flujo, const MatrizDispersa &matriz)
{
	flujo << "Numero de filas: " << matriz.nfilas << endl;
	flujo << "Numero de columnas: " << matriz.ncolumnas << endl;
	flujo << "Numero de valores: " << matriz.numero_valores << endl;

	for (int i = 0; i < matriz.numero_valores; i++)
	{
		flujo << "Valor " << i + 1 << ": "
			  << matriz.valores[i].valor << " ( " << matriz.valores[i].fila
			  << ", " << matriz.valores[i].columna << " )" << endl;
	}

	return flujo;
}

// Sobrecarga del operador de extracción.
// Obtiene desde un flujo de entrada el contenido de una matriz.
istream &operator>>(istream &flujo, MatrizDispersa &matriz)
{
	flujo >> matriz.nfilas >> matriz.ncolumnas >> matriz.numero_valores;

	delete[] matriz.valores;
	matriz.valores = new Valor[matriz.numero_valores];

	for (int i = 0; i < matriz.numero_valores; i++)
		flujo >> matriz.valores[i].fila >> matriz.valores[i].columna >> matriz.valores[i].valor;

	return flujo;
}

// Desde un fichero de entrada carga los datos
// en un objeto del tipo MatrizDispersa.
// Devuelve si la operación ha tenido éxito.
int cargar(char *fichero, MatrizDispersa &matriz)
{
	ifstream fi;
	fi.open(fichero);
	if (!fi)
	{
		cout << "Error: no se pudo abrir " << fichero << endl;
		return 1;
	}
	char cadena[20];
	fi >> cadena;
	if (!strcmp(cadena, "MP-MATRIZDISPERSA-1.0"))
		fi >> matriz;
	else
	{
		cerr << "Formato no correcto. " << endl;
		return 1;
	}

	fi.close();
	return 0;
}
// Guarda en un fichero de salida los datos de una
// matriz según el formato establecido.
// Devuelve si ha tenido éxito.
int salvar(char *fichero, const MatrizDispersa &matriz)
{
	ofstream fo;
	fo.open(fichero);
	if (!fo)
	{
		cout << "Error: no se pudo abrir " << fichero << endl;
		return 1;
	}
	fo << "MP-MATRIZDISPERSA-1.0" << endl;
	fo << matriz;

	fo.close();
	return 0;
}

// Constructor que recibe como parametros el numero de filas y columnas
// y como tercer parametro opcional un array de datos que permite rellenar
// el array de valores con los valores distintos de 0.
// Por defecto el tercer parametro crea una matriz vacia.
MatrizDispersa::MatrizDispersa(int nfil, int ncol, double *datos)
	: nfilas(nfil), ncolumnas(ncol)
{
	int cont = 0;
	if (datos = 0)
		numero_valores = 0;
	else
	{
		for (int i = 0; i < nfilas; i++)
			for (int j = 0; i < ncolumnas; j++)
			{
				if (datos[cont] != 0)
					asignarValor(i, j, datos[cont]);
				cont++;
			}
	}
}

// Elimina todos aquellos valores que estén por debajo
// del umbral estabecido por el dato valor.
// Se crea un nuevo vector de datos de tipo Valor
// donde se almacenan los valores que cumplen la condición establecida.
// Posteriormente se actualizan los valores del objeto con datos ya simplificados.
void MatrizDispersa::podar(double valor)
{
	Valor *poda;
	int n_valores_poda;

	for (int i = 0; i < numero_valores; i++)
	{
		if (valores[i].valor >= valor)
			AniadeValor(valores, i, poda, n_valores_poda);
	}

	delete[] valores;
	valores = poda;
	numero_valores = n_valores_poda;
}