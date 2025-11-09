#include<bits/stdc++.h>
using namespace std;
void selection(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {int min=arr[i];
        for(int j=i+1;j<n;j++)
        {
            if(min>arr[j])
            {
                int temp=min;
                min=arr[j];
                arr[j]=temp;
            }
        }
        arr[i]=min;
    }
}

int main()
{
    int arr[]={3,1,8,9,3,5,7,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    selection(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
