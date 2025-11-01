#include<bits/stdc++.h>
#define INF 999999
using namespace std;
void dij(int n,int source,vector<vector<int>>&graph)
{
    vector<int>dist(n,INF);
    vector<int>visited(n,0);
    dist[source]=0;
    for(int i=0;i<n-1;i++)
    {
        int u=-1;
        for(int j=0;j<n;j++)
        {
            if(!visited[j]&&(u==-1 || dist[j]<dist[u]))
            {
                u=j;
            }
        }
        visited[u]=1;
        for(int v=0;v<n;v++)
        {
            if(!visited[v]&& graph[u][v]&& (dist[u]+graph[u][v]<dist[v]))
            {
                dist[v]=dist[u]+graph[u][v];
            }
        }

    }
    cout << "Vertex\tDistance from Source(" << source << ")\n";
    for (int i = 0; i < n; i++)
    {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

int main()
{
    int n=6;
    vector<vector<int>>graph(n);
    graph={
        {0,14,9,0,0,7},
     {14,0,2,8,0,0},
      {9,2,0,0,11,10},
       {0,8,0,0,6,0},
        {0,0,11,6,0,15},
         {7,0,10,0,15,0}
    };
    dij(n,0,graph);
}
