#include <stdio.h>

#define MAX_PARTITIONS 5

int partitions[MAX_PARTITIONS] = {40, 10, 30, 60};
int num_processes = 5; 
int processes[] = {100, 50, 30, 120, 35};

int main() {
    int i, j, allocated;

    for (i = 0; i < num_processes; i++) {
        allocated = 0;
        for (j = 0; j < MAX_PARTITIONS; j++) {
            if (processes[i] <= partitions[j]) {
                printf("Process %d of size %d KB allocated to partition %d of size %d KB\n", i+1, processes[i], j+1, partitions[j]);
                partitions[j] -= processes[i];
                allocated = 1;
                break;
            }
        }
        if (!allocated) {
            printf("Process %d of size %d KB cannot be allocated\n", i+1, processes[i]);
        }
    }

    return 0;
}

