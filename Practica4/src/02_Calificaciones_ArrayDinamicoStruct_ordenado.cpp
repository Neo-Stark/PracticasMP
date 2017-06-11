/***********************************************************************************
// Autor: Francisco Jose Gonzalez Garcia
// Fichero: 02_Calificaciones_ArrayDinamicoStruct_ordenado.cpp

// Crea una lista de alumnos a partir de unos datos introducidos por la entrada estandar
// siguendo el formato: DNI, Apellido, Nombre, Notas.
// La lista se ordena de mayor a menor nota media de cada alumno.
***********************************************************************************/

using namespace std;
#include <iostream>
#include <cstring>
#include "RegAlumno.h"

int main()
{

    int util_pesos = 0, util_alumno = 2;
    RegAlumno *alumno;
    double *pesos;
    int n;
    bool fin = false;

    cout << "Introducir el numero de notas: ";
    cin >> util_pesos;
    pesos = new double[util_pesos];

    for (int i = 0; i < util_pesos; i++)
    {
        cout << "Introducir peso de las notas (hasta sumar 100%): ";
        cin >> n;
        pesos[i] = n;
    }

    n = 0;
    for (int i = 0; i < util_pesos; i++)
        n += pesos[i];

    if (n == 100)
    {
        int i = 0;
        alumno = new RegAlumno[util_alumno];
        for (i = 0; i < util_alumno && !fin; i++)
        {
            cout << "Introducir DNI: ";
            set_DNI(alumno, i);
            fin = alumno[i].DNI[0] == '*';
            if (!fin)
            {
                cout << "Introducir nombre: ";
                alumno[i].apellido_nombre = LeerNombre();
                cout << "Introducir notas: ";
                set_nota(alumno, i, util_pesos);
                if (i + 1 == util_alumno)
                    Redimensiona(alumno, util_alumno);
            }
        }
        util_alumno = i - 1;
        if (alumno[0].DNI[0] != '*')
        {
            ordena_nota_media(alumno, util_alumno, pesos, util_pesos);
            imprime(alumno, util_alumno, pesos, util_pesos);
        }
    }
    Destruir(alumno, pesos, util_alumno);
}