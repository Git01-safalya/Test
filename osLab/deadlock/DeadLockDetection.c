#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESS 10
#define MAX_RESOURCE 10

int allocation[MAX_PROCESS][MAX_RESOURCE];
int max_demand[MAX_PROCESS][MAX_RESOURCE];
int available[MAX_RESOURCE];
bool marked[MAX_PROCESS];

int num_processes, num_resources;

void initialize() {
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    printf("Enter the number of resources: ");
    scanf("%d", &num_resources);

    printf("Enter allocation matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter maximum demand matrix:\n");
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            scanf("%d", &max_demand[i][j]);
        }
    }

    printf("Enter available resources:\n");
    for (int j = 0; j < num_resources; j++) {
        scanf("%d", &available[j]);
    }

    for (int i = 0; i < num_processes; i++) {
        marked[i] = false;
    }
}

bool is_safe(int process, int work[]) {
    for (int j = 0; j < num_resources; j++) {
        if (max_demand[process][j] - allocation[process][j] > work[j]) {
            return false;
        }
    }
    return true;
}

bool detect_deadlock() {
    int work[num_resources];
    for (int j = 0; j < num_resources; j++) {
        work[j] = available[j];
    }

    int count = 0;
    while (count < num_processes) {
        bool found = false;
        for (int i = 0; i < num_processes; i++) {
            if (!marked[i] && is_safe(i, work)) {
                marked[i] = true;
                for (int j = 0; j < num_resources; j++) {
                    work[j] += allocation[i][j];
                }
                found = true;
                count++;
            }
        }
        if (!found) {
            return true; // Deadlock detected
        }
    }
    return false; // No deadlock detected
}

int main() {
    initialize();

    if (detect_deadlock()) {
        printf("Deadlock detected!\n");
    } else {
        printf("No deadlock detected.\n");
    }

    return 0;
}
