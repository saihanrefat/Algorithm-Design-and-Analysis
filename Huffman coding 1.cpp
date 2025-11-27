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
