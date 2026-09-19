#include <iostream>
using namespace std;

// 快速幂
int quick_pow(int a, int b, int p)
{
    // int ans = 1;
    // while (b) {
    //     if (b & 1) {
    //         ans = (long long)ans * a % p;
    //     }
    //     a = (long long)a * a % p;
    //     b >>= 1;
    // }
    // return ans;
    long long base = a;
    long long ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * base % p;
        }
        b >>= 1;
        base = base * base % p;
    }
    return ans % p;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, p;
    cin >> a >> b >> p;
    int ans = quick_pow(a, b, p);
    cout << a << "^" << b << " mod " << p << "=" << ans << endl;
    return 0;
}