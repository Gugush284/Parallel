#define MAX_TASKS 10000 // определяет максимальное количество задач (разбиений на отрезки)

const double start = 0.01; // Начальное значение отрезка интегрирования
const double end = 3; // Конечное значение отрезка интегрирования
const int num_thr = 8; // Количество потоков
const double eps = 0.000001; // Переменная шага интегрирования

// Данные одного задания
typedef struct {
    double start; // начало отрезка интегрирования данного задания
    double end; // конец
    double summ; // полученная сумма на отрезке
    double eps; // переменная шага интегрирования
} task;

// Очередь заданий
typedef struct {
    task tasks[MAX_TASKS]; // массив заданий
    int count; // счетчик текущего задания
    pthread_mutex_t lock; // мьютекс
} taskQueue;

// Структура, передаваемая потоку
typedef struct {
    taskQueue *queue; // указатель на очередь
    int id; // id данного потока
} thr_struct;