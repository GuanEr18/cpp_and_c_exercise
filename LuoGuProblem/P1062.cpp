#include <iostream>
using namespace std;

long long quick_pow(long long a, long long b)
{
    long long base = 1;
    long long ans = 0;
    while (b)
    {
        if (b & 1)
        {
            ans += base;
        }
        b >>= 1;
        base = base * a;
    }
    return ans;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    long long x, m;
    cin >> x >> m;
    cout << quick_pow(x, m) << endl;
}