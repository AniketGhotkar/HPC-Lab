#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define NUM_POINTS 10000000  // Number of random points

int main() {
    int i, count = 0;
    double x, y;
    double pi;
    double start_time, end_time;

    // Timing the parallel computation
    start_time = omp_get_wtime();

    #pragma omp parallel private(x, y) shared(count)
    {
        unsigned int seed = omp_get_thread_num();  // Seed for random number generator

        #pragma omp for reduction(+:count)
        for (i = 0; i < NUM_POINTS; i++) {
            x = (double) rand_r(&seed) / RAND_MAX;
            y = (double) rand_r(&seed) / RAND_MAX;

            if (x * x + y * y <= 1.0) {
                count++;
            }
        }
    }

    pi = 4.0 * count / NUM_POINTS;
    end_time = omp_get_wtime();

    printf("Estimated value of Pi = %f\n", pi);
    printf("Calculation of Pi completed in %f seconds\n", end_time - start_time);

    return 0;
}

