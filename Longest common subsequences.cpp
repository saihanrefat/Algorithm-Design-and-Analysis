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

