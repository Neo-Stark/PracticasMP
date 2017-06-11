/*************************************************************************************
// Autor: Francisco José González García
// Fichero: montar.cpp

// Lee desde la entrada estándar una secuencia de edificios y escribe en un fichero el skyline resultado.
// La entrada termina cuando se introduce una base con dos valores idénticos.

// Uso: Skyline.exe <fich>

//  <fich> fichero de salida donde se guardará el skyline resultado.
*************************************************************************************/

using namespace std;
#include <iostream>
#include <fstream>
#include "skyline.h"
#include <cstdlib>

int main(int argc, char *argv[])
{
	double x1, x2, h;

	if (argc == 1)
	{
		cerr << "Error: numero de argumentos incorrectos. " << endl
			 << "Uso: " << argv[0] << " <fich> ";
		return 1;
	}
	cin >> x1 >> x2 >> h;
	SkyLine edificios(x1, x2, h);
	while (x1 != x2)
	{
		cin >> x1 >> x2;
		while (x1 > x2)
		{
			cout << "Error:La abscisa 1 debe ser menor que la 2" << endl;
			cin >> x1 >> x2;
		}
		if (x1 != x2)
		{
			cin >> h;
			SkyLine aux(x1, x2, h);
			edificios = edificios + aux;
		}
	}

	salvar(argv[1], edificios);
}