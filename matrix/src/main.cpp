#include "main.h"

int main() {
    double time;

    DEBUG
    int size = 2;

    DEBUG
    double ** A = matrix_new(size);

    DEBUG
    double ** B = matrix_new(size);

    printf("it's A\n");
    matrix_print(A, size);

    printf("\nit's B\n");
    matrix_print(B, size);

    double ** C_single = matrix_multiplication_single(A, B, size, & time);

    printf("\nit's single result: %d s\n", time);
    matrix_print(C_single, size);

    double ** C_multi = matrix_multiplication_multi(A, B, size, NUM_TREADS, & time);

    printf("%d threads: %d s\n", NUM_TREADS, time);

    matrix_print(C_multi, size);

    return 0;
}