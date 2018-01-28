#include <iostream>
using namespace std;

struct Tiempo{
	int hora;
	int minuto;
	int segundo;
};

int convertirASegundos(Tiempo tiempo){
	int segundos =		tiempo.hora*3600 + 
						tiempo.minuto*60 +
						tiempo.segundo;
						
	return segundos;
	}

bool esPosterior(Tiempo tiempo1, Tiempo tiempo2){
	int 	segundos1=convertirASegundos(tiempo1), 
			segundos2=convertirASegundos(tiempo2);
	
	return segundos2 > segundos1;
}

	
Tiempo obtenerNuevoTiempo(Tiempo T, int segundos){
	int segundosT2 = convertirASegundos(T) + segundos;
	int resto;
	Tiempo T2;
	
	T2.hora=segundosT2/3600;	
	while(T2.hora > 23)
		T2.hora=T2.hora-24;
	resto=segundosT2%3600;
	
	T2.minuto=resto/60;
	resto=resto%60;
	
	T2.segundo=resto;
	return T2;
}
	

int main(){
	int utilizados=2;
	Tiempo tiempo[utilizados];
	int segundos;
	
	cout << "Introduzca horas, minutos y segundos de dos tramos: " << endl;
	for( int i=0; i<utilizados; i++){
		do{
			cin>>tiempo[i].hora;
		}while(tiempo[i].hora>23);
		do{	
			cin>>tiempo[i].minuto;
		}while(tiempo[i].minuto>59);
		do{
			cin>>tiempo[i].segundo;
		}while(tiempo[i].segundo>59);
	}

	if (esPosterior(tiempo[0],tiempo[1]))
		cout << "El tramo 2 es posterior"<<endl;
	else 
		cout << "El tramo 1 es posterior."<<endl;
		
	cout 	<< "Introduza segundos a añadir: ";
	cin	>> segundos;

	Tiempo tiempo_nuevo(obtenerNuevoTiempo(tiempo[0], segundos));
	
	cout 	<< "\n El nuevo tiempo es: " 	<< tiempo_nuevo.hora 	<< ' '
													<< tiempo_nuevo.minuto	<< ' '
													<< tiempo_nuevo.segundo	<< ' ';
}
