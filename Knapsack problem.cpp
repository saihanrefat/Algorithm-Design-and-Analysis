#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=7;
    double objects[n]={1,2,3,4,5,6,7};
    double profits[n]={12,5,16,7,9,11,6};
    int weight[n]={3,1,4,2,9,4,3};
    double weight_per_kg[n];
    for(int i=0;i<n;i++)
    {
        weight_per_kg[i]=profits[i]/weight[i];
    }

    ///sort according to weight per kg;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(weight_per_kg[i]<weight_per_kg[j])
            {
                swap(weight_per_kg[i],weight_per_kg[j]);
                swap(weight[i],weight[j]);
                swap(profits[i],profits[j]);
                swap(objects[i],objects[j]);
            }
        }
    }

    int maxload=15;
    double totalprofit=0;

    for(int i=0;i<n;i++)
    {
        for(int j=weight[i];j>=1;j--)
        {
            if(maxload>0)
            {
                totalprofit=totalprofit+weight_per_kg[i];
                maxload=maxload-1;
            }
        }
    }
   cout<<totalprofit;;
}
