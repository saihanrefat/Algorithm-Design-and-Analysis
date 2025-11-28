#include<bits/stdc++.h>
using namespace std;
void tsp(int curr,int count,int cost,int pathindex,vector<vector<int>>&graph,int n,vector<int>&path,vector<int>&bestpath,int &mincost,vector<bool>&visited)
{
    if(count ==n  && graph[curr][0]!=0)
    {
        int totalcost=cost+graph[curr][0];
        if(totalcost<mincost)
        {
            mincost=totalcost;
            path[pathindex+1]=0;
            bestpath=path;
        }
        return;
    }


  for(int i=0;i<n;i++)
  {
      if(!visited[i]&& graph[curr][i]!=0)
      {
          visited[i]=1;
          path[pathindex+1]=i;
          tsp(i,count+1,cost+graph[curr][i],pathindex+1,graph,n,path,bestpath,mincost,visited);
          visited[i]=0;
      }
  }
}
int main()
{
    int n=4;
    vector<vector<int>>graph={
    {0,16,11,6},
    {8,0,13,16},
    {4,7,0,9},
    {5,12,2,0}
    };
    vector<bool>visited(n,0);
    vector<int>path(n+1);
    vector<int>bestpath(n+1);
    visited[0]=1;
    path[0]=0;
    int mincost=INT_MAX;
    tsp(0,1,0,0,graph,n,path,bestpath,mincost,visited);
    cout<<mincost<<endl;
    for(int i=0;i<=n;i++)
    {
        cout<<bestpath[i]<<" ";
    }
    }
