#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) { 
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    int cnt[26] = {0};
    for (char c : s) {
        cnt[c - 'a']++;
    }
    int maxn = 0, minn = 105;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0) {
            maxn = max(maxn, cnt[i]);
            minn = min(minn, cnt[i]);
        }
    }
    int diff = maxn - minn;
    if (isPrime(diff)) {
        cout << "Lucky Word" << endl;
        cout << diff << endl;
    } else {
        cout << "No Answer" << endl;
        cout << 0 << endl;
    }
    
    return 0;
}