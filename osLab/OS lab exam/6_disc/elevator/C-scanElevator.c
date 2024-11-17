// 16 24 43 82 140 170 190
#include<stdio.h>
#include<stdlib.h>

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

int finddisk(int req[],int n,int head,int visited[]){
    if(head == req[n - 1]){
        return 0;
    }
    for(int i = 0;i < n;i++){
        if(visited[i] == 0 && req[i] >= head){
            return i;
        }
    }
    return -1;
}

void cscan(int req[],int m,int head){
    int seq[m],visited[m],idx,st = 0;
    for(int i = 0;i < m;i++){
        visited[i] = 0;
    }
    sort(req,m);
    for(int i = 0;i < m;i++){
        idx = finddisk(req,m,head,visited);
        seq[i] = req[idx];
        st += abs(req[idx] - head);
        head = req[idx];
        visited[idx] = 1;
    }
    for(int i = 0;i < m;i++){
        printf("%d ",seq[i]);
    }
    printf("\nst: %d",st);
}

int main(){
    int n;
    printf("enter number of req: ");
    scanf("%d",&n);
    int m = n + 2;
    printf("enter req: ");
    int req[m];
    for(int i = 0;i < n;i++){
        scanf("%d",&req[i]);
    }
    req[m - 2] = 0,req[m - 1] = 199;
    int head;
    printf("enter head: ");
    scanf("%d",&head);
    cscan(req,m,head);

}