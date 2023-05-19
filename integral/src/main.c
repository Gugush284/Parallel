#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "main.h"

// объявление функций из func.c
extern double fsin(double x);
extern void* thr_func(void* arg);

// точка входа
int main()
{
    double summ; // значение интеграла
    pthread_t thr[num_thr]; // объявление массива потоков 
    taskQueue queue; // объявление очереди задач
    queue.count = 0; // начальное значение счетчика задач
    thr_struct t[num_thr]; // объяление структуры для передачи в потоки
    int rc; // параметр ошибки

    // Деление отрезка интегрирования на более мелкие, задание переменной шага интегрирования,
    // добавление задачи в очередь задач
    for (int i = 0; i < MAX_TASKS; i++){
        queue.tasks[i].start = start + i * (end - start) / MAX_TASKS;
        queue.tasks[i].end = start + (i+1) * (end - start) / MAX_TASKS;
        queue.tasks[i].eps = eps * (i+1) * (end - start) / MAX_TASKS;
    }

    // Инициализация мьютекса, блокирование потоков до тех пор, пока все не будут готовы
    rc = pthread_mutex_init(&queue.lock, NULL);
    if (rc)
    {
        fprintf(stderr, "error:mutex_init, rc:%d\n", rc);
        return EXIT_FAILURE;
    }
    pthread_mutex_lock(&(queue.lock));

    // Запуск потоков
    for (int i = 0; i < num_thr; i++)
    {
        t[i].id = i; // присвоение номера потока
        t[i].queue = &queue; // присвоение ссылки на очередь задач
        rc = pthread_create(&thr[i], NULL, thr_func, &t[i]); // создание потоков

        // Проверяем, что потоки успешно созданы 
        if (rc)
        {
            fprintf(stderr, "error:pthread_create, rc:%d\n", rc);
            return EXIT_FAILURE;
        }
    }

    printf("Threads\n");

    // Разблокировка потоков для начала их работы
    pthread_mutex_unlock(&(queue.lock));

    // Ожидание завершения выполнения каждого потока
    for (int i = 0; i < num_thr; i++)
        pthread_join(thr[i], NULL);

    // Вычисление суммы значений, полученных в каждой выполненной задаче
    for (int i = 0; i < MAX_TASKS; i++)
        summ += queue.tasks[i].summ;
    printf("integral sin(1/x) from %le to %le = %le\n", start, end, summ);

    // Уничтожение мьютекса
    rc = pthread_mutex_destroy(&queue.lock);
    if (rc)
    {
        fprintf(stderr, "error:mutex_destroy, rc:%d\n", rc);
        return EXIT_FAILURE;
    }

    return 0;
}