#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    int i, x;
    ifstream inData;

    inData.open("fich.txt");

 /*   for (i=1; i<=1000; i++)
    {
        inData >> x;
        cout << x << ' ';
    }
   */ 
    while ( inData >> x )
    	cout << x << ' ';
        
    inData.close();
}


 
 
