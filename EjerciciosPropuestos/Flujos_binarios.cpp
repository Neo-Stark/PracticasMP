using namespace std;
#include <iostream>
#include <fstream>

int main(int argc, char ** argv)
{
    ifstream fi;
    ofstream fo(argv[2]);
    double n;

    fi.open((argv[1]));
    fo.open(argv[2], ios::binary);

    // Comprobar fi y fo

    if(!fi && !fo)
        while ( fi.read( (char *) (&n), sizeof (double) ) )
        {
            fo.write( (const char *) (&n), sizeof (double) )
            cout << n;
        }
        
    fi.close();
    fo.close();
}