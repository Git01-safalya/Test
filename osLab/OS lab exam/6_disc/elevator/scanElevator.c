#include<stdio.h>
#include<stdlib.h>

void sort(int req[],int n){
    for(int i = 0;i < n - 1;i++){
        for(int j = i + 1;j < n;j++){
            if(req[j] < req[i]){
                int temp = req[j];
                req[j] = req[i];
                req[i] = temp;
            }
        }
    }
}

void scan(int req[],int n,int head){
    sort(req,n);
    int curr,prev,st = 0;
    for(int i=0; i<n; i++){
        if(head < req[i]){
            curr = i;
            prev = i - 1;
            break;
        }
    }
    for(int i=curr; i<n; i++){
        printf("%d ",req[i]);
        st += abs(req[i] - head);
        head = req[i];
    }
    for(int i=prev; i>=0; i--){
        printf("%d ",req[i]);
        st += abs(req[i] - head);
        head = req[i];
    }
    printf("\nst: %d",st);
}

int main(){
    int m;
    printf("enter number of reqs: ");
    scanf("%d",&m);
    int n = 7 + 1;
    int head;
    printf("enter head: ");
    scanf("%d",&head);
    int req[n];
    printf("enter req: "); //82,170,43,140,24,16,190
    for(int i = 0;i < m;i++){
        scanf("%d",&req[i]);
    }
    req[n - 1] = 199;
    scan(req,n,head);
}