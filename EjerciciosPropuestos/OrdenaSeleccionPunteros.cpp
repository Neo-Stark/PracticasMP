#include <iostream>
using namespace std;
void ordenacionPorSeleccion(const int * v[], int util_v){
int pos_min;
const int *aux;
for (int i=0; i<util_v-1; i++){
pos_min=i;
for (int j=i+1; j<util_v; j++)
if (*v[j] < *v[pos_min])
pos_min=j;
aux = v[i];
v[i] = v[pos_min];
v[pos_min] = aux;
}
}

int main(){
const int DIMARRAY=100;
const int* arrayPunts[DIMARRAY];
const int arrayInts[DIMARRAY]={5,7,3,2};
int utilArray=4;
for(int i=0; i< utilArray; i++){
arrayPunts[i] = &arrayInts[i];
}
cout<<"Array antes de ordenar (impreso con arrayPunts):"<<endl;
for(int i=0; i< utilArray; i++){
cout << *arrayPunts[i] << " ";
}
cout << endl;
ordenacionPorSeleccion(arrayPunts,utilArray);
cout<<"Array despues de ordenar (impreso con arrayPunts):"<<endl;
for(int i=0; i< utilArray; i++){
cout << *arrayPunts[i] << " ";
}
cout << endl;
cout<<"Array despues de ordenar (impreso con arrayInts):"<<endl;
for(int i=0; i< utilArray; i++){
cout << arrayInts[i] << " ";
}
cout << endl;
}