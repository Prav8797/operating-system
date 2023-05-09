#include <stdio.h>

#define NUM_PARTITIONS 6
#define NUM_PROCESSES 5

int partitions[NUM_PARTITIONS] = {300, 600, 350, 200, 750, 125};
int processes[NUM_PROCESSES] = {115, 500, 358, 200, 375};
int allocation[NUM_PROCESSES];

int main() {
    int i, j;
    for (i = 0; i < NUM_PROCESSES; i++) {
        for (j = 0; j < NUM_PARTITIONS; j++) {
            if (processes[i] <= partitions[j]) {
                allocation[i] = partitions[j];
                partitions[j] -= processes[i];
                break;
            }
        }
    }

    printf("Process \t Process size \t Partition allocated\n");
    for (i = 0; i < NUM_PROCESSES; i++) {
        printf("%d \t\t %d KB \t\t ", i+1, processes[i]);
        if (allocation[i] != 0) {
            printf("%d KB\n", allocation[i]);
        } else {
            printf("Not allocated\n");
        }
    }

    return 0;
}
