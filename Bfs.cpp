#include<bits/stdc++.h>
using namespace std;
const int maxn =100;
int adj[maxn][maxn];
int que[maxn];
int visited[maxn];
int front=0;
int rear=0;
void bfs(int n,int start)
{
   que[rear++]=start;
    visited[start]=1;
    while(rear>front)
    {
        int u=que[front++];
        cout<<u<<endl;
        for(int v=0;v<n;v++)
        {
            if(!visited[v]&& adj[u][v])
            {
                que[rear++]=v;
                visited[v]=1;
            }
        }
    }
}


int main()
{
    int n=4;
    int edges=4;
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    bfs(n,0);
}
