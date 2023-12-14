#include <math.h>
#include"pi.h" 

double pi(int n) 
{ 
    double pi = 0;
    
    double start, end;
    
    for (int i = 0; i < n; i++)
    {
        pi = pi + 4.0 * pow(-1, i) / (2.0 * i + 1.0);
    }

    return pi;
} 
