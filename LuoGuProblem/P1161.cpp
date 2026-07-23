#include <iostream>
using namespace std;

struct function
{
    double a;
    int t;
};
int main()
{
    int n;
    cin >> n;
    function f[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i].a >> f[i].t;
    }
    double maxA = 0;
    for (int i = 1; i <= n; i++)
    {
        if (f[i].a > maxA)
        {
            maxA = f[i].a;
        }
    }
    int maxT = 0;
    for (int i = 1; i <= n; i++)
    {
        if (f[i].t > maxT)
        {
            maxT = f[i].t;
        }
    }
    bool flag[int(maxA * maxT) + 2] = {false};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= f[i].t; j++)
        {
            flag[int(f[i].a * j)] ^= 1;
        }
    }
    for (int i = 1; i <= int(maxA * maxT) + 1; i++)
    {
        if (flag[i] == true)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}

// P1161.cpp
// 部分改进
// bool flag[n] = {false};这个在部分原生编译器中会报错
// 而且mian方法中的引用变量是存在栈中，会爆内存
// 声明成全局变量就会变成静态变量，不会爆内存

// 以下是改进版
#include <iostream>
using namespace std;

struct function
{
    double a;
    int t;
};
bool flag[3000001] = {false};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    function f[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i].a >> f[i].t;
    }
    // 反转
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= f[i].t; j++)
        {
            flag[int(f[i].a * j)] ^= 1;
            // int pos = int(f[i].a * j + 1e-6);
            // 注释中的代码不符合题目要求的直接取整数部分
        }
    }
    for (int i = 1; i <= 3000000; i++)
    {
        if (flag[i] == true)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}