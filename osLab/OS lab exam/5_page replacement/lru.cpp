#include<stdio.h>
#include<limits.h>

int checkHit(int incomingPage, int temp[], int occupied) {
    
    for(int i = 0; i < occupied; i++){
        if(incomingPage == temp[i])
            return 1;
    }
    
    return 0;
}

void printFrame(int temp[], int occupied) {
    for(int i = 0; i < occupied; i++)
        printf("%d\t",temp[i]);
}

int main()
{

//    int seq[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1};
//    int seq[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3};
    int seq[] = {7,1,0,2,0,3,0,4,2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    
    int n = sizeof(seq)/sizeof(seq[0]);
    int frames = 3;
    int temp[n];
    int distance[n];
    int occupied = 0;
    int pagefault = 0;
    
    printf("Page\t Frame1 \t Frame2 \t Frame3\n");
    
    for(int m = 0; m < n; m++)
    {
        printf("%d:  \t\t",seq[m]);
        // what if currently in frame 7
        // next item that appears also 7
        // didnt write condition for HIT
        
        if(checkHit(seq[m], temp, occupied)){
            printFrame(temp, occupied);
        }
        
        // filling when frame(s) is/are empty
        else if(occupied < frames){
            temp[occupied] = seq[m];
            pagefault++;
            occupied++;
            
            printFrame(temp, occupied);
        }
        else{   //frame not empty - lru apply
            
            int max = INT_MIN;
            int index;
            // get LRU distance for each item in frame
            for (int f = 0; f < frames; f++)
            {
                distance[f] = 0;
                
                for(int k = m - 1; k >= 0; k--)
                {
                    distance[f]++;

                    if(temp[f] == seq[k])
                        break;
                }
                
                if(distance[f] > max){
                    max = distance[f];
                    index = f;
                }
            }
            temp[index] = seq[m];
            printFrame(temp, occupied);
            pagefault++;
        }
        
        printf("\n");
    }
    
    printf("Page Fault: %d",pagefault);
    
    return 0;
}