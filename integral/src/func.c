#include <math.h>
#include <pthread.h>
#include "func.h"

double fsin(double x)
{
    if (x == 0){
        return 0;
    }

    return sin(1/x);
}

void* thr_func(void* arg)
{
    double x, h;
    thread_data *data = (thread_data *) arg;
    data->summ = 0;

    h = sqrt(data->eps * 4 * pow(data->start, 3) / 10 / (data->end - data->start));
    x = data->start;
    while(x < data->end - h)
    {
        data->summ += (fsin(x) + fsin(x+h))*h/2;
        x += h;
    }
    data->summ += (fsin(x) + fsin(data->end))*(data->end-x)/2;

    return NULL;
}