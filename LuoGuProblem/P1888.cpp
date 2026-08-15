#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int min_val = min(a, min(b, c));
    int max_val = max(a, max(b, c));
    int g = gcd(min_val, max_val);
    cout << min_val / g << "/" << max_val / g << endl;
    return 0;
}