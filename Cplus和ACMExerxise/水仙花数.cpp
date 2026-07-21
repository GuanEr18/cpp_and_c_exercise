//
// Created by Zheng on 2026/3/15.
//
#include <iostream>
using namespace std;
long long mypow(int base, int exp) {
    long long res = 1; // 结果初始化为 1
    for (int i = 0; i < exp; i++) {
        res *= base;   // 每次乘以底数，而不是自乘
    }
    return res;
}
int main() {
    int n; // 位数通常是 int 就够了
    while (std::cin >> n) {
        if (n <= 0) continue;
        // 计算边界
        // 注意：mypow 返回 long long，接收变量也要用 long long 防止溢出
        long long start = (n == 1) ? 0 : mypow(10, n - 1);
        long long end = mypow(10, n) - 1;
        // 如果起始值已经超出 int 范围（虽然题目通常测小数据），循环变量 i 必须是 long long
        for (long long i = start; i <= end; i++) {
            long long c = 0;
            long long k = i;
            while (k > 0) {
                int temp = k % 10;
                k /= 10;
                // 调用修正后的函数
                c += mypow(temp, n);
            }
            // 特殊处理：当 n=1 时，0 也是水仙花数 (0^1 = 0)
            // 上面的 while(k>0) 对于 i=0 不会执行，c=0，i=0，条件成立，逻辑自然覆盖
            if (i == c) {
                cout << i << endl;
            }
        }
    }
    return 0;
}