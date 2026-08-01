#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < i; j++) {
                if (a[j] < a[i]) {
                    count++;
                }
            }
            cout << count << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}