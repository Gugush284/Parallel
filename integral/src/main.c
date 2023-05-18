#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "main.h"

extern double fsin(double x);
extern void* thr_func(void* arg);

int main()
{
    double summ;
    pthread_t thr[num_thr];
    int rc;
    thread_data_t thr_data[num_thr];

    for (int i = 0; i < num_thr; i++)
    {
        thr_data[i].tid = i;
        thr_data[i].start = start + (end-start)*i/num_thr;
        thr_data[i].end = start + (end-start)*(i+1)/num_thr;
        thr_data[i].eps = eps * (i + 1);

        rc = pthread_create(&thr[i], NULL, thr_func, &thr_data[i]);

        if (rc)
        {
            fprintf(stderr, "error:pthread_create, rc:%d\n", rc);
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < num_thr; i++)
        pthread_join(thr[i], NULL);

    for (int i = 0; i < num_thr; i++)
        summ += thr_data[i].summ;
    printf("%le\n", summ);

    return 0;
}