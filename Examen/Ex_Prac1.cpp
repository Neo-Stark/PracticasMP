using namespace std;
#include <iostream>

void quita_repes(double *&v, int &util)
{
   int a_escribir = 0, quitados = 0;
   double aux = -1;

   for (int a_leer = 0; a_leer < util; a_leer++)
   {
      if (aux != v[a_leer])
      {
         v[a_escribir] = v[a_leer];
         a_escribir++;
         aux = v[a_leer];
      }
      else
         quitados++;
   }

   util -= quitados;
   quitados =0;
   for (int i=0; i<util;i++)
   {
      a_escribir= i+1;
      aux = v[i];
      for (int j=i+1; j<util; j++)
      {
         if (aux != v[j])
      {
         v[a_escribir] = v[j];
         a_escribir++;
      }
      else
         quitados++;
      }
      util -= quitados;
      quitados = 0;
   }

   double *v_amp = new double[util];
   for (int i = 0; i < util; i++)
      v_amp[i] = v[i];

   delete[] v;
   v = v_amp;
}

void inserta(double *&v, double n, int &util)
{
   double *v_amp = new double[util + 1];
   for (int i = 0; i < util; i++)
      v_amp[i] = v[i];

   delete[] v;
   v = v_amp;
   v[util] = n;
   util++;
}

int main()
{
   double *v = 0;
   int util_v = 0;
   double n = 0;

   while (n != -1)
   {
      cin >> n;
      if (n != -1)
         inserta(v, n, util_v);
   }

   quita_repes(v, util_v);
   for (int i = 0; i < util_v; i++)
      cout << v[i] << endl;
}