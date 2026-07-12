//
// Created by Zheng on 2026/3/11.
//
#include <iostream>
#include <vector>
using namespace std;
void snake(int n) {
    if (n <= 0) return;
    // 定义 n x n 矩阵，初始化为 0
    vector<vector<int>> a(n, vector<int>(n));
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int num = 1;
    int total = n * n;
    while (num <= total) {
        // 1. 【最右列】从上到下 (Top -> Bottom)
        // 列固定为 right，行 i 从 top 变到 bottom
        for (int i = top; i <= bottom && num <= total; i++) {
            a[i][right] = num++;
        }
        right--; // 右边界向左收缩
        // 2. 【最下行】从右到左 (Right -> Left)
        // 行固定为 bottom，列 i 从 right 变到 left (注意是递减)
        for (int i = right; i >= left && num <= total; i--) {
            a[bottom][i] = num++;
        }
        bottom--; // 下边界向上收缩
        // 3. 【最左列】从下到上 (Bottom -> Top)
        // 列固定为 left，行 i 从 bottom 变到 top (注意是递减)
        for (int i = bottom; i >= top && num <= total; i--) {
            a[i][left] = num++;
        }
        left++; // 左边界向右收缩
        // 4. 【最上行】从左到右 (Left -> Right)
        // 行固定为 top，列 i 从 left 变到 right
        for (int i = left; i <= right && num <= total; i++) {
            a[top][i] = num++;
        }
        top++; // 上边界向下收缩
    }
    // 输出结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " \t"; // 使用制表符对齐
        }
        cout << endl;
    }
}
int main() {
    int n;
    while (cin >> n) {
        snake(n);
    }
    return 0;
}