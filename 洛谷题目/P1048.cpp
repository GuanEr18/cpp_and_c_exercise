#include<iostream>
using namespace std;

 void DFS(int i, int j, int sum)
{
    if(i==2)
    {
        cout<<sum<<endl;
        return;
    }
    if(j==m)
    {
        DFS(i+1,0,sum);
        return;
    }
    DFS(i,j+1,sum+a[i][j]);
}

int main () 
{
    int t,m;
    cin>>t>>m;
    int a[105][2];
    // 
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    // 
    int sum=0;
    DFS(0,0,sum);
}