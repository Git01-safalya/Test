#include <stdio.h>

#define max 10
void sjf(int n, int AT[], int BT[]);
void display(int n, int AT[], int BT[], int WT[], int CT[], int TAT[]);

int main()
{
    int n;
    int AT[max], BT[max];

    printf("\nEnter num of processes : ");
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        printf("Enter AT & BT for P%d : ", i+1);
        scanf("%d %d", &AT[i], &BT[i]);
    }
    sjf(n, AT, BT);
    return 0;
}

void sjf(int n, int AT[], int BT[])
{
    int  CT[max], WT[max], TAT[max];
    printf("\n\n\t SJF process scheduling \n\n");
    printf(" Gantt chart : ");
    int currentTime = 0;
    int sj;
    int num=n, oldBT[max];
    
    for (int i=0; i<n; i++) {
        oldBT[i] = BT[i];
    }        
        
    while (num != 0) {
        sj = -1;
        for (int i=0; i<n; i++) {
            if ( (AT[i]<=currentTime) && (BT[i] < BT[sj] || sj == -1) && (BT[i]!=0) ) {
                sj = i;
            }
        }
        if (sj==-1) {
            currentTime++;
            continue;
        }
        printf("(%d) P%d ", currentTime, sj+ 1);
        
        currentTime+=BT[sj];
        CT[sj] = currentTime;
        TAT[sj] = CT[sj] - AT[sj];
        WT[sj] = TAT[sj] - BT[sj];
        num--;
        BT[sj]=0;
    }
    printf("(%d)\n", currentTime);
    display(n, AT, oldBT, WT, CT, TAT);
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