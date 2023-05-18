#include <pthread.h>

#define AMOUNT_TASKS 10000

typedef struct {
    double start;
    double end;
    double summ;
    double eps;
} thread_data;

typedef struct {
    thread_data tasks[AMOUNT_TASKS];
    int count;
    pthread_mutex_t lock;
} queue;

typedef struct {
    queue *q;
    int id;
} thread;