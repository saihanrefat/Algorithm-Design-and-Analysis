#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=5;
    int jobid[]={1,2,3,4,5};
    int profits[]={10,5,20,1,15};
    int deadlines[]={1,3,2,3,2};

    ///sort according to the decending order;
   for(int i=0;i<n-1;i++)
   {
        for(int j=i+1;j<n;j++)
    {
        if(profits[i]<profits[j])
        {
            swap(profits[i],profits[j]);
            swap(jobid[i],jobid[j]);
            swap(deadlines[i],deadlines[j]);
        }
    }
   }

   ///find maximum slot;
   int maxdeadlines=0;
   for(int i=0;i<n;i++)
   {
       if(deadlines[i]>maxdeadlines)
       {
           maxdeadlines=deadlines[i];
       }
   }

   ///assign all slot false
   bool slot[maxdeadlines];
   for(int i=0;i<maxdeadlines;i++)
   {
       slot[i]=false;
   }

   int result[maxdeadlines];
   int totalprofit=0;

   for(int i=0;i<n;i++)
   {
       for(int j=deadlines[i]-1;j>=0;j--)
       {
           if(!slot[j])
           {
               slot[j]=true;
               result[j]=jobid[i];
               totalprofit=totalprofit+profits[i];
               break;
           }
       }
   }
   for(int i=0;i<maxdeadlines;i++)
   {
       cout<<result[i]<<" ";
   }
   cout<<endl<<"Total profit is: "<<totalprofit;
}
