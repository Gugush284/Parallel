#include <cstdlib>
#include <ctime>
#include <iostream>
#include <omp.h>
#include "debug.h"

double ** matrix_new(int size);
void matrix_print(double ** matrix, int size);
double ** matrix_multiplication_single(double ** A, double ** B, int size, double * time);
double ** matrix_multiplication_multi(double ** A, double ** B, int size, int num_thr, double * time);