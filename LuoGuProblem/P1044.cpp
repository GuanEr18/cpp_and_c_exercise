#include <iostream>
#include <cstring>
using namespace std;

long long dp[20][20];
int n;

/**
 * i 表示有几个数没有入列，j 入列的数字
 */
long long dfs(int i, int j) { 
    if (i == 0) return dp[i][j] = 1;
    // 如果所有数都已经入列，那就只能执行弹出操作（可能数为1）
    if (dp[i][j] != -1) return dp[i][j];
    // 遇到已经计算过的的情况，就返回
    long long ans = 0;
    // 选择 1 是入栈
    ans += dfs(i-1, j+1);
    // 选择 2 是弹出
    if (j>0) ans += dfs(i, j-1);
    // 某个点的方案总数是入栈和弹出的方案之和
    return dp[i][j] = ans;
}
int main () {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << dfs(n, 0) << endl;
}
/**
 * 这个数组的[n][0]是起点，一直走到[0][1],[0][2],[0][3] 作为终点。再作为递归返回计算
 */