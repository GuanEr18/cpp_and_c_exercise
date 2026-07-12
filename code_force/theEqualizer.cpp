//
// Created by Zheng on 2026/5/19.
//对于每组测试数据，如果 Shaunak 能始终获胜，输出 "YES"；否则输出 "NO"。
#include <iostream>
using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        long long val;
        cin >> val;
        sum += val;
    }
    // 条件 1: 初始总和是奇数
    // 条件 2: 变成满k状态后的总和 (n * k) 是偶数
    if ((sum % 2 != 0) || ((n * k) % 2 == 0)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}