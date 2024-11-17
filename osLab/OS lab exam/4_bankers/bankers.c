// Banker's Algorithm
#include <stdio.h>
#define MAX 10

void bankers(int p, int r, int alloc[MAX][MAX], int max[MAX][MAX], int avail[MAX]);

int main()
{
	// P0, P1, P2, P3, P4 are the Process names here    
    int alloc[MAX][MAX], max[MAX][MAX];
	int p, r;
    int avail[MAX];
    printf("Enter number of processes : ");
    scanf("%d", &p);
    printf("Enter number of resources : ");
    scanf("%d", &r);
    printf("\n Allocated matrix ");
    for(int i=0; i<p; i++) {
        printf("\n");
        for (int j=0; j<r; j++) {
            printf("Enter allocated resource %d to P%d : ", j+1, i+1);
            scanf("%d", &alloc[i][j]);
        }
    }
    
    printf("\n Max matrix ");
    for(int i=0; i<p; i++) {
        printf("\n");
        for (int j=0; j<r; j++) {
            printf("Enter max resource %d to P%d : ", j+1, i+1);
            scanf("%d", &max[i][j]);
        }
    }
   
    printf("\n");
        for (int j=0; j<r; j++) {
            printf("Enter available resource %d : ", j+1);
            scanf("%d", &avail[j]);
        }

    bankers(p,r,alloc,max,avail);
	return 0;
}


void bankers(int p, int r, int alloc[MAX][MAX], int max[MAX][MAX], int avail[MAX]) {
    int finish[MAX], ans[MAX], ind = 0;
	for (int k = 0; k < p; k++) {
		finish[k] = 0;      // no process executed at start
	}
    
	int need[MAX][MAX];
	for (int i = 0; i < p; i++) {           // calc need matrix
		for (int j = 0; j < r; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}
    int executed = 0;
	while(executed<p) {
		for (int i = 0; i < p; i++) {
			if (finish[i] == 0) {

				int flag = 0;
				for (int j = 0; j < r; j++) {
					if (need[i][j] > avail[j]){
						flag = 1;
						break;
					}
				}

				if (flag == 0) {        // process selected
                    executed++;
					ans[ind++] = i;
					for (int y = 0; y < r; y++)
						avail[y] += alloc[i][y];
					finish[i] = 1;
				}
			}
		}
	}

	int flag = 1;
	
	for(int i=0; i<p; i++)
	{
        if(finish[i]==0)
        {
            flag=0;
            printf("\nNot safe");
            break;
        }
	}
	
	if(flag==1)
	{
        printf("\nSafe Sequence\n");
        for (int i = 0; i < p - 1; i++)
            printf(" P%d ->", ans[i]+1);
        printf(" P%d", ans[p - 1]+1);
	}
}