#include <iostream>
using namespace std;
#include "MiCadenaClasica.h"

int longitud_cadena (const char *c)
{
	int i=0;
	bool encontrado = false;
	
	while(!encontrado){
		if (*c == '\0' )
			encontrado = true ;
		else
			i++;
			c++;
	}
		return i;
}

bool palindromo(const char *c){
	bool encontrado = true ;
	int l=longitud_cadena(c);
	int i=0;
	const char *p = c+l-1;

	while(i<l/2 && encontrado)
	{
		if(*c!=*p)
			encontrado=false;
		else{
			c++;
			i++;
			p--;
		}
	}	
	return encontrado;
}

void lee_linea(char c[], int tamano){
	do{
		cin.getline(c, tamano);
	} while (c[0] == '\0');
}

int comparar_cadenas(const char *c, const char *c1)
{
	int resultado = 0;
	while(*c!='\0' && *c1!='\0' && resultado == 0){
		if( *c > *c1)
			resultado = 1;
		else if( *c < *c1)
			resultado = -1;
		else{
			c++;
			c1++;
		}
	}
		if( resultado == 0){
			if(longitud_cadena(c) < longitud_cadena(c1))
				resultado = -1;
			else if(longitud_cadena(c) > longitud_cadena(c1))
				resultado = 1;
		}
				
		return resultado;
}

void copiar_cadena(char *c, const char *c1)
{
	while(*c1 != '\0'){
		*c = *c1;
		c++;
		c1++;
	}
	*c = '\0';
}

void encadenar_cadena(char *c, const char *c1){
	c += longitud_cadena(c);
	while(*c1 != '\0'){
		*c = *c1;
		c++;
		c1++;
	}
	*c = '\0';
}

void subcadena(const char *c, char *c1, int p, int l){
	c += p-1;
	int i = 0;
	while( *c != '\0' && i < l){
		*c1 = *c;
		c1++;
		c++;
		i++;
	}
	*c1 = '\0';
}

void invertir_cadena(const char *c, char *c1){
	int l = longitud_cadena(c);
	c += l-1;
	while(l > 0){
		*c1 = *c;
		c1++;
		c--;
		l--;
	}
	*c1 = '\0';
}

void ordenar_matrizcadenas(char cad[][1000], int util){
	char copia[1000];
	int resultado;
	for (int i=0; i < util-1; i++){
		for (int j=0; j < util-2; j++){
			resultado = comparar_cadenas(cad[j],cad[j+1]);
			if(resultado == 1){
				copiar_cadena(copia,cad[j]);
				copiar_cadena(cad[j],cad[j+1]);
				copiar_cadena(cad[j+1],copia);
			}
		}
	}
}
					

