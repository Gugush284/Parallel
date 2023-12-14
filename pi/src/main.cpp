#include "main.h"

int main() {
    int radius = 10000000;

    double p;
    double start, end;

    start = clock();
    p = pi(radius);
    end = clock();

    printf("Pi by one thread: %.10f (%.6f s)\n", p, end - start);

    for (int i = 2; i < NUM_TREADS; i++){
        start = clock();
        p = multi_pi(radius, NUM_TREADS);
        end = clock();

        printf("Pi by %d threads: %.10f (%.6f s)\n", i, p, end - start);
    }

    return 0;
}