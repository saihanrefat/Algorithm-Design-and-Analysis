#include<bits/stdc++.h>
using namespace std;
void insertion(int n,int arr[])
{
    int i,j;
    int key;
    for(int j=1;j<n;j++)
    {
        i=j-1;
        key=arr[j];
        while(i>=0 &&arr[i]>key )
        {
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=key;
    }
}
int main()
{
    int arr[]={8,2,4,9,3,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    insertion(n,arr);
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
