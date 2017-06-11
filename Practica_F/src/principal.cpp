/*************************************************************************************
// Autor: Francisco José González García
// Fichero: principal.cpp

// Lee desde la entrada estándar el contenido de una matriz dispersa.
// Guarda el contenido de la matriz en un fichero.
// Si no se proporciona ningún fichero muestra los datos por la salida estándar.

// Uso: MatrizDispersa.exe [<fich>]

//  <fich> Es el nombre del fichero donde se guarda los datos de la matriz 
//         con el formato establecido.
*************************************************************************************/

using namespace std;
#include <iostream>
#include <fstream>
#include "matrizDispersa.h"
#include <cstdlib>

int main(int argc, char **argv)
{
    MatrizDispersa matriz;

    if (argc != 2)
    {
        cerr << "Parametros incorrectos. Uso: " << argv[0] << " <fich> ";
        exit(1);
    }

    cin >> matriz;
    salvar(argv[1], matriz);
}