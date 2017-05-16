using namespace std;
#include <iostream>

class Binario
{
   private:
   char *ptr;
   void liberar();
   void copiar();

   public:
   Binario();
   Binario(int x);
   Binario(string cadena);
   ~Binario();
   Binario(const Binario &copia);
   Binario &operator=(const Binario& otro_b);
   Binario &operator+(const Binario& otro_b);
}


Binario::Binario()
{
   ptr = new char [2];
   ptr[0] = '0';
   ptr[1] = '\0';
}

Binario::Binario(int x)
{
   string binario;
   if (x > 0)
   {
      while (x > 0)
      {
         if (x%2 == 0)
            binario = "0" + binario;
         else
            binario = "1" + binario;
         
         x = x/2;
      }
   }
   else
      binario = "0";
   
   ptr = new char [binario.size() + 1];
   strcpy(ptr, binario.c_str());
}

Binario::Binario(string candena)
{
   bool valido = true;

   for (int i=0; i < cadena.size() && valido; i++)
      if ( cadena[i] != '0' && cadena[i] != '1')
         valido = false;

      if (!valido)
         Binario();
      else
         ptr = new char [cadena.size() + 1];
         strcpy (ptr, cadena.c_string());

}

void Binario::liberar()
{
   if (ptr != 0)
      delete [] ptr;
   ptr = 0;   
}

Binario::~Binario()
{
   liberar();
}

void Binario::copiar(const Binario &copia)
{
   ptr = new char [strlen(copia.ptr) + 1];

   strcpy (ptr, copia.ptr);
}

Binario::Binario(const Binario &copia)
{
   copiar(copia);
}

Binario& Binario::operator=(const Binario &otro_b)
{
   if (this != &otro_b)
   {
      liberar();
      copiar(otro_b);
   }

   return *this;
}

Binario &Binario::operator+(const Binario& otro_b)
{
   int suma = to_int() + otro_b.to_int();

   return suma;
}

int Binario::to_int()
{
   int numero =0;
   int l = strlen(ptr);
}