#include "matrix.h"

double ** matrix_new(int size){

    double ** matrix = (double **) malloc(sizeof(double *) * size);

    for (int i = 0; i < size; i++){
        matrix[i] = (double *) malloc(sizeof(double) * size);

        for (int j = 0; j < size; j++){
            matrix[i][j] = std::rand() % 50000;
            matrix[i][j] /= 1000;
        }
    }

    return matrix;
}

void matrix_print(double ** matrix, int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            printf("%.3f ", matrix[i][j]);
        }
        printf("\n");
    }
}

double ** matrix_multiplication_single(double ** A, double ** B, int size){
    double ** matrix = (double **) malloc(sizeof(double *) * size);

    for (int i = 0; i < size; i++)
        matrix[i] = (double *) malloc(sizeof(double) * size);

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            matrix[i][j] = 0;

            for(int k = 0; k < size; k++) {
                matrix[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }

    return matrix;
}

double ** matrix_multiplication_multi(double ** A, double ** B, int size, int num_thr){
    double ** matrix = (double **) malloc(sizeof(double *) * size);

    for (int i = 0; i < size; i++)
        matrix[i] = (double *) malloc(sizeof(double) * size);

    #pragma omp parallel num_threads(num_thr)
    #pragma omp parallel for shared(matrix1, matrix2, result) private(i, j, k)
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            matrix[i][j] = 0;

            for(int k = 0; k < size; k++) {
                matrix[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }
    
    return matrix;
}