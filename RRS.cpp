#include<stdio.h>

struct Process {
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
};

void calculateTimes(struct Process processes[], int n, int quantum) {
    int i, completed = 0, time = 0, sumWaitingTime = 0, sumTurnaroundTime = 0;
    
     
    for (i = 0; i < n; i++)
        processes[i].remainingTime = processes[i].burstTime;
    
    
    while (completed < n) {
        for (i = 0; i < n; i++) {
             
            if (processes[i].remainingTime > 0) {
                 
                int executionTime = (processes[i].remainingTime > quantum) ? quantum : processes[i].remainingTime;
                
                
                processes[i].remainingTime -= executionTime;
                
                
                sumWaitingTime += time - processes[i].waitingTime;
                
                 
                if (processes[i].remainingTime == 0) {
                    completed++;
                    processes[i].turnaroundTime = time + executionTime;
                    sumTurnaroundTime += processes[i].turnaroundTime;
                }
                
                 
                processes[i].waitingTime = time + executionTime;
                
                 
                time += executionTime;
            }
        }
    }
    
     
    float avgWaitingTime = (float) sumWaitingTime / n;
    float avgTurnaroundTime = (float) sumTurnaroundTime / n;
    
    
    printf("Average Waiting Time: %.2f ms\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f ms\n", avgTurnaroundTime);
}

int main() {
     
    int n = 3;
    
     
    int quantum = 4;
    
     
    struct Process processes[n];
    
     
    processes[0].burstTime = 24;
    processes[1].burstTime = 3;
    processes[2].burstTime = 3;
    
     
    calculateTimes(processes, n, quantum);
    
    return 0;
}
