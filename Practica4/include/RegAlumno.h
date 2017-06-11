#ifndef ALUMNO
#define ALUMNO

struct RegAlumno
{
    char *DNI;
    char *apellido_nombre;
    double *notas;
};

void lee_linea(char c[], int tamano);
char *LeerNombre();
void set_DNI(RegAlumno *alumno, int id);
void set_nota(RegAlumno *alumno, int id, int util);
int *Redimensiona(RegAlumno *&p, int &cap);
double nota_media(const RegAlumno *alumno, int id, double *pesos, int nnotas);
void ordena_nota_media(RegAlumno *v, int util_v, double *pesos, int nnotas);
void imprime(const RegAlumno *alumno, int nalumno, double *pesos, int nnotas);
void Destruir(RegAlumno *&alumno, double *&pesos, int nalumno);

#endif