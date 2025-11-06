#include<bits/stdc++.h>
using namespace std;
void add(int A[4][4],int B[4][4],int C[4][4],int rowA,int colA,
               int rowB,int colB,int rowC,int colC,int size)
               {
                   for(int i=0;i<size;i++)
                   {
                       for(int j=0;j<size;j++)
                       {
                           C[rowC+i][colC+j]=A[rowA+i][colA+j]+B[rowB+i][colB+j];                       }
                   }
               }


void Strassen(int A[4][4],int B[4][4],int C[4][4],int rowA,int colA,
               int rowB,int colB,int rowC,int colC,int size)
               {
                  if(size==1)
                  {
                      C[rowC][colC]=A[rowA][colA]*B[rowB][colB];
                      return;
                  }
                  int mid=size/2;
                  int temp1[4][4]={0},temp2[4][4]={0};
                  ///A11,B11+A12,B21
                  Strassen(A,B,temp1,rowA,colA,rowB,colB,0,0,mid);
                  Strassen(A,B,temp2,rowA,colA+mid,rowB+mid,colB,0,0,mid);
                  add(temp1,temp2,C,0,0,0,0,rowA,colA,mid);
                   ///A11,B12+A12,B22
                  Strassen(A,B,temp1,rowA,colA,rowB,colB+mid,0,0,mid);
                  Strassen(A,B,temp2,rowA,colA+mid,rowB+mid,colB+mid,0,0,mid);
                  add(temp1,temp2,C,0,0,0,0,rowA,colA+mid,mid);
                  ///A21,B11+A22,B21
                  Strassen(A,B,temp1,rowA+mid,colA,rowB,colB,0,0,mid);
                  Strassen(A,B,temp2,rowA+mid,colA+mid,rowB+mid,colB,0,0,mid);
                  add(temp1,temp2,C,0,0,0,0,rowA+mid,colA,mid);
                  ///A21,B11+A22,B22
                  Strassen(A,B,temp1,rowA+mid,colA,rowB,colB,0,0,mid);
                  Strassen(A,B,temp2,rowA+mid,colA+mid,rowB+mid,colB+mid,0,0,mid);
                  add(temp1,temp2,C,0,0,0,0,rowA+mid,colA+mid,mid);
               }
int main()
{
    int A[4][4],B[4][4],C[4][4]={0};
    cout<<"Enter the value of matrix A :"<<endl;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>A[i][j];
        }
    }
    cout<<"Enter the value of matrix B :"<<endl;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>B[i][j];
        }
    }
    Strassen(A,B,C,0,0,0,0,0,0,4);
    cout<<"Matrix multiplication of the A and B:"<<endl;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
}
