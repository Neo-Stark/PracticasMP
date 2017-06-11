using namespace std;
#include <iostream>

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