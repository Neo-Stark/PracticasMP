using namespace std;
#include <iostream>

const int DIM = 100;
int MezclarUnico (double *v1, int util_v1, double *v2, int util_v2, double *vs)
{
    int i=0, j=0, util_vs=0;
    while ( i < util_v1  && j < util_v2 )
        if ( v1[i] < v2[j] )
        {
            vs[util_vs] = v1[i];
            
            util_vs++;
            i++;
        } 
        else if (v2[j] < v1[i])
        {
            vs[util_vs] = v2[j];
            
            util_vs++;
            j++;         
        } 
        else 
            i++;
        
     if ( i == util_v1 )
        for ( int k = j; k < util_v2; k++ )
            {
                vs[util_vs] = v2[k];
                util_vs++;
            }
     else    
        for ( int k = i; k < util_v1; k++ )
            {
                vs[util_vs] = v1[k];
                util_vs++;
            }
    return util_vs;

}

int main()
{
    double v1[DIM], v2[DIM], vs[DIM], n=0;
    int util_v1=0, util_v2=0, util_vs=0, i=0;

    while(i<DIM && n != -1)
    {
        cin >> n;
        if (n != -1)
        {
            v1[i] = n;
            util_v1++;
        }
        i++;
    }
    i=0;
    n=0;

    while(i<DIM && n != -1)
    {
        cin >> n;
        if (n != -1)
        {
            v2[i] = n;
            util_v2++;
        }
        i++;
    }

    util_vs = MezclarUnico(v1, util_v1, v2, util_v2, vs);
    for (int i=0; i<util_vs; i++)
        cout << vs[i] << ' ';
}