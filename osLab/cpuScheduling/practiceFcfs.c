#include<stdio.h>
struct Process
{
    int Process_id;
    int bt;
    int ct;
    int tat;
    int wt;
};

void solve(struct Process process[],int n)
{
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int current_time = 0;

    for(int i = 0;i<n;i++)
    {
        process[i].ct = current_time+process[i].bt;
        process[i].tat = process[i].ct;
        process[i].wt = process[i].tat - process[i].bt;

        total_turnaround_time += process[i].tat;
        total_waiting_time += process[i].wt;

        current_time += process[i].ct;

    }
    printf("\n");

    float avg_waiting_time = (float) total_waiting_time / n;
    float avg_turnaround_time = (float) total_turnaround_time / n;

    printf("\nProcess\t Burst Time\t Completion Time\t Turnaround Time\t Waiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t  %d\t\t %d\t\t\t %d\t\t\t %d\n", process[i].Process_id,
               process[i].bt, process[i].ct,
               process[i].tat, process[i].wt);
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main()
{
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    printf("Enter Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].Process_id = i + 1;
        printf("Process %d:\n", processes[i].Process_id);
        
        printf("Burst Time: ");
        scanf("%d", &processes[i].bt);
    }

    solve(processes, n);

    return 0;
}