#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void FCFS(int n, int reqSeq[], int iniHead);

int main() {
    printf("\n\t FCFS disk scheduling\n");
    int n, reqSeq[MAX], iniHead;
    printf("\nEnter num of requests  : ");
    scanf("%d", &n);

    printf("Enter request sequence : ");
    for(int i=0; i<n; i++) {
        scanf("%d", &reqSeq[i]);
    }

    printf("Enter initial head pos : ");
    scanf("%d", &iniHead);
    
    FCFS(n, reqSeq, iniHead);
    return 0;
}
int abso(int a) {
    if(a<0) return -a;
    else return a;
}

void FCFS(int n, int reqSeq[], int iniHead) {
    printf("\n\nSeek sequence   : ");
    float totalSeek = 0;
    int prev = iniHead;
    for(int i=0; i<n; i++){
        totalSeek += abso(reqSeq[i]-prev);
        printf("%d ",reqSeq[i]);
        prev = reqSeq[i];
    }
    printf("\nTotal Seek dist : %.0f\n",totalSeek);
    printf("Avg Seek dist   : %.2f\n\n",totalSeek/n);
}