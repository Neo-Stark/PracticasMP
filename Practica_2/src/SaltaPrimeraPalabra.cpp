#include <iostream>
using namespace std;

void EliminaExcesoBlancos(char *c){
   	int posicion_lectura, posicion_escritura = 0;
   	int quitados = 0;
   	const char a_borrar = ' ';
   	
		for(posicion_lectura = 0; c[posicion_lectura]!='\0'; posicion_lectura++){
			if(c[posicion_lectura] != a_borrar){
				c[posicion_escritura] = c[posicion_lectura];
				posicion_escritura++;
			}
			else 	if(c[posicion_lectura +1] != a_borrar){
						c[posicion_escritura] = c[posicion_lectura];
						posicion_escritura++;
					}
			else
				quitados++;
		}
		c[posicion_lectura - quitados] = '\0';
}

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

void QuitaPrimerEspacio(char *c){
	if(*c == ' ')
		for (int i=0; c[i]!='\0';i++)
			c[i] = c[i+1];
}

void quita_palabra(char *c, int &posicion){
	EliminaExcesoBlancos(c);
	QuitaPrimerEspacio(c);
	posicion = Encuentra_espacio(c);
	if (posicion == -1)
		*c = '\0';
}

void lee_linea(char c[], int tamano){
	do{
		cin.getline(c, tamano);
	} while (c[0] == '\0');
}

int main(){
	const int TAMANIO = 100;
	char c[TAMANIO];
	int posicion;

	lee_linea(c,TAMANIO);
	quita_palabra(c,posicion);
	
	if (c[0] == '\0')
		cout << "La cadena queda vacía tras quitar la primera palabra. " << endl;
	else 
		cout << "Cadena tras quitar la primera palabra:" << c + posicion << endl;
}
