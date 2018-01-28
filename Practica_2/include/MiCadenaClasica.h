#ifndef MICADENACLASICA
#define MICADENACLASICA

int longitud_cadena (const char *c);
bool palindromo(const char *c);
void lee_linea(char c[], int tamano);
int comparar_cadenas(const char *c, const char *c1);
void copiar_cadena(char *c, const char *c1);
void encadenar_cadena(char *c, const char *c1);
void subcadena(const char *c, char *c1, int p, int l);
void invertir_cadena(const char *c, char *c1);
void ordenar_matrizcadenas(char cad[][1000], int util);
#endif
