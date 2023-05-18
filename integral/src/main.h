const double start = 0.01;
const double end = 5;
const int num_thr = 4;
const double eps = 0.1;

typedef struct {
    int tid;
    double start;
    double end;
    double summ;
    double eps;
} thread_data_t;