///Traveling salesman
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

///maximum subarray


#include<bits/stdc++.h>
using namespace std;
int max3(int a,int b,int c)
{
    return max(max(a,b),c);
}
int maxcrosing(int arr[],int left,int mid,int right)
{
  int left_sum=INT_MIN;
  int sum=0;
  for(int i=mid;i>=left;i--)
  {
      sum=sum+arr[i];
      left_sum=max(left_sum,sum);
  }
    int right_sum=INT_MIN;
   sum=0;
  for(int i=mid+1;i<=right;i++)
  {
      sum=sum+arr[i];
      right_sum=max(right_sum,sum);
  }
  return left_sum+right_sum;
}
int maxisubarray(int arr[],int left,int right)
{
     if(left==right){
        return arr[left];
     }
     int mid=(left+right)/2;
     return max3(
            maxisubarray(arr,left,mid),
            maxisubarray(arr,mid+1,right),
             maxcrosing(arr,left,mid,right)
    );
}
int main()
{
    int arr[]={-3,-4,5,-1,2,-4,6,-1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<maxisubarray(arr,0,n-1);
}


///strassence

#include<bits/stdc++.h>
using namespace std;
void add(int a[4][4],int b[4][4],int c[4][4],int rowa,int cola,int rowb,int colb,int rowc,int colc,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[rowc+i][colc+j]=a[rowa+i][cola+j]+b[rowb+i][colb+j];
        }
    }
}
void Strassences(int a[4][4],int b[4][4],int c[4][4],int rowa,int cola,int rowb,int colb,int rowc,int colc,int n)
{
    if(n==1)
    {
        c[rowc][colc]=a[rowa][cola]*b[rowb][colb];
        return;
    }
    int mid=n/2;
    int temp1[4][4]={0};
    int temp2[4][4]={0};

    ///
    Strassences(a,b,temp1,rowa,cola,rowb,colb,0,0,mid);
    Strassences(a,b,temp2,rowa,cola+mid,rowb+mid,colb,0,0,mid);
    add(temp1,temp2,c,0,0,0,0,rowc,colc,mid);
     ///
    Strassences(a,b,temp1,rowa,cola,rowb,colb+mid,0,0,mid);
    Strassences(a,b,temp2,rowa,cola+mid,rowb+mid,colb+mid,0,0,mid);
    add(temp1,temp2,c,0,0,0,0,rowc,colc+mid,mid);
     ///
    Strassences(a,b,temp1,rowa+mid,cola,rowb,colb,0,0,mid);
    Strassences(a,b,temp2,rowa+mid,cola+mid,rowb+mid,colb,0,0,mid);
    add(temp1,temp2,c,0,0,0,0,rowc+mid,colc,mid);
     ///
    Strassences(a,b,temp1,rowa+mid,cola,rowb,colb+mid,0,0,mid);
    Strassences(a,b,temp2,rowa+mid,cola+mid,rowb+mid,colb+mid,0,0,mid);
    add(temp1,temp2,c,0,0,0,0,rowc+mid,colc+mid,mid);
}
int main()
{
    int A[4][4], B[4][4], C[4][4]={0};
    int n=4;
    cout<<"Enter 1st matrix value:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>A[i][j];
        }
    }
    cout<<"Enter 2nd matrix value:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>B[i][j];
        }
    }
    Strassences(A,B,C,0,0,0,0,0,0,n);
    cout<<"3rd matrix value are:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }

}

///dijkstra


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
    vector<vector<int>>graph={
        {0,14,9,0,0,7},
     {14,0,2,8,0,0},
      {9,2,0,0,11,10},
       {0,8,0,0,6,0},
        {0,0,11,6,0,15},
         {7,0,10,0,15,0}
    };
    dij(n,0,graph);
}


///Ballman ford

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

///topological
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& topo) {
    visited[node] = true;
    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor, adj, visited, topo);
        }
    }
    topo.push_back(node); // add after visiting all neighbors
}

int main() {
    int n = 6; // number of nodes
    vector<vector<int>> adj(n);

    // Directed edges (example)
    adj[5] = {2, 0};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};

    vector<bool> visited(n, false);
    vector<int> topo;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) dfs(i, adj, visited, topo);
    }

    reverse(topo.begin(), topo.end()); // reverse to get correct order

    cout << "Topological Sort: ";
    for(int x : topo) cout << x << " ";
    cout << endl;

    return 0;
}

///Huffman


#include<bits/stdc++.h>
using namespace std;
struct node{
char ch;
int fre;
int left;
int right;
};
void huffman(node nodes[],int root,string code)
{
    if(root==-1)
    {
        return;
    }
    if(nodes[root].left==-1 && nodes[root].right==-1)
    {
        cout<<nodes[root].ch<<": "<<code<<endl;
        return;
    }
    huffman(nodes, nodes[root].left,code+"0");
    huffman(nodes,nodes[root].right,code+"1");
}
int main()
{
    char ch[]={'A','B','C','D','E'};
    int fre[]={6,6,3,2,3};
    int n=5;
    node nodes[2*n];
    bool used[2*n];
    memset(used,0,sizeof(used));
    for(int i=0;i<n;i++)
    {
        nodes[i].ch=ch[i];
        nodes[i].fre=fre[i];
        nodes[i].left=-1;
        nodes[i].right=-1;
    }
    int total=n;
    while(total<2*n-1)
    {
        int min1=-1;
        int min2=-1;
        for(int i=0;i<total;i++)
        {
            if(used[i])
            {
                continue;
            }
            if(min1==-1 ||nodes[i].fre<nodes[min1].fre)
            {
                min1=i;
            }
        }
        for(int i=0;i<total;i++)
        {
            if(used[i]||i==min1)
            {
                continue;
            }
            if(min2==-1 ||nodes[i].fre<nodes[min2].fre)
            {
                min2=i;
            }
        }

        nodes[total].ch='$';
        nodes[total].fre=nodes[min1].fre+nodes[min2].fre;
        nodes[total].left=min1;
        nodes[total].right=min2;
        used[min1]=true;
         used[min2]=true;
        total++;
    }
    int root=total-1;
    huffman(nodes,root,"");
}


