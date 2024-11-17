#include<stdio.h>
#include<limits.h>

int abs(int a){
    return (a >= 0) ? a : -a;
}

int findsst(int inputseq[], int n, int visited[], int head){
    int min = INT_MAX, minIdx = -1;
    for(int i=0; i<n; i++){
        if(visited[i] == 0 && abs(inputseq[i] - head) < min){
            min = abs(inputseq[i] - head);
            minIdx = i;
        }
    }
    return minIdx;
}

void sstf(int inputseq[],int n,int head){
    int idx = 0;
    int diskseq[n];
    int ST = 0;
    int visited[n];
    for(int i=0; i<n; i++){
        visited[i] = 0;
    }

    for(int i=0; i<n; i++){
        int sst = findsst(inputseq, n, visited, head);
        diskseq[idx++] = inputseq[sst];
        ST += abs(head - inputseq[sst]);
        head = inputseq[sst];
        visited[sst] = 1;
    }

    for(int i=0; i<n; i++){
        printf("%d\t",diskseq[i]);
    }
    printf("\nseek time = %d",ST);
}

int main(){
    int n = 7;
    int inputseq[] = {82,170,43,140,24,16,190};
    int head = 50;
    sstf(inputseq,n,head);
}