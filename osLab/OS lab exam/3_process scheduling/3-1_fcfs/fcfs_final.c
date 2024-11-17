#include <stdio.h>

#define max 10

void display (int n, int AT[], int BT[], int WT[], int CT[], int TAT[]);
void fcfs(int n, int at[], int bt[]);

int main () {
    int n;
    int AT[max], BT[max];
    printf("\nEnter number of processes : "); 
    scanf("%d", &n);

    for (int i=0; i<n; i++ ) {
        printf("Enter the AT & BT of P%d : ", i+1);
        scanf("%d %d", &AT[i], &BT[i]);
    }
    fcfs(n, AT, BT);
    return 0;
}

void fcfs(int n, int AT[], int BT[]) {
    int currentTime = 0, job, num=n;
    int TAT[max]={0}, WT[max]={0}, CT[max]={0}, oldBT[max];
    printf("\n\n\t FCFS process scheduling\n\n");
    printf("Gantt chart : ");
    for(int i=0; i<n; i++) {
        oldBT[i] = BT[i];
    }
    while (num != 0) {
        job = -1;

        for (int i=0; i<n; i++) {       //search for job with least AT
            if( (AT[i] <= currentTime) && (BT[i] != 0) && (AT[i]<AT[job] || job == -1)) {
                job = i;
            } 
        }

        if(job == -1) {     //if no such job then CPU will be idle for 1 time unit
            currentTime++;
            continue;
        }

        printf("(%d) P%d ", currentTime, job+1);
        
            currentTime += BT[job];
            CT[job] = currentTime;
            TAT[job] = CT[job] - AT[job];
            WT[job] = TAT[job] - BT[job];
            BT[job] = 0;
            num--;
    }
    printf("(%d)\n", currentTime);
    display (n, AT, oldBT, WT, CT, TAT);
}



void display (int n, int AT[], int BT[], int WT[], int CT[], int TAT[])
{
    printf("\n --------------------------------------------\n");
    printf("|  Pid  |  AT  |  BT  ||  WT  |  CT  |  TAT  |\n");
    printf("|_______|______|______||______|______|_______|\n");

    float sumWT=0, sumTAT=0;
    for (int i=0; i<n; i++) {
        printf("|  P%d   |  %2d  |  %2d  ||  %2d  |  %2d  |  %2d   |\n", i+1, AT[i], BT[i], WT[i], CT[i], TAT[i]);
        sumWT += WT[i];
        sumTAT += TAT[i];
    }
    printf(" --------------------------------------------\n");
    printf("\nAvg WT : %.1f\n", sumWT/n);
    printf("Avg TAT : %.1f\n", sumTAT/n);
}