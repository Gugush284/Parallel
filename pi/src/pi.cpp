#include <math.h>
#include <ctime>
#include"pi.h" 

double pi(int n, double * time) 
{ 
    double pi = 0;

    double start, end;
    
    start = clock();
    for (int i = 0; i < n; i++)
    {
        pi = pi + 4.0 * pow(-1, i) / (2.0 * i + 1.0);
    }
    end = clock();

    if (time != NULL)
        * time = (end - start) / CLOCKS_PER_SEC;

    return pi;
} 
