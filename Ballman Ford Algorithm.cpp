#include<bits/stdc++.h>
using namespace std;

#define INF 999999

void bellmanFord(int n, int source, vector<vector<int>> &graph)
{
    vector<int> dist(n, INF);
    dist[source] = 0;
for(int k=0;k<n-1;k++)
{
    for(int u=0;u<n;u++)
    {
        for(int v=0;v<n;v++)
        {
            if(graph[u][v]!=0)
            {
                if(dist[u] != INF &&dist[u]+graph[u][v]<dist[v])
                {
                    dist[v]=dist[u]+graph[u][v];
                }
            }
        }
    }
}

///negative cycle check
for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(graph[i][j]!=0)
            {
                if(dist[i] != INF &&dist[i]+graph[i][j]<dist[j])
                {
                    cout<<"Negative cycle exist";
                    return;
                }
            }
        }
    }
    ///result
    for(int i=0;i<n;i++)
    {
        cout<<i<<"      "<<dist[i]<<endl;
    }
}

int main()
{
    int n = 4;

    vector<vector<int>> graph =
    {
        {0, 1, 2,  0,},
        {0, 0,  2, 0},
        {0,  0,  0,  2},
        {0,  -5,  0,  0}
    };

    bellmanFord(n, 0, graph);
}

