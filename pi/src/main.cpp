#include "main.h"

int main() {
    int radius = 10000;

    double p;
    double time = 0;

    p = pi(radius, & time);

    printf("Pi by one thread: %.10f (%.6f s)\n", p, time);

    time = 0;
        
    p = multi_pi(radius, NUM_TREADS, & time);

    printf("Pi by %d threads: %.10f (%.6f s)\n", NUM_TREADS, p, time);
   

    return 0;
}