#include <fstream>
#include <iostream>
#include "MiCadenaClasica.h"

using namespace std;

int main()
{
    int UtilF_cad=0;
    ifstream inData;
    char cad[1000][1000];
    
    inData.open("fich_nombres.txt");

    while ( inData.getline(cad[UtilF_cad], 1000) )     
        UtilF_cad++;
     
	 cout << "Antes de ordenar:" << endl;   
    for (int i=0; i<UtilF_cad; i++)
       cout << cad[i] << endl;
   
   ordenar_matrizcadenas(cad, UtilF_cad);
   cout << "\nDespu�s de ordenar: " << endl;
   for (int i=0; i<UtilF_cad; i++)
       cout << cad[i] << endl;
	
	inData.close();
}


 
 
