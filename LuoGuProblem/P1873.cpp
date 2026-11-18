// P1873 洛谷
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long m;
vector<long long> a;
bool check(long long h) {
    long long sum = 0;
    for(long long x : a) {
        if (x > h) {
            sum += x - h;
            if(sum >= m) {
                return true;
            }
        }
    }
    return false;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    a.reserve(n);
    long long mx = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        a.push_back(x);
        mx = max(mx, x);
    }
    long long left = 0, right = mx, ans = 0;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (check(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
