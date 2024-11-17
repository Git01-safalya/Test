/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int checkhit(int k,vector<int> temp)
{
    for(int i = 0;i<3;i++)
    {
        if(k == temp[i])
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    vector<int> sequence = {7,1,0,2,0,3,0,4,2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    
    int frames = 3;
    vector<int> frame(frames,-1);
    vector<int> distance(frames);
    int pageFault = 0;
    
    
    for(int p = 0;p<20;p++)
    {
        int s = 0;
        if(checkhit(sequence[p],frame))
        {
            s++;
        }
        else if(pageFault <= 3 && s == 0)
        {
            frame[p] = sequence[p];
            pageFault++;
        }
        else
        {
            int max = -1;
            int index = -1;
            
            for(int i = 0 ;i<frames;i++)
            {
                distance[i] = 0;
                
                for(int k = p-1;k>=0;k--)
                {
                    distance[i]++;
                    if(frame[i] == sequence[k])
                    {
                        break;
                    }
                }
                
                if(distance[i] > max)
                {
                    max = distance[i];
                    index = i;
                }
            }
            
            frame[index] = sequence[p];
            pageFault++;
            
        }
    }
    
    cout<<pageFault;
    

    return 0;
}
