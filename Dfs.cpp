#include<bits/stdc++.h>
#define maxn 100
using namespace std;
int adj[maxn][maxn];
int visited[maxn];
void dfs(int n,int start)
{
    visited[start]=1;
    cout<<start<<endl;
    for(int v=0;v<n;v++)
    {
        if(!visited[v] && adj[start][v])
        {
            dfs(n,v);
        }
    }

}

int main()
{
    int node,edge;
    cout<<"Enter total node and edge : ";
    cin>>node>>edge;
     cout<<"Enter all edge between two nodes : ";
    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    int start;
     cout<<"Enter vertics name to start: ";
     cin>>start;
     dfs(node,start);
}

