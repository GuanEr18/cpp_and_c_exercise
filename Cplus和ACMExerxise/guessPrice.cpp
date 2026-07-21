//
// Created by Zheng on 2026/6/9.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int case_num = 1;
    while (true) {
        // 安全读取 N，如果遇到文件结束符(EOF)则退出
        if (!(cin >> n)) break;
        if (n == 0) break;
        vector<int> prices(n);
        for (int i = 0; i < n; ++i) {
            cin >> prices[i];
        }
        sort(prices.begin(), prices.end());
        int xiao_ming_score = 0;
        int store_score = 0;
        int guess;
        for (int i = 0; i < 5; ++i) {
            // 正常读取每一次猜测
            if (!(cin >> guess)) break;
            auto it = lower_bound(prices.begin(), prices.end(), guess);
            if (it != prices.end() && *it == guess) {
                xiao_ming_score++;
                prices.erase(it);
            } else {
                store_score++;
            }
            if (xiao_ming_score == 2 || store_score == 2) {
                break;
            }
        }
        cout << "CASE #" << case_num << "\n";
        if (xiao_ming_score > store_score) {
            cout << "Xiaoming win!\n";
        } else {
            cout << "Store win!\n";
        }
        case_num++;
    }
    return 0;
}