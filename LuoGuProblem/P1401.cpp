#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    long long a1,a2,b1,b2;
    cin >> a1 >> a2 >> b1 >> b2;
    long long p1 = a1 * b1;
    long long p2 = a1 * b2;
    long long p3 = a2 * b1;
    long long p4 = a2 * b2;

    // 找出这 4 个结果中的最大值和最小值
    long long min_val = min({p1, p2, p3, p4});
    long long max_val = max({p1, p2, p3, p4});

    // 判断是否越界（低于 int 最小值 或 高于 int 最大值）
    if (min_val < INT_MIN || max_val > INT_MAX) {
        cout << "long long int" << endl;
    } else {
        cout << "int" << endl;
    }
}