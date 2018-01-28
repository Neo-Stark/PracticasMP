/*********************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2013-2014
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 2
// EJERCICIO 8
//
/*********************************************************************/

#include <iostream>
#include "Matriz2D-1.h"
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

	//Matriz2D_1 matriz = LeeMatriz2D_1 (fils, cols);
	//PintaMatriz2D_1 (matriz, fils, cols);

	// INICIALIZACIÓN ALEATORIA

	Matriz2D_1 matriz = AleatorizaMatriz2D_1 (fils, cols, 10);
	PintaMatriz2D_1 (matriz, fils, cols);

	// COPIA

	Matriz2D_1 copia = CopiaMatriz2D_1 (matriz, fils, cols);
	PintaMatriz2D_1 (copia, fils, cols);

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

	Matriz2D_1 submatriz = SubMatriz2D_1 (matriz, fi, ci, fe, ce);
	PintaMatriz2D_1 (submatriz, fe-fi+1, ce-ci+1);

	// ELIMINA FILA 
	
	int fila_borrar;

	cout << "\nFila a eliminar = "; 
	cin >> fila_borrar; 

	Matriz2D_1 matriz_una_fila_menos = 
		 EliminaFilaMatriz2D_1 (matriz, fils, cols, fila_borrar);

	PintaMatriz2D_1 (matriz_una_fila_menos, fils-1, cols);

	// ELIMINA COLUMNA 
	
	int columna_borrar;

	cout << "\nColumna a eliminar = "; 
	cin >> columna_borrar; 

	Matriz2D_1 matriz_una_columna_menos = 
		EliminaColumnaMatriz2D_1 (matriz, fils, cols, columna_borrar);

	PintaMatriz2D_1 (matriz_una_columna_menos, fils, cols-1);


	// TRASPUESTA

	Matriz2D_1 traspuesta = TraspuestaMatriz2D_1 (matriz, fils, cols);
	cout << "\nMatriz traspuesta = "; 
	PintaMatriz2D_1 (traspuesta, cols, fils);

	// La trasp. de la trasp. es la original
	Matriz2D_1 traspuesta_traspuesta = 
		TraspuestaMatriz2D_1 (traspuesta, cols, fils);

	cout << "\nMatriz traspuesta de la traspuesta= "; 
	PintaMatriz2D_1 (traspuesta_traspuesta, fils, cols);

	// INVERSION FILAS

	Matriz2D_1 invertida = InvierteMatriz2D_1 (matriz, fils, cols); 
	cout << "\nMatriz con filas invertidas= "; 
	PintaMatriz2D_1 (invertida, fils, cols);

	return (0);
}
/*********************************************************************/
/*********************************************************************/ 
 
