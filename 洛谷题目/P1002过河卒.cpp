//
// Created by Zheng on 2026/5/18.
//
#include <iostream>
#include <vector>
using namespace std;

int a[2][2];
vector<vector<int>> map;
vector<vector<long long> > memory;
int dx[]={1,2,2,1,-1,-2,-2,-1};
int dy[]={2,1,-1,-2,-2,-1,1,2};
//返回值改成long long 代表返回的路径数
long long  DFS(int x,int y) {
    if (x<0 || y<0 || x>a[0][0] || y>a[0][1]) {
        return 0;
    }
    if (map[x][y]==1) {
        return 0;
    }
    // map[x][y]=2;这个在这道题目不需要
    if (x==a[0][0] && y==a[0][1]) {
        return 1;
    }
    if (memory[x][y]!=-1) {
        return memory[x][y];
    }
    memory[x][y]=DFS(x+1,y)+DFS(x,y+1);
    //由此可知 memory[x][y]其实是调用了DFS通过向终点递归从终点开始加上路数
    return memory[x][y];
}
//memory[x][y]中第（x,y）点存的值是这个点通向终点的路数
int main() {
    while (cin>>a[0][0]>>a[0][1]>>a[1][0]>>a[1][1]) {
        map.clear();
        map.resize(a[0][0]+1,vector<int>(a[0][1]+1,0));
        memory.clear();
        memory.resize(a[0][0]+1,vector<long long>(a[0][1]+1,-1));
        map[a[1][0]][a[1][1]]=1;
        for (int i=0;i<8;i++) {
            int x=a[1][0]+dx[i],y=a[1][1]+dy[i];
            if (x>=0 && x<=a[0][0] && y>=0 && y<=a[0][1]) {
                map[x][y]=1;
            }
        }
        cout<<DFS(0,0)<<endl;
        //测试
        for (int i=0;i<a[0][0];i++) {
            for (int j=0;j<a[0][1];j++) {
                cout<<memory[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}