#include <iostream>
using namespace std;
/**
 * 只通过了测试案例1，2
 */
int main()
{
    int n, a;
    cin >> n;
    for (int i = n; i >= 0; i--)
    {
        cin >> a;
        if (a)
        {
            if (i < n && a > 0)
                cout << '+';
            if (abs(a) > 1 || i == 0)
                cout << a;
            if (a == -1 && i)
                cout << '-';
            if (i > 0)
                cout << 'x';
            if (i > 1)
                cout << '^' << i;
        }
    }
    return 0;
}
