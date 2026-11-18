#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
int a[MAXN];
int n, k;
// check: 长度为 len 时能否切出至少 k 段
bool check(int len) {
    if (len == 0) return true; // 防止除零
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += a[i] / len;
    }
    return cnt >= k;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    int maxVal = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxVal = max(maxVal, a[i]);
    }
    // 二分答案：l 是可行解，r 是不可行解
    int l = 0, r = maxVal + 1;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            l = mid;   // mid 可行，尝试更大的长度
        } else {
            r = mid;   // mid 不可行，缩短长度
        }
    }
    cout << l << endl;
    return 0;
}
