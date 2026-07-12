#include <cmath>
#include <iostream>
#include <algorithm> // 需要包含这个头文件来使用 min 和 max
using namespace std;

double H, S1, V, L, K;
int n;
void solve() {
    // 1. 计算时间
    double firstT = sqrt((H - K) / 5.0); // 球落到车顶高度的时间
    double terminalT = sqrt(H / 5.0);    // 球落到底的时间
    // 2. 计算小车能接住的小球编号的左右极限（闭区间）
    // 加上 1e-8 是为了防止浮点数精度丢失（比如 4.99999 被误转为 4）
    double rightLimit = S1 - firstT * V + L; // 车尾最远能到达的位置
    double leftLimit = S1 - terminalT * V;   // 车头最远能到达的位置
    int n1 = (int)(rightLimit + 1e-8);
    int n2 = (int)(leftLimit + 1e-8);
    // 3. 【核心修改】将结果严格限制在合法的小球编号 [0, n-1] 范围内
    n1 = min(n1, n - 1);
    n2 = max(n2, 0);
    // 4. 计算区间内的小球数量（闭区间公式：右边界 - 左边界 + 1）
    int ans = n1 - n2 + 1;
    // 如果算出来是负数，说明小车完美错过了所有球，输出 0
    if (ans < 0) ans = 0;
    cout << ans << endl;
}

int main() {
    while (cin >> H >> S1 >> V >> L >> K >> n) {
        solve();
    }
    return 0;
}