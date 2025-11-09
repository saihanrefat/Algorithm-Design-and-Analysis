#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={22,26,38,39,41,55,63,77,94};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        int flag=0;
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                flag=1;
                swap(arr[j],arr[j+1]);
            }
        }
        if(flag==0)
        {
            break;
        }
    }
for(int i=0;i<n;i++)
{
    cout<<arr[i]<< " ";
}
}

