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
