//
// Created by Zheng on 2026/6/6.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,x;
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>x;
    vector<vector<int>> a(n,vector<int>(3,0));
    vector<vector<int>> b(n+1,vector<int>(x+1,0));
    for(int i=0;i<n;i++) {
        for(int j=0;j<3;j++) {
            cin>>a[i][j];
        }
        //k代表手里可能剩下的药水数量
        for(int k=1;k<n+1;k++) {
            if (k>=a[i][2]) {
                b[i][k]=max(b[i-1][k]+a[i][0],b[i-1][k-a[i][2]]+a[i][1]);
            }
            else {
                b[i][k]=b[i-1][k]+a[i][0];
            }
        }
    }
    cout << b[n][x] * 5 << "\n";
    return 0;
}