//
// Created by Zheng on 2026/5/22.
//
#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> a;
vector<int> b;
vector<int> c;
vector<vector<int>> pos; // pos[i] 存放所有当前处于第 i 级的课程编号

void noneName() {
    vector<int> answer;
    while (true) {
        bool flag = false;
        // 寻找目前最高的有课的等级 (从 k 到 1)
        for (int i = k; i > 0; i--) {
            // 第 i 级有课，且下一级 i+1 还没超过容量限制
            if (c[i] > 0 && c[i + 1] < a[i + 1] && !pos[i].empty()) {
                int id = pos[i].back();
                pos[i].pop_back();
                b[id]++;
                c[i]--;
                c[i + 1]++;
                pos[i + 1].push_back(id); // 塞进新等级的桶里
                answer.push_back(id);
                flag = true;
                break; // 开启下一轮检查
            }
        }
        if (!flag) break; // 所有课都无法再晋升了
    }
    // 输出结果
    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << "\n";
}
int main() {
    // 提升输入输出效率
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            cin >> n >> k;
            // 使用 assign 确保每组测试数据进来时都彻底清空、重新分配
            a.assign(k + 5, 0);
            c.assign(k + 5, 0);
            pos.assign(k + 5, vector<int>());
            b.assign(n + 5, 0);
            // 1. 读入 1 到 k 级的容量限制
            for (int i = 1; i <= k; i++) {
                cin >> a[i];
            }
            a[k + 1] = n + 1; // 级别 k+1 没有容量限制，设为无限大
            // 2. 读入 1 到 n 节课的初始状态（注意条件是 i <= n）
            for (int i = 1; i <= n; i++) {
                cin >> b[i];
                c[b[i]]++;
                pos[b[i]].push_back(i); // 把课程 i 放入它初始级别的桶中
            }
            noneName();
        }
    }
    return 0;
}