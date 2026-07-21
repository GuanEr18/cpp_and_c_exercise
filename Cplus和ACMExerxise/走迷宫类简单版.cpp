//
// Created by Zheng on 2026/5/14.
//
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> puzzle;
void DFS (int x,int y) {
//    寻路遵循右下左上
    if (x<0 || x>=n || y<0 || y>=n) {
        return;
    }
    if (puzzle[x][y]==1 || puzzle[x][y]==2) {
        return;
    }
    puzzle[x][y]=2;
    if (x==n-1 && y==n-1) {
        cout<<"get one way to the target"<< endl;
        return;
    }
    DFS(x,y+1);
    DFS(x+1,y);
    DFS(x,y-1);
    DFS(x-1,y);
}
int main() {
    cout<<"enter length and width"<<endl;
    while (cin >> n) {
        puzzle.assign(n,vector<int>(n,0));
        cout<<"enter 0 or 1 as path or wall"<< endl;
        cout<<"the(0,0)and (n-1,n-1) must 0"<<endl;
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                cin >> puzzle[i][j];
            }
        }
        DFS(0,0);
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                cout<<puzzle[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}