#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, M; // T: 背包容量(总时间), M: 物品数量(草药数目)
int main () {
    cin >> T >> M;
    // 存储物品的重量(first)和价值(second)
    vector<pair<int,int>> value(M); 
    for (int i = 0; i < M; i++) {
        cin >> value[i].first >> value[i].second;
    }
    // dp[i][j] 表示前 i 个物品，在容量为 j 时的最大价值
    // 第一维是物品数量(M)，第二维是背包容量(T)
    vector<vector<int>> dp(M+1, vector<int>(T+1, 0)); 
    for (int i = 1; i <= M; i++) { // 外层遍历物品
        int w = value[i-1].first;  // 当前物品的重量(采摘时间)
        int v = value[i-1].second; // 当前物品的价值
        for (int j = 0; j <= T; j++) { // 内层遍历背包容量(总时间)
            // 第一选择：不拿第 i 件物品
            dp[i][j] = dp[i-1][j]; 
            // 第二选择：拿第 i 件物品（前提是当前容量 j 装得下该物品）
            if (j >= w) {
                dp[i][j] = max(dp[i][j], dp[i-1][j - w] + v);
            }
        }
    }
    cout << dp[M][T] << endl;
    return 0;
}
// 装箱问题优先考虑动态规划