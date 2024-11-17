#include <stdio.h>

#define max 10
void srtf(int n, int AT[], int BT[], int WT[], int CT[], int TAT[]);
void display (int n, int AT[], int oldBT[], int WT[], int CT[], int TAT[]);


int main() 
{
    int n;
    printf("\nEnter num of processes : ");
    scanf("%d", &n);

    int AT[max], BT[max], WT[max], CT[max], TAT[max], oldBT[max];
    for (int i=0; i<n; i++) {
        printf("Enter AT & BT for P%d : ", i+1);
        scanf("%d %d", &AT[i], &BT[i]);  
    }

    srtf (n, AT, BT, WT, CT, TAT);
    
    return 0;
}


void srtf(int n, int AT[], int BT[], int WT[], int CT[], int TAT[]) 
{
    printf("\n\n\tSRTF (SJF - Preemptive)\n");
    printf("\n Gantt chart :  ");
    int currentTime=0;
    int oldBT[max], totalBT=0;
    int prevsj=-1;
    for (int i=0; i<n; i++) {
        totalBT += BT[i];
        oldBT[i]=BT[i];
    }

    int sj, current2;
    while (totalBT != 0) {
        sj = -1;
        
        for (int i=0; i<n; i++) {
            if ( (AT[i] <= currentTime) && (BT[i] < BT[sj] || sj == -1) && (BT[i] != 0) ) {
                sj = i;
            }
        }

        if (sj == -1) {
            currentTime++;
            continue;
        }
    
        if (prevsj!=sj)
            printf("(%d) P%d ", currentTime, sj+1);
        BT[sj]--;
        totalBT--;
        currentTime++;
        prevsj=sj;
        
        if (BT[sj] == 0) {
            CT[sj] = currentTime;
            TAT[sj] = CT[sj] - AT[sj];
            WT[sj] = TAT[sj]-oldBT[sj];
        }
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