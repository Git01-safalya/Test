// display waiting queue in sjf

#include <stdio.h>

#define max 10
void sjf(int n, int AT[], int BT[], int WT[], int CT[], int TAT[]);
void display(int n, int AT[], int oldBT[], int WT[], int CT[], int TAT[]);

int main()
{
    int n = 5;
    int AT[max], BT[max], CT[max], WT[max], TAT[max], oldBT[max];

    printf("Enter num of processes : ");
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        printf("Enter AT & BT for P%d : ", i+1);
        scanf("%d %d", &AT[i], &BT[i]);
    }

    sjf(n, AT, BT, WT, CT, TAT);
    
    return 0;   
    
}

void sjf(int n, int AT[], int BT[], int WT[], int CT[], int TAT[])
{
    printf("\n\tSJF - Non Preemptive \n");
    
    int currentTime = 0;
    int sj;
    int BTtotal = 0, oldBT[max];
    
    for (int i=0; i<n; i++) {
        BTtotal += BT[i];
        oldBT[i] = BT[i];
    }        
        
    printf("\nTime | Waiting queue     | Process being executed");

    while (BTtotal != 0 ) {
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
        
        printf("\n %2d  | ", currentTime);
        for (int i=0; i<n; i++) {
            if ((AT[i] <= currentTime) && (BT[i]!=0)) {
                printf("P%d ", i+1);
            }
        }
        printf("\n     |\t\t\t | \t P%d", sj+1);
        CT[sj] = currentTime + BT[sj];
        TAT[sj] = CT[sj] - AT[sj];
        WT[sj] = TAT[sj] - BT[sj];
        currentTime += BT[sj];
        BTtotal -= BT[sj];
        BT[sj]=0;
    }
    display(n, AT, oldBT, WT, CT, TAT);
}

void display(int n, int AT[], int oldBT[], int WT[], int CT[], int TAT[])
{
    float sumWT=0, sumTAT=0;
    for(int i=0; i<n; i++) {
        sumWT += WT[i];
        sumTAT += TAT[i];
    }

    printf("\n\n|  Pid  |  AT  |  BT  ||  WT  |  CT  |  TAT  |\n");
    printf("|_______|______|______||______|______|_______|\n");
    for (int i=0; i<n; i++) {
        printf("|  P%2d  |  %2d  |  %2d  ||  %2d  |  %2d  |  %2d   |\n", i+1, AT[i],oldBT[i],WT[i],CT[i],TAT[i]);
    }

    printf("\nAvg WT  = %.1f\n", sumWT/n);
    printf("Avg TAT = %.1f", sumTAT/n);   
}