
#include<bits/stdc++.h>
using namespace std;
int position(int arr[],int first,int last)
{
    int k=first-1;
    int pivot=arr[last];
    for(int i=first;i<last;i++ )
    {
        if(pivot>arr[i])
        {
            k++;
            swap(arr[k],arr[i]);
        }
    }
    swap(arr[k+1],arr[last]);
    return k+1;
}
void quicksort(int arr[],int first,int last)
{
   if(first<last)
   {
       int pi=position(arr,first,last);
       quicksort(arr,0,pi-1);
        quicksort(arr,pi+1,last);
   }
}

int main()
{
    int arr[]={3,1,8,9,3,5,7,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
