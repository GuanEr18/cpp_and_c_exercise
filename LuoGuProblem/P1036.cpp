//
// Created by Zheng on 2026/5/15.
//
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int n,k,kind=0;
vector<int> a;
bool judgement(int target) {
    int limit=(int)sqrt(target)+1;
    if (target <2) {
        return false;
    }
    if (target == 2 || target == 3) {
        return true;
    }
    if (target%2==0) {
        return false;
    }
    for (int i=3; i<=limit; i+=2) {
        if (target % i == 0) {
            return  false;
        }
    }
    return true;
}
void DFS(int start,int round,int sum) {
    //剪枝优化：如果剩下的全选上也不够就返回（一步步返回到够为止）
    if (n-start<k-round) {
        //这个时候还没有选够k个数字不用判断
        return;
    }
    if (round == k) {
        if (judgement(sum)) {
            kind++;
        }
        return;
    }
    DFS(start+1,round,sum);//不选
    DFS(start+1,round+1,sum+a[start]);//选

    // 用 for 循环向后枚举选择，保证不重复、不回头
    // for (int i = start; i < n; i++) {
    //     DFS(i+1,round+1,sum+a[i]);
    // }
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); // 进一步解除 cin 和 cout 的绑定
    while (cin>>n>>k) {
        a.resize(n);
        for (int i=0;i<n;i++) {
            cin>>a[i];
        }
        DFS(0,0,0);
        cout<<kind<<endl;
    }
    return 0;
}