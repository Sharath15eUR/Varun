#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

// Global variable to store N
int N;

// SIGINT handler
void sigint_handler(int sig) {
    printf("\nSIGINT received. Termination prevented. Let threads finish...\n");
}

// Utility function to calculate time difference
double get_time_diff(clock_t start, clock_t end) {
    return (double)(end - start) / CLOCKS_PER_SEC;
}

// === Thread A: Sum of first N prime numbers ===
void* threadA_func(void* arg) {
    clock_t start = clock();
    printf("[Thread A] Started\n");

    int count = 0, num = 2, sum = 0;
    while (count < N) {
        int is_prime = 1;
        for (int i = 2; i * i <= num; i++)
            if (num % i == 0) { is_prime = 0; break; }
        if (is_prime) { sum += num; count++; }
        num++;
    }

    printf("[Thread A] Sum of first %d prime numbers = %d\n", N, sum);
    clock_t end = clock();
    printf("[Thread A] Completed in %.2f seconds\n", get_time_diff(start, end));
    return NULL;
}

// === Thread B: Print every 2 seconds ===
void* threadB_func(void* arg) {
    clock_t start = clock();
    printf("[Thread B] Started\n");

    for (int i = 0; i < 50; i++) {
        printf("Thread 1 is running\n");
        sleep(2);
    }

    clock_t end = clock();
    printf("[Thread B] Completed in %.2f seconds\n", get_time_diff(start, end));
    return NULL;
}

// === Thread C: Print every 3 seconds ===
void* threadC_func(void* arg) {
    clock_t start = clock();
    printf("[Thread C] Started\n");

    for (int i = 0; i < 34; i++) {
        printf("Thread 2 is running\n");
        sleep(3);
    }

    clock_t end = clock();
    printf("[Thread C] Completed in %.2f seconds\n", get_time_diff(start, end));
    return NULL;
}

// === Main Function ===
int main() {
    // Register SIGINT handler
    signal(SIGINT, sigint_handler);

    pthread_t threadA, threadB, threadC;

    printf("Enter N: ");
    scanf("%d", &N);

    printf("\n[Main] Creating Threads...\n");

    pthread_create(&threadA, NULL, threadA_func, NULL);
    pthread_create(&threadB, NULL, threadB_func, NULL);
    pthread_create(&threadC, NULL, threadC_func, NULL);

    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    pthread_join(threadC, NULL);

    printf("\n[Main] All threads finished.\n");
    return 0;
}
