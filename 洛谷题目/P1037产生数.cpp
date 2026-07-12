//
// Created by Zheng on 2026/5/15.
//
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int k;
int change[10][10];
string n;
vector<vector<int>> a;
//给这个数能转换到的数字打标记
void DFS(int start,bool visit[]) {
    visit[start]=true;
    for (int i=0;i<10;i++) {
        if (visit[i]==false && change[start][i]==1) {
            DFS(i,visit);
        }
    }
}
vector<int> multiply(const vector<int>& a,int b) {
    vector<int> target;
    int add=0;
    for(int i=0;i<a.size() || add>0;i++) {
        if(i<a.size()) {
            add+=a[i]*b;
        }
        target.push_back(add%10);
        add/=10;
    }
    return target;
}
int main () {
    //初始化
    memset(change,0,sizeof(change));
    while (cin>>n>>k) {
        for (int i=0;i<k;i++) {
            int x,y;
            cin>>x>>y;
            change[x][y]=1; //更改标记
        }
        vector<int> ans;
        ans.push_back(1);
        for (int i=0;i<n.size();i++) {
            int temp = n[i]-'0';
            bool visit[10];
            memset(visit,0,sizeof(visit));
            DFS(temp,visit);
            int count=0;
            for (int j=0;j<10;j++) {
                if (visit[j]==true) {
                    count++;
                }
            }
            ans=multiply(ans,count);
        }
        for (int i=ans.size()-1;i>=0;i--) {
            cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}