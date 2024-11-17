#include<stdio.h>
#include<stdlib.h>

#define max 50
 
void FCFS(int seq[],int seqlen,int currentHead){
    int ST = 0;
    int diskseq[seqlen];
    for(int i = 0; i < seqlen; i++){
        diskseq[i] = seq[i];
        if (seq[i] > currentHead)
            ST += seq[i] - currentHead;
        else
            ST += currentHead - seq[i];
        
        currentHead = seq[i];
    }
    printf("Seek Operation: %d\nSequence: ",ST);
    for(int i = 0;i < seqlen;i++){
        printf("%d\t",diskseq[i]);
    }
}

int main(){
    int seqlen;
    printf("Enter the Disk Sequence length: ");
    scanf("%d",&seqlen);
    int seq[max];
    int currentHead;
    printf("Enter the disk sequence: ");
    for(int i = 0;i < seqlen;i++){
        scanf("%d",&seq[i]);
    }
    printf("Enter the current Head position: ");
    scanf("%d",&currentHead);
    FCFS(seq,seqlen,currentHead);
}