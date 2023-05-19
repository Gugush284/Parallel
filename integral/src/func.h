#include <pthread.h>

#define AMOUNT_TASKS 10000 // количество заданий

// Данные одного задания
typedef struct {
    double start; // начало отрезка интегрирования данного задания
    double end; // конец
    double summ; // полученная сумма на отрезке
    double eps; // переменная шага интегрирования
} thread_data;

// Очередь заданий
typedef struct {
    thread_data tasks[AMOUNT_TASKS]; // массив заданий
    int count; // счетчик текущего задания
    pthread_mutex_t lock; // мьютекс
} queue;

// Структура, передаваемая потоку
typedef struct {
    queue *q; // указатель на очередь
    int id; // id данного потока
} thread;
