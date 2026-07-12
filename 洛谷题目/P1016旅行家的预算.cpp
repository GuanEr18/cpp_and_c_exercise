//
// Created by Zheng on 2026/4/26.
//
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm> // 用于 swap

using namespace std;

/**
 * 洛谷 P1016 [NOIP1999 提高组] 旅行家的预算
 * 核心策略：贪心算法
 * 1. 如果油箱范围内有更便宜的站：只加到刚好能撑到那个站的油量。
 * 2. 如果范围内没有更便宜的站：在当前站加满油，然后前往下一站。
 */

int main() {
    double S, C, L, P0;
    int N;
    // S:总距离 C:油箱容量 L:每单位油行驶距离 P0:起点油价 N:加油站数量
    if (!(cin >> S >> C >> L >> P0 >> N)) return 0;

    double longest = C * L; // 满油状态下最远能跑多远
    double leftLength = 0;  // 关键变量：油箱内剩余油量折算成可行驶的公里数

    // D[i] 存储距离，P[i] 存储价格。索引 0 是起点，N+1 是终点。
    vector<double> D(N + 2, 0), P(N + 2, 0);
    P[0] = P0;      // 起点油价
    D[N + 1] = S;   // 终点距离（终点油价默认为 0，因为它最便宜，能吸引车往终点开）

    for (int i = 1; i <= N; i++) {
        cin >> D[i] >> P[i];
    }

    // --- 步骤 1：预处理（排序） ---
    // 虽然题目通常有序，但为了过所有测试点，必须保证距离从小到大
    for (int i = 0; i <= N; i++) {
        for (int j = i + 1; j <= N + 1; j++) {
            if (D[i] > D[j]) {
                swap(D[i], D[j]);
                swap(P[i], P[j]); // 距离交换时，价格必须跟着交换
            }
        }
    }

    // --- 步骤 2：无解判定 ---
    // 如果任何两个站点之间的间距超过了满油最远距离，绝对跑不到终点
    for (int i = 1; i <= N + 1; i++) {
        if (D[i] - D[i - 1] > longest) {
            cout << "No Solution" << endl;
            return 0;
        }
    }

    double consume = 0; // 累计总花费

    // --- 步骤 3：模拟旅行（贪心控制循环） ---
    // 注意：循环体内部手动控制 i 的移动，所以 for 头部不写 i++
    for (int i = 0; i <= N; ) {
        int target = -1; // 用来记录范围内第一个比当前站便宜的加油站索引

        // 在当前能跑到的航程内 (longest) 寻找第一个价格更低的加油站
        for (int j = i + 1; j <= N + 1 && D[j] - D[i] <= longest; j++) {
            if (P[j] < P[i]) {
                target = j;
                break; // 只要找到第一个更便宜的就立刻跳出，因为我们要去那儿换低价油
            }
        }

        if (target != -1) {
            // 情况 A：在范围内找到了更便宜的加油站
            double needDist = D[target] - D[i]; // 到达那里需要的总里程
            if (leftLength < needDist) {
                // 如果当前剩余的油不够跑到 target，就在当前站 i 加一点点
                // 刚好加到能撑到 target 站就行（不用加满，因为 target 那里更便宜）
                consume += (needDist - leftLength) / L * P[i];
                leftLength = 0; // 到达 target 站时，油箱刚好空了
            } else {
                // 如果剩下的油够跑过去，一分钱都不用花，直接耗油
                leftLength -= needDist;
            }
            i = target; // 直接“瞬移”到那个更便宜的加油站
        }
        else {
            // 情况 B：范围内所有的站都比当前站贵
            // 既然当前站最便宜，那就“趁便宜加满”！
            consume += (longest - leftLength) / L * P[i]; // 加满油箱

            // 此时油箱满了，先跑到下一个站 i+1，看有没有转机
            leftLength = longest - (D[i + 1] - D[i]);
            i++; // 步进到下一站
        }
    }

    // 输出结果，保留两位小数
    cout << fixed << setprecision(2) << consume << endl;
    return 0;
}