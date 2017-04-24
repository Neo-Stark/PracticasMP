//Función que devuelve la posición del elemento mayor 
//en un array de enteros.
#include <iostream>
using namespace std;

const int* Pos_mayor( const int* v, int util){
   const int* pos=0;
   int max=0;
   for (int i=0; i<util; i++){
      if(v[i] > max ){
         max = v[i];
         pos = &v[i];
      }
   }
   return pos;
}

int main(){
   int v[100];
   int util=0;
   const int* pos_mayor;

   for (int i=0; i<100 && v[i-1] != -1; i++){
      cin >> v[i];
      util++;
   }

   pos_mayor = Pos_mayor(v,util);
   cout << *pos_mayor;
}
/*
Ejer1: clase vector dinamico, hacer sobrecarga insercion y extraccion
Ejer2: main que escriba una lista en un fichero
Ejer3: main que lea una lista de un fichero*/