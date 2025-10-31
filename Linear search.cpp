#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[]={2,6,8,9,1,5,3,7,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    int data;
    cout<<"Enter searching data: ";
    cin>>data;
    int loc=size;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==data)
        {
            loc=i;
            break;
        }
    }
    if(loc==size)
    {
        cout<<"Data are not found"<<endl;
    }
    else
    {
        cout<<"Data are found at "<<loc<<endl;
    }

}
