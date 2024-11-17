#include<stdio.h>
#include<limits.h>
#define max 40

void sort(int req[], int n){
    for(int i = 0;i < n - 1;i++){
        for(int j = i + 1;j < n;j++){
            if(req[i] > req[j]){
                int temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }
}

int abs(int a){
    return (a >= 0) ? a : -a;
}

int findDisk(int req[],int n,int head,int visited[]){
    if(head == req[n - 1]){
        return 0;
    }
    for(int i = 0;i < n;i++){
        if(req[i] >= head && visited[i] == 0){
            return i;
        }
    }
    return -1;
}

void clook(int req[],int n,int head){
    int st = 0;
    int seq[n];
    int idx = 0;
    int visited[max] = {0};
    for(int i = 0;i < n;i++){
        idx = findDisk(req,n,head,visited);
        st += abs(req[idx] - head);
        seq[i] = req[idx];
        head = req[idx];
        visited[idx] = 1;
    }
    for(int i = 0;i < n;i++){
        printf("%d\t",seq[i]);
    }
    printf("\nST: %d",st);
}

int main(){
    int n = 7;
    int req[] = {82,170,43,140,24,16,190}; // 16 24 43 82 140 170 190
    sort(req,n);
    int head = 50;
    clook(req,n,head);
}