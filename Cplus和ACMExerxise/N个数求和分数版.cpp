//
// Created by Zheng on 2026/4/11.
//
// #include <algorithm>
// #include <iostream>
// #include <vector>
// using namespace std;
// int gcd () {
//
// }
// int lcm () {
//
// }
// int main () {
//     int n;
//     while (cin >> n) {
//         vector<int>a(n);
//         vector<int>b(n);
//         char c;
//         for (int i = 0; i < n; i++) {
//             cin >> a[i]>>c>>b[i];
//         }
//     }
// }
#include <iostream>
#include <cmath>
using namespace std;
// 定义长整型别名，防止数据溢出
typedef long long ll;
// 使用辗转相除法求最大公约数
ll gcd(ll a, ll b) {
    // 传入的 a, b 必须是正数，所以调用前取绝对值
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    int n;
    cin >> n;
    ll nume = 0, deno = 1; // 初始化总和的分子为0，分母为1
    char ch;               // 用于接收输入中的 '/' 字符
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> ch >> b; // 按照 "a/b" 的格式读取
        if (i == 0) {
            // 第一个数直接赋值
            nume = a;
            deno = b;
        } else {
            // 交叉相乘进行通分相加: nume/deno + a/b = (nume*b + a*deno) / (deno*b)
            nume = nume * b + a * deno;
            deno = deno * b;
            // 每次相加后立即约分，防止数值过大导致溢出
            ll g = gcd(abs(nume), abs(deno));
            nume /= g;
            deno /= g;
        }
    }
    // 保证分母为正数，若分母为负，则将负号移至分子
    if (deno < 0) {
        deno = -deno;
        nume = -nume;
    }
    // 提取整数部分和剩余的分子
    ll integer_part = nume / deno;
    ll fraction_nume = abs(nume % deno); // 分数部分的分子必须为正数
    // 根据不同的情况格式化输出
    if (integer_part == 0 && fraction_nume == 0) {
        // 结果为 0
        cout << 0;
    } else if (integer_part != 0 && fraction_nume == 0) {
        // 只有整数部分
        cout << integer_part;
    } else if (integer_part == 0 && fraction_nume != 0) {
        // 只有分数部分（注意：如果原数为负，负号应在分子前面）
        if (nume < 0) cout << "-";
        cout << fraction_nume << "/" << deno;
    } else {
        // 既有整数部分，又有分数部分
        cout << integer_part << " " << fraction_nume << "/" << deno;
    }
    return 0;
}