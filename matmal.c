#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to multiply two matrices
void multiply_int(int N, int** A, int** B, int** C) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiply_double(int N, double** A, double** B, double** C) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0.0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int N = 512; // Change N to 64, 128, 256, 512, 1024

    // Allocate memory for integer matrices
    int** A = (int**)malloc(N * sizeof(int*));
    int** B = (int**)malloc(N * sizeof(int*));
    int** C = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        A[i] = (int*)malloc(N * sizeof(int));
        B[i] = (int*)malloc(N * sizeof(int));
        C[i] = (int*)malloc(N * sizeof(int));
    }

    // Initialize matrices A and B with random values
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    // Measure execution time for integer multiplication
    clock_t start = clock();
    multiply_int(N, A, B, C);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for integer matrix multiplication: %f seconds\n", time_taken);

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    // Repeat for double matrices
    double** D = (double**)malloc(N * sizeof(double*));
    double** E = (double**)malloc(N * sizeof(double*));
    double** F = (double**)malloc(N * sizeof(double*));
    for (int i = 0; i < N; i++) {
        D[i] = (double*)malloc(N * sizeof(double));
        E[i] = (double*)malloc(N * sizeof(double));
        F[i] = (double*)malloc(N * sizeof(double));
    }

    // Initialize matrices D and E with random values
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            D[i][j] = (double)(rand() % 10);
            E[i][j] = (double)(rand() % 10);
        }
    }

    // Measure execution time for double multiplication
    start = clock();
    multiply_double(N, D, E, F);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for double matrix multiplication: %f seconds\n", time_taken);

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(D[i]);
        free(E[i]);
        free(F[i]);
    }
    free(D);
    free(E);
    free(F);

    return 0;
}
