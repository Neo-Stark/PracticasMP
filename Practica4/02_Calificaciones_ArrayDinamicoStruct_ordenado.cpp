using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>
ifstream entrada("fich_alumnos.txt"); //(Prueba con fichero de entrada)

struct RegAlumno
{
    char *DNI;
    char *apellido_nombre;
    double *notas;
};

void lee_linea(char c[], int tamano)
{
    do
    {
        cin.getline(c, tamano);
    } while (c[0] == '\0');
}

char *LeerNombre()
{
    char cadena[300];
    char *p;

    lee_linea(cadena, 300);

    p = new char[strlen(cadena) + 1];

    strcpy(p, cadena);

    cout << "Nombre: " << p << endl;

    return p;
}

void set_DNI(RegAlumno *alumno, int id)
{
    alumno[id].DNI = new char[9];
    cin >> alumno[id].DNI;
    cout << "DNI " << alumno[id].DNI << endl;
}

void set_nota(RegAlumno *alumno, int id, int util)
{
    alumno[id].notas = new double[util];

    for (int i = 0; i < util; i++)
        cin >> alumno[id].notas[i];
}

int *Redimensiona(RegAlumno *&p, int &cap)
{
    RegAlumno *vd_ampliado = new RegAlumno[cap + 1];

    for (int i = 0; i < cap; i++)
        vd_ampliado[i] = p[i];

    delete[] p;

    p = vd_ampliado;

    cap++;
}

double nota_media(const RegAlumno *alumno, int id, double *pesos, int nnotas)
{
    double nota_media = 0;
    for (int i = 0; i < nnotas; i++)
        nota_media += alumno[id].notas[i] * pesos[i] * 0.01;
    return nota_media;
}

void ordena_nota_media(RegAlumno *v, int util_v, double *pesos, int nnotas)
{
    int pos_max;
    RegAlumno aux;
    if (v[1].DNI[0] != '*')
        for (int i = 0; i < util_v - 1; i++)
        {
            pos_max = i;

            for (int j = i + 1; j < util_v; j++)
                if (nota_media(v, j, pesos, nnotas) > nota_media(v, pos_max, pesos, nnotas))
                    pos_max = j;

            aux = v[i];
            v[i] = v[pos_max];
            v[pos_max] = aux;
        }
}

void imprime(const RegAlumno *alumno, int nalumno, double *pesos, int nnotas)
{
    cout << "\tAlumno "
         << "\tDNI "
         << "\t\tNota media " << endl;
    for (int i = 0; i < nalumno; i++)
    {
        cout << i + 1 << ".- "
             << "\t" << alumno[i].apellido_nombre
             << "\t" << alumno[i].DNI
             << "\t" << nota_media(alumno, i, pesos, nnotas) 
             << endl;
    }
}

void Destruir(RegAlumno *&alumno, double *&pesos, int nalumno)
{   
    delete [] alumno[0].DNI;
    for (int i=0; i<nalumno; i++)
    {
        if(i > 0)
        delete [] alumno[i].DNI;
        delete [] alumno[i].notas;
        delete [] alumno[i].apellido_nombre;
    }
    delete [] alumno;
    delete [] pesos;
    alumno = 0;
    pesos = 0;
}

////////////////////////////////////////////////////
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
        util_alumno = i-1;
        if (alumno[0].DNI[0] != '*')
        {
            ordena_nota_media(alumno, util_alumno, pesos, util_pesos);
            imprime(alumno, util_alumno, pesos, util_pesos);
        }
    }
    Destruir(alumno, pesos, util_alumno);
}

////////////////////////////////////////////////////
