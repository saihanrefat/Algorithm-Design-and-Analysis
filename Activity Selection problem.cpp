#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n=5;
    int Activity[n]={1,2,3,4,5};
    int start[n]={0,2,1,0,2};
    int finish[n]={2,4,3,1,5};

    ///sort finish in the ascending order
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(finish[i]>finish[j])
            {
                swap(finish[i],finish[j]);
                swap(Activity[i],Activity[j]);
                swap(start[i],start[j]);
            }
        }
    }
    int result[n];
    int fini=0;
    int k=0;
    result[k++]=Activity[0];
    fini=finish[0];
    for(int i=1;i<n;i++)
    {
        if(start[i]>=fini)
        {
            result[k++]=Activity[i];
            fini=finish[i];
        }
    }
    for(int i=0;i<k;i++)
    {
        cout<<result[i]<<" ";
    }
}
