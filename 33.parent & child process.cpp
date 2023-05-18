#include <stdio.h>
#include <unistd.h>
#define fork
#define wait
int isPrime(int num) {
    if (num <= 1)
        return 0;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }

    return 1;
}
void fibonacciSeries(int n) {
    int first = 0, second = 1;

    printf("Fibonacci Series: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", first);
        int next = first + second;
        first = second;
        second = next;
    }

    printf("\n");
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    pid_t pid = fork(0,n);

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        fibonacciSeries(n);
    } else {
        wait(NULL);

        printf("Prime Numbers: ");
        for (int i = 2; i <= n; i++) {
            if (isPrime(i))
                printf("%d ", i);
        }

        printf("\n");
    }

    return 0;
}

