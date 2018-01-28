/*********************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2013-2014
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 2
// EJERCICIO 9 (a)
//
/*********************************************************************/

#include <iostream>
#include "Matriz2D-2.h"
using namespace std; 

/*********************************************************************/
/*********************************************************************/

int main (void)
{
	int fils, cols; 

	cout << "Filas = "; 
	cin >> fils; 
	cout << "Columnas = "; 
	cin >> cols; 

	// LECTURA 

	//Matriz2D_2 matriz = LeeMatriz2D_2 (fils, cols);
	//PintaMatriz2D_2 (matriz, fils, cols);

	// INICIALIZACIÓN ALEATORIA

	Matriz2D_2 matriz = AleatorizaMatriz2D_2 (fils, cols, 10);
	PintaMatriz2D_2 (matriz, fils, cols);

	// COPIA

	Matriz2D_2 copia = CopiaMatriz2D_2 (matriz, fils, cols);
	PintaMatriz2D_2 (copia, fils, cols);

	// SUBMATRIZ
	
	int fi, fe, ci, ce;

	cout << "\nFila inicial = "; 
	cin >> fi; 
	cout << "Fila final = "; 
	cin >> fe; 
	cout << "Columna inicial = "; 
	cin >> ci; 
	cout << "Columna final = "; 
	cin >> ce; 

	Matriz2D_2 submatriz = SubMatriz2D_2 (matriz, fi, ci, fe, ce);
	PintaMatriz2D_2 (submatriz, fe-fi+1, ce-ci+1);

	// ELIMINA FILA 
	
	int fila_borrar;

	cout << "\nFila a eliminar = "; 
	cin >> fila_borrar; 

	Matriz2D_2 matriz_una_fila_menos = 
		EliminaFilaMatriz2D_2 (matriz, fils, cols, fila_borrar);

	PintaMatriz2D_2 (matriz_una_fila_menos, fils-1, cols);

	// ELIMINA COLUMNA 
	
	int columna_borrar;

	cout << "\nColumna a eliminar = "; 
	cin >> columna_borrar; 

	Matriz2D_2 matriz_una_columna_menos = 
		EliminaColumnaMatriz2D_2 (matriz, fils, cols, columna_borrar);

	PintaMatriz2D_2 (matriz_una_columna_menos, fils, cols-1);


	// TRASPUESTA

	Matriz2D_2 traspuesta = TraspuestaMatriz2D_2 (matriz, fils, cols);
	cout << "\nMatriz traspuesta = "; 
	PintaMatriz2D_2 (traspuesta, cols, fils);

	// La trasp. de la trasp. es la original
	Matriz2D_2 traspuesta_traspuesta = 
		TraspuestaMatriz2D_2 (traspuesta, cols, fils);

	cout << "\nMatriz traspuesta de la traspuesta= "; 
	PintaMatriz2D_2 (traspuesta_traspuesta, fils, cols);

	// INVERSION FILAS

	Matriz2D_2 invertida = InvierteMatriz2D_2 (matriz, fils, cols); 
	cout << "\nMatriz con filas invertidas= "; 
	PintaMatriz2D_2 (invertida, fils, cols);

	char c;
	cin >> c; 

	return (0);
}

/*********************************************************************/
/*********************************************************************/ 
 
