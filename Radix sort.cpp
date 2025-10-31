#include<bits/stdc++.h>
using namespace std;
int getmax(int arr[],int n)
{
 int max=arr[0];
 for(int i=0;i<n;i++)
 {
     if(arr[i]>max)
     {
         max=arr[i];
     }
 }
 return max;
}
void Counting_Sort(int arr[],int n,int exp)
{
    vector<int> count(10,0);
    for (int i = 0; i < n; i++)
    {
        int index = (arr[i] / exp) % 10;
        count[index]++;
    }
    for(int i=1;i<=9;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--) {
    int index = (arr[i] / exp) % 10;
    output[count[index] - 1] = arr[i];
    count[index]--;
}
    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }
}
void radixsort(int arr[],int n)
{
    int maximum=getmax(arr,n);
    for(int exp=1;maximum/exp>0;exp*=10)
    {
         Counting_Sort(arr,n,exp);
    }
}
int main()
{
    int arr[]={105,456,789,234,163,907,356};
    int size=sizeof(arr)/sizeof(arr[0]);
    radixsort(arr,size);
    cout<<"Sorted array is: ";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

