//
// Created by Zheng on 2026/6/1.
//
#include <iostream>
using namespace std;
bool isPerfect(int x) {
    int sum=0;
    // 只需要遍历到 x/2 即可，因为大于 x/2 的数不可能是 x 的真因数
    for (int i=1;i<=x/2;i++) {
        if (x%i==0) {
            sum+=i;
        }
    }
    return sum==x;
}

int main() {
    int n;
    if (cin >> n) {
        for (int i = 2; i <= n; i++) {
            if (isPerfect(i)) {
                cout << i << endl;
            }
        }
    }
    return 0;
}