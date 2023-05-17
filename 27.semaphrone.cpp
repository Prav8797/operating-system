#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_INSTANCES 4
#define NUM_PROCESSES 4
#define sleep

sem_t semaphore;

void *process(void *thread_num) {
    int num = *((int*) thread_num);
    sem_wait(&semaphore);
    printf("Process P%d acquired the semaphore.\n", num);
    sleep(2);
    sem_post(&semaphore);
    printf("Process P%d released the semaphore.\n", num);

    return NULL;
}

int main() {
    pthread_t threads[NUM_PROCESSES];
    int thread_nums[NUM_PROCESSES] = {1, 2, 3, 4};
    int i;
    sem_init(&semaphore, 0, NUM_INSTANCES);
    for (i = 0; i < NUM_PROCESSES; i++) {
        pthread_create(&threads[i], NULL, process, (void *) &thread_nums[i]);
    }
    for (i = 0; i < NUM_PROCESSES; i++) {
        pthread_join(threads[i], NULL);
    }
    int thread_num = 5;
    pthread_t thread;
    pthread_create(&thread, NULL, process, (void *) &thread_num);
    printf("Process P%d is trying to acquire the semaphore.\n", thread_num);
    sem_wait(&semaphore);
    printf("Process P%d acquired the semaphore.\n", thread_num);
    sleep(2);
    sem_post(&semaphore);
    printf("Process P%d released the semaphore.\n", thread_num);
    sem_destroy(&semaphore);

    return 0;
}

