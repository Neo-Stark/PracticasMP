using namespace std;
#include <iostream>
#include <cstring>

struct RegAlumno {
   char * DNI;
   char * apellido_nombre;
   double * notas;
};

void Push_back_double(double *&v, double x)
{
   static int util=0;
   double *vd_ampliado = new double[ util + 1 ];

    for (int i= 0; i<util; i++)
        vd_ampliado[i] = v[i];

    delete [] v;

    v = vd_ampliado;
    v[util] = x;

    util ++;
   
}

void nuevo_alumno(RegAlumno *alumno, int util, char DNI, char nombre, double notas)
{
   RegAlumno *vd_ampliado = new RegAlumno[ util + 1 ];

    for (int i= 0; i<util; i++)
        vd_ampliado[i] = alumno[i];

    delete [] alumno;

    alumno = vd_ampliado;
   // alumno->DNI = new char[strlen(DNI)];
    //alumno->apellido_nombre = new char[];

    util ++;
}

////////////////////////////////////////////////////
int main()
{
     RegAlumno * alumno;
     double * pesos;
     int util_pesos=0, util_alumno=0;
     int n;
     char DNI;

     cout << "Introducir el numero de notas: ";
     cin >> util_pesos;
   
     for (int i=0; i <util_pesos; i++)
     {
         cout << "Introducir peso de las notas (hasta sumar 100%): ";
         cin >> n;
         Push_back_double (pesos,n);
     }

     n=0;
     for (int i=0;i<util_pesos;i++){
        cout << pesos[i] <<endl;
      n+=pesos[i];
     }

     if (n == 100){
        cin >> DNI;
        cout << DNI;
     }
}

////////////////////////////////////////////////////
