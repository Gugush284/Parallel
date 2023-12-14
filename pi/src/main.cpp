#include "main.h"

int main() {
    int radius = 100000;

    double p;
    double start, end;

    start = clock();
    p = pi(radius);
    end = clock();

    printf("Pi by one thread: %.10f (%.6f s)\n", p, end - start);

    start = clock();
    p = multi_pi(radius);
    end = clock();

    printf("Pi by multi threads: %.10f (%.6f s)\n", p, end - start);

    return 0;
}