#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // 不开long long 会有一个测试点不通过
    long long n, c, count = 0;
    cin >> n >> c;
    vector<long long> x(n, -1);
    for (long long i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    int r1 = 0, r2 = 0;
    for (int i = 0; i < n; i++)
    {
        /**
         *
        指针 r1：寻找第一个使 x[r1] - x[i] > c 的位置。也就是说，在 r1 之前的所有元素，都满足 x[j] - x[i] <= c。

        指针 r2：寻找第一个使 x[r2] - x[i] >= c 的位置。也就是说，在 r2 之前的所有元素，都满足 x[j] - x[i] < c。

        通过这两个指针的夹逼，所有满足 x[j] - x[i] == c 的元素刚好落在了区间 [r2, r1 - 1] 内。
         */
        while (r1 < n && x[r1] - x[i] <= c)
            r1++;
        while (r2 < n && x[r2] - x[i] < c)
            r2++;
        if (c==0)
            count += r1 - r2 - 1;
        else
            count += r1 - r2;
    }
    cout << count << endl;
}