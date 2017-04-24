#include <iostream>
using namespace std;

class Complejo
{
    private:
        double real;
        double imag;
        
    public:
    	
        Complejo()
        { 
		     real = imag = 0;
		}
    	
        Complejo(double re, double im)
        { 
		     real = re;
		     imag = im;
		}

        void AsignarReal(double re) 
        {
             real = re;
        }
        
        void AsignarImag(double im)
        {
            imag = im;
        }
        
        double ParteReal() 
        {
            return real;
        }

        double ParteImag()
        {
            return imag;
        }
     
        Complejo Suma(const Complejo &c1)
        {
            Complejo salida;
            
            salida.real = real + c1.real;
            salida.imag = imag + c1.imag;
            
            return salida;
        }
};

//..............................................................................
int main ()
{
     Complejo c1(6, 4), c2, cs;
     
     c2.AsignarReal(-7);
     c2.AsignarImag(5);
     
     cs = c1.Suma(c2);
     
     cout << "La suma es: " << cs.ParteReal() << "+" << cs.ParteImag() << "i"<< endl;
}
 
