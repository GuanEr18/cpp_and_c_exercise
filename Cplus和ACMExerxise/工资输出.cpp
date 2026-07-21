//
// Created by Zheng on 2026/3/11.
//
#include <iomanip>
#include <iostream>
#include <vector>//动态分配内存，能让数组长度位置的题目通过
using namespace std;
int main(void) {
    int T, N;
    double S;
    while (cin >> T && T != 0) {  // T=0时结束
        vector<double> expenses(T);
        double totalSum = 0.0;
        for (int i = 0; i < T; i++) {
            cin >> N >> S;
            expenses[i] = N * S;  // 计算每个企业的总支出
        }
        for (int i = 0; i < T; i++) {
            totalSum += expenses[i];
            cout << fixed << setprecision(2) << i + 1 << ": " << expenses[i] << endl;
        }
        cout << fixed << setprecision(2) << totalSum / T << endl;
    }
    return 0;
}