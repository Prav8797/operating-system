#include <stdio.h>
#include <pthread.h>

void *print_even(void *args) {
    int i;
    for (i = 0; i <= 40; i += 2) {
        printf("Even thread: %d\n", i);
    }
    pthread_exit(NULL);
}

void *print_odd(void *args) {
    int i;
    for (i = 1; i <= 40; i += 2) {
        printf("Odd thread: %d\n", i);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t even_thread, odd_thread;
    int result1, result2;
    
    result1 = pthread_create(&even_thread, NULL, print_even, NULL);
    if (result1) {
        printf("Error creating even thread: %d\n", result1);
        return 1;
    }
    
    result2 = pthread_create(&odd_thread, NULL, print_odd, NULL);
    if (result2) {
        printf("Error creating odd thread: %d\n", result2);
        return 1;
    }
    
    pthread_join(even_thread, NULL);
    pthread_join(odd_thread, NULL);
    
    return 0;
}

