#include<bits/stdc++.h>
using namespace std;
int main()
{
    int inf=9999999;
    char node[]={'A','B','C','D'};
    int n = sizeof(node)/sizeof(node[0]);

   int matrix[4][4]={
   {0,3,inf,7},
   {inf,0,2,inf},
   {5,inf,0,1},
   {2,inf,inf,0}
};
 int table[5][4][4];
 for(int i=0;i<n;i++)
 {
     for(int j=0;j<n;j++)
     {
         table[0][i][j]=matrix[i][j];
     }
 }
 for(int k=1;k<=n;k++)
 {
     for(int i=0;i<n;i++)
 {
     for(int j=0;j<n;j++)
     {
         table[k][i][j]=min(table[k-1][i][j],(table[k-1][i][k-1]+table[k-1][k-1][j]));
     }
 }
 }
 for(int i=0;i<n;i++)
 {
     cout<<node[i]<<" ";
 }
 cout<<endl;
 for(int i=0;i<n;i++)
 {
     cout<<node[i]<<" ";
     for(int j=0;j<n;j++)
     {
         if(table[n][i][j]>=inf)
         {
             cout<<"INF"<<" ";
         }
         else
         {
             cout<<table[n][i][j]<<" ";
         }
     }
     cout<<endl;
 }
 return 0;
 }
