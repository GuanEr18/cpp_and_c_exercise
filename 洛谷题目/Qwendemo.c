//
// Created by Zheng on 2026/3/22.
//
#include <stdio.h>
#include <string.h>
#define MAX_LEN 200
// 高精度数组，每一位存储一个数字
int factorial[MAX_LEN];
int sum_result[MAX_LEN];
// 高精度乘法：factorial = factorial * num
void multiply(int num) {
    int carry = 0;
    for (int i = 0; i < MAX_LEN; i++) {
        long long temp = (long long)factorial[i] * num + carry;
        factorial[i] = temp % 10;
        carry = temp / 10;
    }
}
// 高精度加法：sum_result = sum_result + factorial
void add() {
    int carry = 0;
    for (int i = 0; i < MAX_LEN; i++) {
        int temp = sum_result[i] + factorial[i] + carry;
        sum_result[i] = temp % 10;
        carry = temp / 10;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    // 初始化数组
    memset(factorial, 0, sizeof(factorial));
    memset(sum_result, 0, sizeof(sum_result));
    // 0! = 1
    factorial[0] = 1;
    // 计算 1! + 2! + ... + n!
    for (int i = 1; i <= n; i++) {
        multiply(i);  // 计算 i!
        add();        // 累加到总和
    }
    // 找到最高有效位并输出
    int start = MAX_LEN - 1;
    while (start >= 0 && sum_result[start] == 0) {
        start--;
    }
    if (start < 0) {
        printf("0\n");
    } else {
        for (int i = start; i >= 0; i--) {
            printf("%d", sum_result[i]);
        }
        printf("\n");
    }
    return 0;
}