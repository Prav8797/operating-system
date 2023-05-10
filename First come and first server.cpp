 #include<stdio.h>

void findWaitingTime(int n, int bt[], int wt[]) {
    wt[0] = 0;
  
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}
  
void findTurnaroundTime(int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}
  
void findAverageTime(int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
  
    findWaitingTime(n, bt, wt);
  
    findTurnaroundTime(n, bt, wt, tat);
  
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
  
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
  
    float average_wt = (float)total_wt / n;
    float average_tat = (float)total_tat / n;
  
    printf("\nAverage Waiting Time: %.2f", average_wt);
    printf("\nAverage Turnaround Time: %.2f", average_tat);
}

int main() {
    int n = 3;  
    int burst_time[] = {10, 15, 25};
  
    findAverageTime(n, burst_time);
  
    return 0;
}

