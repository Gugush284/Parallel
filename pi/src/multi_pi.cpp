#include <math.h>
#include "multi_pi.h" 


double multi_pi(int n)
{
    double pi = 0;
    double start, end;
    
    #pragma omp parallel reduction(+:pi)
    {   
        #pragma omp for
        for (int i = 0; i < n; i++)
        {
            pi = pi + 4.0 * pow(-1, i) / (2.0 * i + 1.0);
        }
    }

    return pi;
}