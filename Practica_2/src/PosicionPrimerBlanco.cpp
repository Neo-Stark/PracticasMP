
#include <iostream>
using namespace std;

//Método que devuelve la posición del primer espacio en blanco encotrado en 
//una cadena del tipo c-string o -1 si no tiene espacios.
int Encuentra_espacio(const char *c){
	int encontrado = -1;
	int pos = 0;
	while (*c != '\0' && encontrado==-1){
		if (*c == ' ')
			encontrado = pos;
		else{
			c++;
			pos++;
		}
	}
	return encontrado;
}

void lee_linea(char c[], int tamano){
	do{
		cin.getline(c, tamano);
	} while (c[0] == '\0');
}

int main(){
	const int TAMANIO = 100;
	char c[TAMANIO];
	int encontrado;

	lee_linea(c,TAMANIO);
	encontrado = Encuentra_espacio(c);
	if (encontrado == -1)
		cout << "La cadena no tiene espacios blancos. " << endl;
	else 
		cout << "El primer espacio en blanco es el caracter: " << encontrado + 1 << endl;
}
