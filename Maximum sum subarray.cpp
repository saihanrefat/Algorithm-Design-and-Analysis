#include<bits/stdc++.h>
using namespace std;
int max3(int a,int b,int c)
{
    return max(max(a,b),c);
}
int maxSrossingSum(int arr[],int left,int mid,int right)
{
    int left_sum=INT_MIN;
    int sum=0;
    for(int i=mid;i>=left;i--)
    {
        sum=sum+arr[i];
        left_sum=max(left_sum,sum);
    }
    sum=0;
    int right_sum=INT_MIN;
     for(int i=mid+1;i<=right;i++)
    {
        sum=sum+arr[i];
        right_sum=max(right_sum,sum);
    }
    return right_sum+left_sum;
}
int maximumSubarraySum(int arr[],int left,int right)
{
    if(left==right)
    {
        return arr[0];
    }
    int mid=(left+right)/2;
    return max3(
                maximumSubarraySum(arr,0,mid),
                maximumSubarraySum(arr,mid+1,right),
                maxSrossingSum(arr,left,mid,right)
                );
}
int main()
{
    int arr[]={-2,-5,6,-2,-6,1,5,-6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum sum Subarray is: "<<maximumSubarraySum(arr,0,n-1);
    return 0;
}
