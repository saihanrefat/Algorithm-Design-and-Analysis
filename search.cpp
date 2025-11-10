#include<bits/stdc++.h>
using namespace std;
int searching(int arr[],int n,int value)
{

    for(int i=0;i<n;i++)
    {
        if(arr[i]==value)
        {
            return 1;
            break;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int value;
    cin>>value;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   int flag= searching(arr,n,value);
   if(flag==1)
   {
       cout<<"YES";
   }
   else
   {
       cout<<"No";
   }
}
