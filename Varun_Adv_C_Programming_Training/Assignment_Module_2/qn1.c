#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* sum_primes(void* arg) {
    int N = *(int*)arg, count = 0, num = 2, sum = 0;
    while (count < N) {
        int is_prime = 1;
        for (int i = 2; i * i <= num; i++)
            if (num % i == 0) { is_prime = 0; break; }
        if (is_prime) { sum += num; count++; }
        num++;
    }
    printf("Sum of first %d prime numbers: %d\n", N, sum);
    return NULL;
}

void* print_thread1(void* arg) {
    for (int i = 0; i < 50; i++) {
        printf("Thread 1 is running\n");
        sleep(2);
    }
    return NULL;
}

void* print_thread2(void* arg) {
    for (int i = 0; i < 34; i++) {
        printf("Thread 2 is running\n");
        sleep(3);
    }
    return NULL;
}

int main() {
    pthread_t A, B, C;
    int N;

    printf("Enter N: ");
    scanf("%d", &N);

    pthread_create(&A, NULL, sum_primes, &N);
    pthread_create(&B, NULL, print_thread1, NULL);
    pthread_create(&C, NULL, print_thread2, NULL);

    pthread_join(A, NULL);
    pthread_join(B, NULL);
    pthread_join(C, NULL);

    return 0;
}
