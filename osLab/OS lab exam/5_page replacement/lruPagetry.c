#include<stdio.h>
#define MAX 20
void lruPage(int pages, int frame_size, int seq[]);

int main()
{   
    printf("\n\n\tLRU Page replacement\n");
    int frame_size, pages;
    printf("Enter no of pages : ");
    scanf("%d", &pages);
    int seq[MAX];
    printf("Enter sequence : ");
    for (int i=0; i<pages; i++) {
        scanf("%d", &seq[i]);
    }
    printf("Enter frame size : ");
    scanf("%d", &frame_size);

    lruPage(pages, frame_size, seq);
    return 0;
}

void lruPage(int pages, int frame_size, int seq[]) {
    int position;
    int a = 0, b = 0, pageFaults = 0;
    int frames[MAX];
    int temp[MAX];

    for(int f = 0; f < frame_size; f++){
            frames[f] = -1;     //empty frames
    }
    
    for(int m = 0; m < pages; m++)
    {
        printf("%d  |\t", seq[m]);
            a = 0, b = 0;

            // check if page already in frame
            for(int f = 0; f < frame_size; f++)
            {
                if(frames[f] == seq[m])     //page HIT
                {
                        a = 1;
                        b = 1;
                        break;
                }
            }
            if(a == 0)  //no page hit
            {
                // if page not in frame, check for empty frame
                for(int f = 0; f < frame_size; f++)
                {
                    if(frames[f] == -1)
                    {
                        frames[f] = seq[m];
                        b = 1;      //pageFault
                        pageFaults++;
                        break;
                    }
                }
            }
            if(b == 0)  //no empty frame
            {
                for(int f = 0; f < frame_size; f++)
                    temp[f] = 0;
                
                for(int k=m-1, l=1; l <= frame_size - 1; l++, k--)
                {
                    for(int f = 0; f < frame_size; f++)
                    {
                        if(frames[f] == seq[k])
                        {
                            temp[f] = 1;
                        }
                    }
                }
                for(int f = 0; f < frame_size; f++)
                {
                    if(temp[f] == 0)
                        position = f;
                }
                frames[position] = seq[m];
                pageFaults++;
            }
            
            for(int f = 0; f < frame_size; f++)
            {
                if(frames[f]==-1)
                    printf("-\t", frames[f]);
                else
                    printf("%d\t", frames[f]);
            }
            printf("\n");
    }
    printf("\nTotal Number of Page Faults:\t%d\n", pageFaults);
}