///Lcs


#include<bits/stdc++.h>
using namespace std;
int main()
{
    string x="ABCBDAB";
    string y="BDCABA";
    int m=x.size();
    int n=y.size();
    int table[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            table[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                table[i][j]=1+table[i-1][j-1];
            }
            else
            {
                table[i][j]=max(table[i][j-1],table[i-1][j]);
            }
        }
    }
    cout<<"LCS length  :"<<table[m][n]<<endl;
    int i=m;
    int j=n;
    string lcs="";
    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            lcs=lcs+x[i-1];
            i--;
            j--;
        }
        else if(table[i-1][j]>=table[i][j-1])
        {
            i--;
        }
        else{
            j--;
        }
    }
    reverse(lcs.begin(),lcs.end());
    cout<<lcs;




}

///Tree vertex spliting

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int weight;
    vector<int> children;
};

// Greedy DFS with vertex splitting
int greedyDFS(vector<Node> &tree, int u, int capacity) {
    vector<int> childWeights;
    for(int v : tree[u].children) {
        childWeights.push_back(greedyDFS(tree, v, capacity));
    }

    // Sort child weights descending
    sort(childWeights.rbegin(), childWeights.rend());

    int sum = tree[u].weight;

    // Take only capacity many children
    for(int i=0; i<min(capacity, (int)childWeights.size()); i++) {
        sum += childWeights[i];
    }

    // If children > capacity, remaining children create "split nodes"
    int remaining = childWeights.size() - capacity;
    if(remaining > 0) {
        for(int i=capacity; i<childWeights.size(); i++) {
            sum += childWeights[i]; // extra children as split nodes
        }
    }

    return sum;
}

int main() {
    int n = 5;
    vector<Node> tree(n);

    // Node weights
    tree[0].weight = 10;
    tree[1].weight = 5;
    tree[2].weight = 8;
    tree[3].weight = 3;
    tree[4].weight = 7;

    // Tree edges
    tree[0].children = {1, 2, 3}; // root has 3 children -> exceeds capacity
    tree[1].children = {4};

    int capacity = 2; // max children per node
    int maxSum = greedyDFS(tree, 0, capacity);

    cout << "Maximum sum after vertex splitting (greedy): " << maxSum << endl;

    return 0;
}

///All pair shortest path


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

///prims algorithm

#include<bits/stdc++.h>
#define large 77777777
using namespace std;
void prims(int n,vector<vector<int>>&graph)
{
    vector<int>selected(n,0);
    int edges=0;
    int sum=0;
    selected[0]=1;
    while(edges<n-1)
    {
        int min=large;
        int x,y;
        for(int i=0;i<n;i++)
        {
            if(selected[i])
            {
                for(int j=0;j<n;j++)
                {
                    if(!selected[j] &&graph[i][j])
                    {
                        if(min>graph[i][j])
                        {
                            min=graph[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        cout<<x<<" "<<y<<endl;
    sum=sum+graph[x][y];
    selected[y]=1;
    edges++;
    }
    cout<<"Total cost is:"<<sum;
}
int main()
{
    int n=8;
    vector<vector<int>>graph={
    {0,3,0,5,2,0,0,0},
    {3,0,7,0,6,0,0,0},
    {0,7,0,0,10,2,0,0},
    {5,0,0,0,3,0,2,0},
    {2,6,10,3,0,7,5,5},
    {0,0,2,0,7,0,0,6},
    {0,0,0,2,5,0,0,4},
    {0,0,0,0,5,6,4,0}
    };
    prims(n,graph);

}


///knapsack problem

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


///BFS

#include<bits/stdc++.h>
using namespace std;
# define max 100
int que[max];
int rear=0;
int front =0;
int adj[max][max];
int visited[max];
void bfs(int n,int start)
{
    que[rear++]=start;
    visited[start]=1;
    while(front<rear)
    {
        int u=que[front++];
        cout<<u;
        for(int v=0;v<n;v++)
        {
            if(adj[u][v]==1 && !visited[v])
            {
                que[rear++]=v;
                visited[v]=1;
            }
        }
    }
}
int main()
{
    int node=4;
    int edge=4;
    for(int i=0;i<4;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    bfs(node,0);
}

///Dfs

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
///dfs
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

///job sequencing

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

///Activity selection



#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n=5;
    int Activity[n]={1,2,3,4,5};
    int start[n]={0,2,1,0,2};
    int finish[n]={2,4,3,1,5};

    ///sort finish in the ascending order
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(finish[i]>finish[j])
            {
                swap(finish[i],finish[j]);
                swap(Activity[i],Activity[j]);
                swap(start[i],start[j]);
            }
        }
    }
    int result[n];
    int fini=0;
    int k=0;
    result[k++]=Activity[0];
    fini=finish[0];
    for(int i=1;i<n;i++)
    {
        if(start[i]>=fini)
        {
            result[k++]=Activity[i];
            fini=finish[i];
        }
    }
    for(int i=0;i<k;i++)
    {
        cout<<result[i]<<" ";
    }
}


///











