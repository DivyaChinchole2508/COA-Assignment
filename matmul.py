import numpy as np
import time

def multiply_int(N, A, B):
    C = np.zeros((N, N), dtype=int)
    for i in range(N):
        for j in range(N):
            for k in range(N):
                C[i][j] += A[i][k] * B[k][j]
    return C

def multiply_double(N, A, B):
    C = np.zeros((N, N), dtype=float)
    for i in range(N):
        for j in range(N):
            for k in range(N):
                C[i][j] += A[i][k] * B[k][j]
    return C

if __name__ == "__main__":
    N = 1024  # Change N to 64, 128, 256, 512, 1024

    # Integer matrix multiplication
    A = np.random.randint(10, size=(N, N), dtype=int)
    B = np.random.randint(10, size=(N, N), dtype=int)

    start_time = time.time()
    C = multiply_int(N, A, B)
    end_time = time.time()
    print(f"Time taken for integer matrix multiplication: {end_time - start_time:.6f} seconds")

    # Double matrix multiplication
    D = np.random.rand(N, N)
    E = np.random.rand(N, N)

    start_time = time.time()
    F = multiply_double(N, D, E)
    end_time = time.time()
    print(f"Time taken for double matrix multiplication: {end_time - start_time:.6f} seconds")
