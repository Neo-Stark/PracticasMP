#include <fstream>

using namespace std;

int main()
{
    ofstream outData;

    outData.open("fich.txt");

    for (int i=1; i<=1000; i++)
       outData << i << endl;

    outData.close();
}


 
