#include "main.h"

int main() {
    int size = 6;

    double ** A = matrix_new(size);

    double ** B = matrix_new(size);

    printf("it's A\n");
    matrix_print(A, size);

    printf("\nit's B\n");
    matrix_print(B, size);

    double ** C_single = matrix_multiplication_single(A, B, size);

    printf("\nit's single result: \n");
    matrix_print(C_single, size);

    double ** C_multi = matrix_multiplication_multi(A, B, size, NUM_TREADS);

    printf("%d threads:\n", NUM_TREADS);

    matrix_print(C_multi, size);

    return 0;
}