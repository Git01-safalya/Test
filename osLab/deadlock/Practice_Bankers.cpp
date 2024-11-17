#include<iostream>
using namespace std;

int main()
{
    int n = 5;
    int m = 3;

    int alloc[5][3] = {{0, 1, 0},  
                       {2, 0, 0},   
                       {3, 0, 2},   
                       {2, 1, 1},    
                       {0, 0, 2}};  
  
    int max[5][3] = {{7, 5, 3},  
                     {3, 2, 2},    
                     {1, 0, 2},   
                     {2, 2, 2},    
                     {4, 3, 3}}; 

    int need[n][m];
    int rem[m] = {3,3,2};
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        need[i][j]= max[i][j] - alloc[i][j];
    }

    int ans[n] = {0};
    int f[n] = {0};
    int index = 0;
    for(int k = 0;k<5;k++)
    {
        for(int i = 0;i<n;i++)
        {
            if(f[i] == 0)
            {

            
            int flag = 0;
            for(int j = 0;j<m;j++)
            {
                if(need[i][j] > rem[j])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                ans[index] = i;
                index++;
                f[i] = 1;
                for(int l = 0;l<3;l++)
                {
                    rem[l] += alloc[i][l];
                }

            }
            }
        }
    }

    int flag = 0;
    for(int i = 0;i<n;i++)
    {
        if(f[i] == 0)
        {
            flag = 1;
        }
    }

    if(flag == 0)
    {
        cout<<"Safe path exist :";
        for(int i = 0;i<n;i++)
        {
            cout<<"P"<<ans[i]<<" ";
        }
    }
    else
    {
        cout<<"Safe path doesn't exist "<<endl;
    }
    return 0;
}