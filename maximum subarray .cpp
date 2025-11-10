#include<bits/stdc++.h>
using namespace std;
int maxsubarray(vector<int>&arr)
{
    int maxi=arr[0];
    int maxend=arr[0];
    for(int i=0;i<arr.size();i++)
    {
        maxend=max(arr[i],maxend+arr[i]);
        maxi=max(maxi,maxend);
    }
    return maxi;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int maxsum=maxsubarray(arr);
    cout<<maxsum;
}

