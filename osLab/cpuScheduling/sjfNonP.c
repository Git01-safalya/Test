#include <stdio.h>

#define MAX_PROCESS 10

typedef struct {
    int burst_time;
    int process_id;
} Process;


void swap(Process *xp, Process *yp) {
    Process temp = *xp;
    *xp = *yp;
    *yp = temp;
} 


// Function to perform selection sort based on burst time
void sort(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}


int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_PROCESS) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    Process processes[MAX_PROCESS];
    printf("Enter burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        processes[i].process_id = i + 1;
        scanf("%d", &processes[i].burst_time);
    }

    // Sort processes based on burst time
    sort(processes, n);

    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    int total_waiting_time = 0, total_turnaround_time = 0, waiting_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time;
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].burst_time, waiting_time, waiting_time + processes[i].burst_time);
        waiting_time += processes[i].burst_time;
        total_turnaround_time += waiting_time;
    }

    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);

    return 0;
}
