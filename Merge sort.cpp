#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int left,int right,int mid)
{
    int size=right-left+1;
    int arr1[size];
    int i=left;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=right)
    {
        if(arr[i]<arr[j])
        {
            arr1[k++]=arr[i];
            i++;
        }
        else{
             arr1[k++]=arr[j];
            j++;
        }
    }
    while(i<=mid)
    {
        arr1[k++]=arr[i];
        i++;
    }
     while(j<=right)
    {
        arr1[k++]=arr[j];
        j++;
    }
    for(int k=0;k<size ;k++)
    {
        arr[left+k]=arr1[k];
    }
}
void divide(int arr[],int left,int right)
{
    int mid;
    if(left<right)
    {
        mid=(left+right)/2;
        divide(arr,left,mid);
        divide(arr,mid+1,right);
        merge(arr,left,right,mid);
    }
}
int main()
{
    int arr[]={8,2,4,9,3,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    divide(arr,0,n-1);
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
