//
// Created by Zheng on 2026/3/10.
//
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double PI = 3.14159265358979323846;

double jisuan(double e, double x) {
    double m = 1.0;       // cos(x) 的第 0 项是 1
    double term = 1.0;    // 当前项的值 (term)，初始为第 0 项
    int n = 1;            // 从第 1 项开始 (对应 x^2 / 2!)
    while (true) {
        //加上括号，确保分母是 (2n-1) * 2n
        // 递推公式：新项 = 旧项 * (-x^2) / ((2n-1) * 2n)
        double factor = -x * x / ((2 * n - 1) * (2 * n));
        term = term * factor; // 计算当前第 n 项的值
        if (fabs(term) < e) {
            break;
        }
        m += term; // 累加到结果
        n++;       // 准备计算下一项
    }
    return m;
}

int main() {
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    double e, x, result;
    while (cin >> x >> e) {
        // 处理角度范围
        while (x >= 360.0) x -= 360.0;
        while (x < 0.0) x += 360.0;
        //角度转弧度
        x = x * PI / 180.0;
        result = jisuan(e, x);
        cout << fixed << setprecision(8) << result << endl;
    }
    return 0;
}