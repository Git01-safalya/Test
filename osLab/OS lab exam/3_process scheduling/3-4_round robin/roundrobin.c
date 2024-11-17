#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define max 50
struct P
{
    int at, bt, CT, WT, TAT;
};
int main()
{
    int n, a, b, q;
    printf("enter the number of processes : ");
    scanf("%d", &n);
    struct P p[max];
    for (int i = 0; i < n; i++)
    {
        printf("enter arrival time for process %d", i + 1);
        scanf("%d", &(p[i].at));
        printf("enter  burst time for process %d", i + 1);
        scanf("%d", &(p[i].bt));
    }
    printf("enter time quantum ");
    scanf("%d", &q);
    float AT[20], BT[20];

    for (int i = 0; i < n; i++)
    {
        AT[i] = p[i].at;
        BT[i] = p[i].bt;
    }
    int c = n;
    float time = 0;
    double tot_wt = 0;
    double tot_tat = 0;
    
    int job = -1;
    while (c != 0)
    {
        job=-1;
        
        for (int i = 0; i < n; i++)
        { 
            int p = time + 0.1;
            if (AT[i] <= p && (AT[job] > AT[i] || job == -1) && BT[i] > 0)
            {
                job = i;
            }
        }
        
        if(job==-1)
        {
            time++;
            continue;
        }
        if (BT[job] <= q)
        {
            time+=BT[job];
            BT[job]=0;
        }
        else{
            time+=q;
            BT[job]-=q;
        }
        if(BT[job]>0)
        {
            AT[job]=time+0.1;
        }
        if(BT[job]==0)
        {
            c--;
            p[job].CT=time;
            p[job].TAT=p[job].CT-p[job].at;
            p[job].WT=p[job].TAT-p[job].bt;
            tot_wt+=p[job].WT;
            tot_tat+=p[job].TAT;
        }
    }
    float average_waiting_time = tot_wt /n ; 
    float average_turnaround_time = tot_tat / n;
    
    printf("\nProcess | AT | BT | CT | WT |\n");
    for (int i = 0; i < n; i++)
    {      
        printf("  P%d    | %2d | %2d | %2d | %2d  |\n", i + 1, p[i].at, p[i].bt, p[i].CT, p[i].WT);
    }    
    
    printf("\nAverage Waiting Time: %lf", average_waiting_time);
    printf("\nAverage Turnaround Time: %lf", average_turnaround_time);
    
    return 0;
}