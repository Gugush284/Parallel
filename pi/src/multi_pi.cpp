#include <math.h>
#include <omp.h>
#include "multi_pi.h" 


double multi_pi(int n, int num_thr)
{
    double pi = 0;

    #pragma omp parallel num_threads(num_thr)
    {
        #pragma omp parallel reduction(+:pi)
        {   
            #pragma omp for
            for (int i = 0; i < n; i++)
            {
                pi = pi + 4.0 * pow(-1, i) / (2.0 * i + 1.0);
            }
        }
    }

    return pi;
}