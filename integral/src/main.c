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
    taskQueue queue;
    queue.count = 0;
    thr_struct t[num_thr];

    for (int i = 0; i < MAX_TASKS; i++){
        queue.tasks[i].start = start + i * (end - start) / MAX_TASKS;
        queue.tasks[i].end = start + (i+1) * (end - start) / MAX_TASKS;
        queue.tasks[i].eps = eps * (i+1) * (end - start) / MAX_TASKS;
    }

    pthread_mutex_init(&queue.lock, NULL);
    pthread_mutex_lock(&(queue.lock));
    for (int i = 0; i < num_thr; i++)
    {
        t[i].id = i;
        t[i].queue = &queue;
        rc = pthread_create(&thr[i], NULL, thr_func, &t[i]);

        if (rc)
        {
            fprintf(stderr, "error:pthread_create, rc:%d\n", rc);
            return EXIT_FAILURE;
        }
    }

    pthread_mutex_unlock(&(queue.lock));

    for (int i = 0; i < num_thr; i++)
        pthread_join(thr[i], NULL);

    for (int i = 0; i < MAX_TASKS; i++)
        summ += queue.tasks[i].summ;
    printf("%le\n", summ);

    return 0;
}