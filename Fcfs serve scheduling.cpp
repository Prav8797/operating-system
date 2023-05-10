#include <stdio.h>

int main() {
    int n = 3;  
    int arrival_time[] = {0, 0, 0};  
    int burst_time[] = {2, 4, 8};  

    int completion_time[n];  
    int turnaround_time[n];  
    int waiting_time[n];  
     
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < arrival_time[i]) {
            current_time = arrival_time[i];
        }
        completion_time[i] = current_time + burst_time[i];
        current_time = completion_time[i];
    }

     
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
    }

     
    float avg_turnaround_time = 0;
    float avg_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        avg_turnaround_time += turnaround_time[i];
        avg_waiting_time += waiting_time[i];
    }
    avg_turnaround_time /= n;
    avg_waiting_time /= n;

    printf("Average turnaround time: %f\n", avg_turnaround_time);
    printf("Average waiting time: %f\n", avg_waiting_time);

    return 0;
}
