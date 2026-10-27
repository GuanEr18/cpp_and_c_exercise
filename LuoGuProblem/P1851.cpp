#include <iostream>
#include <cmath>
using namespace std;

// 优化：求真约数之和（不包含数字本身）
int sumOfDivisors(int n)
{
    if (n == 1)
        return 0; // 1 的真约数之和为 0
    int sum = 1;  // 1 是所有大于 1 的整数的约数
    int sqrtN = sqrt(n);
    for (int i = 2; i <= sqrtN; ++i)
    {
        if (n % i == 0)
        {
            sum += i;
            if (i != n / i)
            { // 避免完全平方数重复添加
                sum += n / i;
            }
        }
    }
    return sum;
}
pair<int, int> solve(int n)
{
    int a = n;
    while (true)
    {
        int b = sumOfDivisors(a);
        if (a!=b && sumOfDivisors(b) == a)
        {
            return make_pair(a, b);
        }
        a++;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int s;
    cin >> s;
    cout << solve(s).first << " " << solve(s).second << endl;
}