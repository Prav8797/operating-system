#include<stdio.h>
#include<stdbool.h>

#define NUM_PROCESSES 4
#define NUM_RESOURCES 3

int main() {
     
    int claim[NUM_PROCESSES][NUM_RESOURCES] = {
        {3, 2, 2},
        {6, 1, 3},
        {3, 1, 4},
        {4, 2, 2}
    };
    int allocation[NUM_PROCESSES][NUM_RESOURCES] = {
        {1, 0, 0},
        {6, 1, 2},
        {2, 1, 1},
        {0, 0, 2}
    };
    int available[NUM_RESOURCES] = {9, 3, 6};
    
    
    bool finished[NUM_PROCESSES] = {false};
    int safe_sequence[NUM_PROCESSES];
    int num_finished = 0;
    
     
    while (num_finished < NUM_PROCESSES) {
        bool found_process = false;
        for (int i = 0; i < NUM_PROCESSES; i++) {
            if (!finished[i]) {
                bool can_be_allocated = true;
                for (int j = 0; j < NUM_RESOURCES; j++) {
                    if (claim[i][j] - allocation[i][j] > available[j]) {
                        can_be_allocated = false;
                        break;
                    }
                }
                if (can_be_allocated) {
                     
                    for (int j = 0; j < NUM_RESOURCES; j++) {
                        available[j] += allocation[i][j];
                    }
                    finished[i] = true;
                    safe_sequence[num_finished] = i;
                    num_finished++;
                    found_process = true;
                    break;
                }
            }
        }
         
        if (!found_process) {
            printf("System is in unsafe state.\n");
            return 0;
        }
    }
    
    printf("System is in safe state. Safe sequence: ");
    for (int i = 0; i < NUM_PROCESSES; i++) {
        printf("%d ", safe_sequence[i]);
    }
    printf("\n");
    return 0;
}
