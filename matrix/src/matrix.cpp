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

    auto start_time = std::chrono::steady_clock::now();

    for(int u = 0; u < LOOP; u++) {
        for(int i = 0; i < size; i++) 
            for(int j = 0; j < size; j++) {
                matrix[i][j] = 0;

                for(int k = 0; k < size; k++) {
                    matrix[i][j] += (A[i][k] * B[k][j]);
                }
            }
    }

    auto time = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::steady_clock::now() - start_time );

    std::cout << "Time: " << time.count() << std::endl;

    return matrix;
}

double ** matrix_multiplication_multi(double ** A, double ** B, int size, int num_thr){

    double ** matrix = (double **) malloc(sizeof(double *) * size);

    for (int i = 0; i < size; i++)
        matrix[i] = (double *) malloc(sizeof(double) * size);

    auto start_time = std::chrono::steady_clock::now();
    
    for(int u = 0; u < LOOP; u++) {
        #pragma omp parallel for shared(matrix1, matrix2, result) private(i, j, k) num_threads(num_thr) 
        for(int i = 0; i < size; i++)
            for(int j = 0; j < size; j++) {
                matrix[i][j] = 0;

                for(int k = 0; k < size; k++)
                    matrix[i][j] += (A[i][k] * B[k][j]);
            }
    }

    auto time = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::steady_clock::now() - start_time );

    std::cout << "Time: " << time.count() << std::endl;
    
    return matrix;
}