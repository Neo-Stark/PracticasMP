
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const double PI = 3.1415927;  // Cte global por si la necesitamos en otras clases

bool SonIguales(double uno, double otro)
{
	return (abs(uno-otro) <= 1e-5);
}


/////////////////////////////////////////////////////////////////////////
class Punto2D{
private:
   double abscisa  = NAN;
   double ordenada = NAN;
public:
   Punto2D(double abscisaPunto, double ordenadaPunto)
   {
      SetCoordenadas(abscisaPunto, ordenadaPunto);
   }
   
   double Abscisa(){
      return abscisa;
   }
   
   double Ordenada(){
      return ordenada;
   }
   
   void SetCoordenadas(double abscisaPunto, double ordenadaPunto){
      abscisa = abscisaPunto;
      ordenada = ordenadaPunto;
   }
   
   bool EsIgual_a (Punto2D otro_punto){
      return (SonIguales(abscisa, otro_punto.abscisa)
              &&
              SonIguales(ordenada, otro_punto.ordenada));
   }
   
   string ToString(){
		return "(" + to_string(abscisa) + " , " + to_string(ordenada) + ")";
	}
};


class PoligonoRegular{
private:
   
	Punto2D centro;         // Centro de la circunferencia circunscrita que envuelve al pol�gono.
    Punto2D *vertices;      // cordenandas de los vértices del polígono.
	int 	num_lados ;     // N�mero de lados del pol�gono
	double  longitud  ;     // Longitud de cada lado
    void SetVertices()
    {
        vertices = new Punto2D [num_lados];
        
    }
	
	//////////////////////////////////////////////////////////////////
   // Devuelve la longitud del lado del nuevo poligono resultado de 
	// multiplicar por factor_multiplicativo el n�mero de lados. 
	double NuevaLongitudLado (int factor_multiplicativo){
		int nuevo_numero_lados;
		
		nuevo_numero_lados = factor_multiplicativo * num_lados;

		return Radio() * sqrt(2 * (1 - cos(2*PI / nuevo_numero_lados)));
	}
	
	bool EsCorrecto(int num_lados, double longitud){
	  return 0 < num_lados && 0 < longitud; 
   }

public:
   PoligonoRegular (Punto2D centro_poligono,
                    int num_lados_poligono,
                    double longitud_lado_poligono
                    )
		:centro (centro_poligono)
	{
      if (EsCorrecto(num_lados_poligono, longitud_lado_poligono))
         num_lados = num_lados_poligono;
         longitud = longitud_lado_poligono;
   }


	// Este constructor llama al anterior (el de los 3 par�metros)
	PoligonoRegular (int num_lados_poligono, double longitud_lado_poligono)
		: PoligonoRegular (Punto2D(0.0,0.0), num_lados_poligono, longitud_lado_poligono)
	{ }

	// Este constructor llama al anterior (el de los 2 par�metros)
	PoligonoRegular()
      :PoligonoRegular (3 , 1)
	{ }

	Punto2D Centro(){
		return centro;	
	}

	double Longitud(){
		return longitud;	
	}
	
	int NumLados(){
		return num_lados;	
	}
	
	double Radio(){
		return longitud / (2.0 * sin(PI / num_lados));	
	}

	double Perimetro(){
		return longitud * num_lados;	
	}
	
	double Area(){
		double radio;
      
      radio = Radio();
		return 0.5 * num_lados * radio * radio * sin(2*PI / num_lados);					
	}

	bool EsMayorQue(PoligonoRegular otro){
		return Area() > otro.Area();
	}
	
	// Develve un nuevo pol�gono, inscrito en la misma circunferencia, 
	// pero multiplicando por un entero factor_multiplicativo el n�mero de lados.
   // El radio sigue siendo el mismo 
	// porque el nuevo pol�gono est� inscrito en la misma circunferencia. 
	
	PoligonoRegular Multiplica (int factor_multiplicativo){
		PoligonoRegular nuevo (centro,
                             num_lados * factor_multiplicativo, 
                             NuevaLongitudLado(factor_multiplicativo));
		return nuevo;
	}
	
	double Ajuste(){
	   double radio = Radio();
	   
	   return PI * radio * radio - Area();
   }
	
};


////////////////////////////////////////////////////////////////////////

int main (){
	PoligonoRegular poligono1;
	PoligonoRegular poligono2 (6, 4);
	
	if (poligono1.EsMayorQue(poligono2))
		cout << "El area de poligono1 es mayor que la de poligono2";
	else 
		cout << "El area de poligono2 es mayor que la de poligono1";		

   PoligonoRegular poligono_doble (poligono1.Multiplica(2));
   
   cout << "\n\n�rea del pol�gono con doble n�mero de lados: " 
        << poligono_doble.Area();
   
   ///////////////////////////////////////////////////////////
	
	while (! SonIguales(0.0 , poligono_doble.Ajuste())) {
		poligono_doble = poligono_doble.Multiplica(2);
	}

	cout << "\n\nEl pol�gono envolvente tiene " 
	     << poligono_doble.NumLados() << " lados\n\n";
}

