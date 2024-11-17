#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX 20

void SSTF(int n, int reqSeq[], int iniHead);

int main() {
    printf("\n\t SSTF disk scheduling\n");
    int n, reqSeq[MAX], iniHead;
    printf("\nEnter num of requests  : ");
    scanf("%d", &n);

    printf("Enter request sequence : ");
    for(int i=0; i<n; i++) {
        scanf("%d", &reqSeq[i]);
    }

    printf("Enter initial head pos : ");
    scanf("%d", &iniHead);
    
    SSTF(n, reqSeq, iniHead);
    return 0;
}

int abso(int a) {
    if(a<0) return -a;
    else return a;
}

void SSTF(int n, int reqSeq[], int iniHead) {
    printf("\n\nSeek sequence   : ");
    float totalSeek = 0;
    int prev = iniHead;
    bool visited[MAX];
    for(int i=0;i<n;i++) {
        visited[i] = false;
    }

    for(int i=0; i<n; i++) {
        int next = -1;
        int diff = INT_MAX;
        for(int j=0; j<n; j++) {
            if(visited[j]==false && abso(reqSeq[j]-prev)<diff){
                diff = abso(reqSeq[j]-prev);
                next =j;
            }
        }   
        visited[next]=true;
        totalSeek += abso(reqSeq[next]-prev);
        printf("%d ",reqSeq[next]);
        prev = reqSeq[next];
    }
    printf("\nTotal Seek dist : %.0f\n",totalSeek);
    printf("Avg Seek dist   : %.2f\n\n",totalSeek/n);
}