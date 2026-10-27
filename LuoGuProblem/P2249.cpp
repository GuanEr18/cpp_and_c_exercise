#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    while (m--)
    {
        int q;
        cin >> q;
        int left = 0, right = n - 1, ans = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            // if (a[mid] == q)
            // {
            //     while (mid > 0 && a[mid - 1] == q)
            //     {
            //         mid--;
            //     }
            //     ans = mid + 1;
            //     break;
            // }
            /**
             * 上面的代码在遇到重复值的时候会退化导致超时
             */
            if (a[mid] == q) {
                ans = mid + 1;   // 记录当前合法答案（1-indexed）
                right = mid - 1; // ✅ 关键：不break，继续向左搜索第一个出现位置
            }
            else if (a[mid] < q)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}