#include "main.h"

int main() {
    int radius = 10000;

    double p_single, p_multi;

    p_single = pi(radius);

    printf("Pi by one thread: %.10f\n", p_single);

    p_multi = multi_pi(radius, NUM_TREADS);

    printf("Pi by %d threads: %.10f\n", NUM_TREADS, p_multi);

    printf("%.15f\n", p_multi - p_single);
   
    return 0;
}