#define MAX_TASKS 10000

const double start = 0.01;
const double end = 3;
const int num_thr = 8;
const double eps = 0.0001;

typedef struct {
    double start;
    double end;
    double summ;
    double eps;
} task;

typedef struct {
    task tasks[MAX_TASKS];
    int count;
    pthread_mutex_t lock;
} taskQueue;

typedef struct {
    taskQueue *queue;
    int id;
} thr_struct;