#include <stdio.h>
#include <stdbool.h>

#define MAX_PARTITIONS 10
typedef struct {
    int id;
    int size;
    bool allocated;
} MemoryPartition;
int findWorstFitPartition(MemoryPartition partitions[], int numPartitions, int processSize) {
    int worstFitIndex = -1;
    int worstFitSize = -1;

    for (int i = 0; i < numPartitions; i++) {
        if (!partitions[i].allocated && partitions[i].size >= processSize) {
            if (worstFitIndex == -1 || partitions[i].size > worstFitSize) {
                worstFitIndex = i;
                worstFitSize = partitions[i].size;
            }
        }
    }

    return worstFitIndex;
}
void printMemoryPartitions(MemoryPartition partitions[], int numPartitions) {
    printf("Memory Partitions:\n");
    for (int i = 0; i < numPartitions; i++) {
        printf("Partition %d: Size: %d KB, Allocated: %s\n", partitions[i].id, partitions[i].size,
               partitions[i].allocated ? "Yes" : "No");
    }
    printf("\n");
}

int main() {
    MemoryPartition partitions[MAX_PARTITIONS] = {
        {1, 40, false},
        {2, 10, false},
        {3, 30, false},
        {4, 60, false}
    };

    int numPartitions = 4;

    int processSizes[] = {100, 50, 30, 120, 35};
    int numProcesses = sizeof(processSizes) / sizeof(processSizes[0]);

    printf("Worst-Fit Memory Allocation Algorithm\n\n");

    for (int i = 0; i < numProcesses; i++) {
        int processSize = processSizes[i];

        int worstFitIndex = findWorstFitPartition(partitions, numPartitions, processSize);

        if (worstFitIndex != -1) {
            partitions[worstFitIndex].allocated = true;
            printf("Process %d: Size: %d KB, Allocated to Partition %d\n", i + 1, processSize, partitions[worstFitIndex].id);
        } else {
            printf("Process %d: Size: %d KB, Not Enough Memory\n", i + 1, processSize);
        }

        printMemoryPartitions(partitions, numPartitions);
    }

    return 0;
}

