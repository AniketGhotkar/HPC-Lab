#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define VECTOR_LENGTH 1000000  
#define ADDITIVE_CONSTANT 5.0            

int main() {
    float *input_vector, *output_vector;
    int index;
    double start_time, end_time;

    input_vector = (float*) malloc(VECTOR_LENGTH * sizeof(float));
    output_vector = (float*) malloc(VECTOR_LENGTH * sizeof(float));

    for (index = 0; index < VECTOR_LENGTH; index++) {
        input_vector[index] = (float) index;
    }

    start_time = omp_get_wtime();

    #pragma omp parallel for
    for (index = 0; index < VECTOR_LENGTH; index++) {
        output_vector[index] = input_vector[index] + ADDITIVE_CONSTANT;
    }

    end_time = omp_get_wtime();

    printf("Vector Scalar Addition completed in %f seconds\n", end_time - start_time);

    free(input_vector);
    free(output_vector);

    return 0;
}

