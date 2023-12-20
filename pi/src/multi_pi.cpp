#include <math.h>
#include <omp.h>
#include <ctime>
#include <iostream>
#include <chrono>
#include <math.h>
#include "multi_pi.h" 


double multi_pi(int n, int num_thr)
{

    double pi = 0;

    auto start_time = std::chrono::steady_clock::now();

    for(int j = 0 ; j < 1000 ; ++j){
        pi = 0;

        #pragma omp parallel for reduction(+:pi) num_threads(num_thr)
        for (int i = 0; i < n; i++){
            pi = pi + 4.0 * pow(-1, i) / (2.0 * i + 1.0); // Грегори-Лейбница
        }
    }

    auto time = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::steady_clock::now() - start_time );

    std::cout << "Time: " << time.count() << std::endl;

    return pi;
}