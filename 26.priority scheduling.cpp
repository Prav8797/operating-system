#include<stdio.h> 

void findWaitingTime(int processes[], int n, int bt[], int wt[], int priority[]) 
{ 
    wt[0] = 0; 
    for (int i = 1; i < n ; i++ ) 
        wt[i] = bt[i-1] + wt[i-1] ; 
  
} 

void findTurnAroundTime( int processes[], int n, int bt[], int wt[], int tat[]) 
{ 
    for (int i = 0; i < n ; i++) 
        tat[i] = bt[i] + wt[i]; 
} 

void findAvgTime( int processes[], int n, int bt[], int priority[]) 
{ 
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
    findWaitingTime(processes, n, bt, wt, priority); 
    findTurnAroundTime(processes, n, bt, wt, tat); 
    printf("Processes  Burst time  Priority  Waiting time  Turn around time\n"); 
    for (int i=0; i<n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        printf("   P%d        %d         %d         %d              %d\n", i+1, bt[i], priority[i], wt[i], tat[i]); 
    } 
  
    printf("\nAverage waiting time = %f", (float)total_wt / (float)n); 
    printf("\nAverage turn around time = %f\n", (float)total_tat / (float)n); 
} 

int main() 
{ 
    int processes[] = { 1, 2, 3}; 
    int n = sizeof processes / sizeof processes[0]; 
    int burst_time[] = {30, 5, 12}; 
    int priority[] = {2, 1, 3}; 
  
    findAvgTime(processes, n, burst_time, priority); 
    return 0; 
} 

