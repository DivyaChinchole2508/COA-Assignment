#include <stdio.h>
#include <string.h>
#include <time.h>

long long fibonacci_recursive(int n) {
    if (n <= 1)
        return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

void run_fibonacci_recursive() {
    for (int i = 0; i < 50; ++i) {
        printf("%lld ", fibonacci_recursive(i));
    }
    printf("\n");
}


long long fibonacci_loop(int n) {
    if (n <= 1)
        return n;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

void run_fibonacci_loop() {
    for (int i = 0; i < 50; ++i) {
        printf("%lld ", fibonacci_loop(i));
    }
    printf("\n");
}


long long fibonacci_recursive_memo(int n, long long memo[]) {
    if (memo[n] != -1)
        return memo[n];
    if (n <= 1)
        return n;
    return memo[n] = fibonacci_recursive_memo(n - 1, memo) + fibonacci_recursive_memo(n - 2, memo);
}

void run_fibonacci_recursive_memo() {
    long long memo[50];
    memset(memo, -1, sizeof(memo));  // Initialize memo array with -1

    for (int i = 0; i < 50; ++i) {
        printf("%lld ", fibonacci_recursive_memo(i, memo));
    }
    printf("\n");
}

long long fibonacci_loop_memo(int n, long long memo[]) {
    memo[0] = 0;
    if (n > 0) {
        memo[1] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[n];
}

void run_fibonacci_loop_memo() {
    long long memo[50];
    memset(memo, -1, sizeof(memo));  // Initialize memo array with -1

    for (int i = 0; i < 50; ++i) {
        printf("%lld ", fibonacci_loop_memo(i, memo));
    }
    printf("\n");
}


// Function prototypes
void run_fibonacci_recursive();
void run_fibonacci_loop();
void run_fibonacci_recursive_memo();
void run_fibonacci_loop_memo();

double measure_time(void (*func)()) {
    clock_t start, end;
    start = clock();
    func();
    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    return time_taken;
}

int main() {
    printf("Running recursive Fibonacci...\n");
    double time_recursive = measure_time(run_fibonacci_recursive);
    printf("Time taken by recursive method: %f seconds\n\n", time_recursive);

    printf("Running loop Fibonacci...\n");
    double time_loop = measure_time(run_fibonacci_loop);
    printf("Time taken by loop method: %f seconds\n\n", time_loop);

    printf("Running recursive Fibonacci with memoization...\n");
    double time_recursive_memo = measure_time(run_fibonacci_recursive_memo);
    printf("Time taken by recursive with memoization method: %f seconds\n\n", time_recursive_memo);

    printf("Running loop Fibonacci with memoization...\n");
    double time_loop_memo = measure_time(run_fibonacci_loop_memo);
    printf("Time taken by loop with memoization method: %f seconds\n\n", time_loop_memo);

    // Calculating and printing speedup
    printf("Speedup of loop over recursive: %f\n", time_recursive / time_loop);
    printf("Speedup of recursive with memoization over recursive: %f\n", time_recursive / time_recursive_memo);
    printf("Speedup of loop with memoization over recursive: %f\n", time_recursive / time_loop_memo);

    return 0;
}


