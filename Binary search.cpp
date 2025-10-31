#include<bits/stdc++.h>
using namespace std;
int binary(int arr[],int n,int value)
{
    int first=0;
    int last=n-1;
        while(first<last)
        {
             int mid=(first+last)/2;
            if(arr[mid]==value)
            {
                return mid;
                break;
            }
            else if(arr[mid]>value)
            {
                last=mid-1;
            }
            else
            {
                first=mid+1;
            }
        }
        return -1;

}
int main()
{
    int arr[]={22,26,38,39,41,55,63,77,94};
    int size=sizeof(arr)/sizeof(arr[0]);
    int data;
    cout<<"Enter searching data: ";
    cin>>data;
    int loc=binary(arr,size,data);
    if(loc==-1)
    {
        cout<<"Data are not found"<<endl;
    }
    else
    {
        cout<<"Data are found"<<endl;
    }

}
