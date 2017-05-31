mezclar dos ficheros de entrada en un fichero ordenado.


int mezclar(ifstream& fichero1, ifstream& fichero2, ofstream& fichero3)
{
    int entero1, entero2;
    fichero1 >> entero1;
    fichero2 >> entero2;

    while(!fichero1.eof() && ! fichero2.eof() )
        if ( entero1 < entero2)
        {
        fichero3 << entero1 << endl;
        fichero1 >> entero1;
        }
        else 
        {
            fichero3 << entero2 << endl;
            fichero2 >> entero2;
        }
    
    if ( fichero1.eof() )
        while( ! fichero2.eof() )
        {
            fichero3 << entero2 << endl;
            fichero2 >> entero2;
        }
    if ( fichero2.eof() )
        while( ! fichero1.eof() )
        {
            fichero3 << entero1 << endl;
            fichero1 >> entero1;
        }
    
    return 0;
}

int main()
{
    ifstream f1("fichero1.txt"), f2("fichero2.txt");
    ofstream fo("ficherosalida.txt");
    
    mezclar(f1, f2, fo);

    f1.close();
    f2.close();
    fo.close();
}