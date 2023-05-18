#include <math.h>
#include <stdio.h>
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
    thread_data *data;
    int count;
    int counter = 0;
    thread *t = (thread *) arg;
    queue *q = t->q;
    
    while(1){
        pthread_mutex_lock(&(q->lock));
        if (q->count >= AMOUNT_TASKS) {
            pthread_mutex_unlock(&(q->lock));
            break;
        }
        count = q->count;
        (q->count)++;
        counter++;
        pthread_mutex_unlock(&(q->lock));

        data = q->tasks + count;

        h = sqrt(data->eps * 4 * pow(data->start, 3) / 10 / (data->end - data->start));
        x = data->start;
        while(x < data->end - h)
        {
            data->summ += (fsin(x) + fsin(x+h))*h/2;
            x += h;
        }
        data->summ += (fsin(x) + fsin(data->end))*(data->end-x)/2;
    }

    printf("id = %d: counter = %d\n", t->id, counter);

    return NULL;
}