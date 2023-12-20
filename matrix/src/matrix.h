#include <cstdlib>
#include <iostream>
#include <chrono>

#define LOOP 10000000

double ** matrix_new(int size);
void matrix_print(double ** matrix, int size);
double ** matrix_multiplication_single(double ** A, double ** B, int size);
double ** matrix_multiplication_multi(double ** A, double ** B, int size, int num_thr);