//
// Created by Zheng on 2026/3/28.
//
//最短时间是都朝近端方向下桥
//最长时间是朝远端下桥 T=步行时间+阻挡时间
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//  最少时间应该是所有人都下桥的最少时间
void mintime(int L, vector<int>& site) {
    int max_min_dist = 0; // 记录“最短距离”中的最大值
    for (int pos : site) {
        // 当前士兵向左走(pos) 或 向右走(L+1-pos) 的最短距离
        int my_min = min(pos, L + 1 - pos);
        // 更新全局最大值（木桶效应，取决于最慢的那个人）
        if (my_min > max_min_dist) {
            max_min_dist = my_min;
        }
    }
    cout << max_min_dist << " ";
}
void maxtime(int T,int L,int N,vector<int>&site) {
    auto itmin=std::min_element(site.begin(),site.end());
    auto itmax=std::max_element(site.begin(),site.end());
    if (L+1-*itmin>=*itmax) {
        T=L+1-*itmin;
    }
    else {
        T=*itmax;
    }
    cout<<T<<endl;
}
int main () {
    int T=0,L,N;
    while (cin>>L>>N) {
        vector<int>site(N);
        for (int i=0;i<N;i++) {
            cin>>site[i];
        }
        mintime(L,site);
        maxtime(T,L,N,site);
    }
    return 0;
}
//还是过不了
//改了mintime方程，过不了第一个测试，其他都可以