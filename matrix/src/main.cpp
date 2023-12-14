#include "main.h"

int main() {
    double start, end;

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

    start = clock();
    double ** C_single = matrix_multiplication_single(A, B, size);
    end = clock();

    printf("\nit's single result: %d s\n", end - start);
    matrix_print(C_single, size);

    double ** C_multi;

    for (int i = 2; i < NUM_TREADS + 1; i++){
        start = clock();
        C_multi = matrix_multiplication_multi(A, B, size, i);
        end = clock();

        printf("%d threads: %d s\n", i, end - start);

        matrix_print(C_multi, size);
        }

    return 0;
}