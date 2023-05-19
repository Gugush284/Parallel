#include <math.h>
#include <stdio.h>
#include "func.h"

// Вычисляем функцию sin(1/x), дополнив значение в нуле 
double fsin(double x)
{
    if (x == 0){
        return 0;
    }

    return sin(1/x);
}

// Функция для выполнения потоком
void* thr_func(void* arg)
{
    double x, h; // x - аргумент функции, h - шаг
    thread_data *data; // объявление указателя на данные конкретной задачи
    int count; // номер текущего задания
    int counter = 0; // количество заданий, выполненых данным потоком
    thread *t = (thread *) arg; // получение данных для потока
    queue *q = t->q; // получение указателя на очередь задач
    
    // Рабочий цикл
    while(1){
        // Блокируем мьютекс
        pthread_mutex_lock(&(q->lock)); // Ожидаем либо запуска всех процессов, либо получения номера задачи другим процессом
        
        // Проверяем, что задачи остались
        if (q->count >= AMOUNT_TASKS) { 
            // Если задач нет, то разблокируем мьютекс и выходим из цикла
            pthread_mutex_unlock(&(q->lock)); 
            break;
        }
        
        count = q->count; // Получаем номер текущей задачи
        (q->count)++; // Увеличиваем счетчик решенных задач
        counter++; // Увеличиваем счетчик решенных потоком задач
        pthread_mutex_unlock(&(q->lock)); // Отпускаем мьютекс

        data = q->tasks + count; // Получаем указатель на данные текущего задания
        
        // Вычисляем шаг интегрирования
        h = sqrt(data->eps * 4 * pow(data->start, 3) / 10 / (data->end - data->start));
        x = data->start; // задаем начало отрезка текущего задания
        
        // Интегрируем текущей отрезок
        while(x < data->end - h)
        {
            data->summ += (fsin(x) + fsin(x+h)) * h/2;
            x += h;
        }
        data->summ += (fsin(x) + fsin(data->end))*(data->end-x)/2;
    }

    // Выводим количество решенных заданий
    printf("id = %d: counter = %d\n", t->id, counter);

    return NULL;
}
