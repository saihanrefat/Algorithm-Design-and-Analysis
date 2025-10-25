#include<bits/stdc++.h>
using namespace std;
void Counting_Sort(int arr[],int n)
{
    int maxval=arr[0];
    for(int i=0;i<n;i++)
    {
        if(maxval<arr[i])
        {
            maxval=arr[i];
        }
    }
    vector<int> count(maxval+1,0);
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }
    for(int i=1;i<=maxval;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    vector<int> output(n);
    for(int i=n-1;i>=0;i--)
    {
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }
}

int main()
{
    int arr[]={1,2,4,3,0,2,1,7,1,4,3,0};
    int n=sizeof arr/sizeof(arr[0]);
    Counting_Sort(arr,n);
    cout<<"Sorted Array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

