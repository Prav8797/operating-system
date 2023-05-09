#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
};

void SRPT(struct Process processes[], int n) {
    int time = 0;
    int completed = 0;
    int i, shortest_index;
    float total_waiting_time = 0;
    float total_turnaround_time = 0;
    struct Process current;

    while (completed < n) {
        shortest_index = -1;

        for (i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && processes[i].remaining_time > 0) {
                if (shortest_index == -1 || processes[i].remaining_time < processes[shortest_index].remaining_time) {
                    shortest_index = i;
                }
            }
        }

        if (shortest_index == -1) {
            time++;
            continue;
        }

        current = processes[shortest_index];
        current.remaining_time--;

        if (current.remaining_time == 0) {
            completed++;
            total_waiting_time += time - current.arrival_time - current.burst_time + 1;
            total_turnaround_time += time - current.arrival_time + 1;
        }

        time++;
    }

    printf("Average Waiting Time: %f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %f\n", total_turnaround_time / n);
}

int main() {
    int n = 4;
    struct Process processes[n];
    processes[0].pid = 1;
    processes[0].arrival_time = 0;
    processes[0].burst_time = 5;
    processes[0].remaining_time = 5;

    processes[1].pid = 2;
    processes[1].arrival_time = 1;
    processes[1].burst_time = 3;
    processes[1].remaining_time = 3;

    processes[2].pid = 3;
    processes[2].arrival_time = 2;
    processes[2].burst_time = 3;
    processes[2].remaining_time = 3;

    processes[3].pid = 4;
    processes[3].arrival_time = 4;
    processes[3].burst_time = 1;
    processes[3].remaining_time = 1;

    SRPT(processes, n);

    return 0;
}
