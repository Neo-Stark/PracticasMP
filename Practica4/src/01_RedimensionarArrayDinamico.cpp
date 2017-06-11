#include <iostream>
using namespace std;

const int TAM_BLOQ = 10;

enum TipoRedimension {DeUnoEnUno, EnBloques, Duplicando};

int* Redimensiona(int* p, TipoRedimension tipo, int& cap){
   if( tipo == DeUnoEnUno){
      int *vd_ampliado = new int[ cap + 1 ];

    for (int i= 0; i<cap; i++)
        vd_ampliado[i] = p[i];

    delete [] p;

    p = vd_ampliado;

    cap ++;
   }

   else if ( tipo == EnBloques){
      int *vd_ampliado = new int[ cap + TAM_BLOQ ];

    for (int i= 0; i<cap; i++)
        vd_ampliado[i] = p[i];

    delete [] p;

    p = vd_ampliado;

    cap += TAM_BLOQ;
   }

   else if (tipo == Duplicando){
      int *vd_ampliado = new int[ cap*2 ];

    for (int i= 0; i<cap; i++)
        vd_ampliado[i] = p[i];

    delete [] p;

    p = vd_ampliado;

    cap = cap * 2;
   }
   return p;
}

int main(int argc, char* argv[]){
   int n, TAM = 5;
   int* v_din = new int [TAM];
   char* arg = argv[1];

   cout << "Introduce enteros. Finalice con \"FIN\": ";
   cin >> n;
   while (n != 0){
      static int i=0;
      v_din[i] = n;
      i++;
         
      cin >> n;
      
      if((i==TAM && n != 0) && argc==1)
         v_din = Redimensiona(v_din, DeUnoEnUno, TAM);
      if((i==TAM && n != 0) && *arg=='1')
         v_din = Redimensiona(v_din, DeUnoEnUno, TAM);
      if((i==TAM && n != 0) && *arg=='2')
         v_din = Redimensiona(v_din, EnBloques, TAM);
      if((i==TAM && n != 0) && *arg=='3')
         v_din = Redimensiona(v_din, Duplicando, TAM);
   }
   
   for (int i=0; i<TAM; i++)
   	cout << v_din[i] << endl;
   	
   delete [] v_din;
}