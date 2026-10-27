// #include <iostream>
// #include <map>
// #include <climits>
// using namespace std;
// int main () {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n;
//     while (cin >> n) {
//         map<int, int> a;
//         for (int i = 0; i < n; ++i) {
//             int temp;
//             cin >> temp;
//             // X值出现的频率
//             a[temp]++;
//         }
//         int ans = INT_MAX;
//         while (!a.empty()) {
//             auto it1 = a.begin();
//             auto it2 = a.begin();
//             // 对当前位置的值-1
//             --((*it1).second);
//             int length = 1;
//             ++it2;
//             // .first表示当前键值（地址位）这里规定+1代表尝试选取的长度要加 1 .second表示如果下一项的人数更多那就可以选上增加长度
//             for (; it2 != a.end() && (*it2).first == (*it1).first + 1 && (*it2).second > (*it1).second;++it1,++it2) {
//                 length++;
//                 --((*it2).second);
//             }
//             // 删掉 0 的项
//             it1 = a.begin();
//             while (it1!=a.end()) {
//                 if ((*it1).second==0)
//                 // 删掉it1项数值之后就会返回下一项的地址值
//                     it1 = a.erase(it1);
//                 else
//                 // 没有执行删除才能手动向后移一位
//                     it1++;
//             }
//             if (length<ans) {
//                 ans = length;
//             }
//         }
//         cout << ans << endl;
//     }
// }

/**
 * 上面是原先的代码，最后一个测试点会超时
 */

#include <iostream>
#include <map>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n)
    {
        vector<int> x(n);
        // a[x] 代表以x为结尾的所有组的长度，小根堆维护最短组
        map<int, priority_queue<int, vector<int>, greater<int>>> a;
        for (int i = 0; i < n; ++i)
        {
            int temp;
            cin >> temp;
            x[i] = temp;
        }
        sort(x.begin(), x.end());
        for (int i : x)
        {
            // 如果第i-1的数组不存在，就会自动创建，其中的value为空
            // 然后检查这个堆是不是空的
            if (!a[i - 1].empty())  // 第一次访问一定是空的，走else
            {
                int len = a[i - 1].top();
                a[i - 1].pop();
                a[i].push(len + 1);
            }
            else
                a[i].push(1);
        }

        int ans = INT_MAX;
        for (auto &[key, pq] : a)
        {
            while (!pq.empty())
            {
                ans = min(ans, pq.top());
                pq.pop();
            }
        }
        cout << ans << endl;
    }
}
