#include <iostream>
using namespace std;
int main()
{
    int n, d, s = 0;
    cin >> n >> d;
    while (d >= 7)
    {
        d -= 7;
        s += 1250;
    }
    while (d > 0)
    {
        if (n!=6 && n!=7)
        {
            s+=250;
        }
        n++;
        if (n > 7)
        {
            n = 1;
        }
        d--;
    }
    cout << s;
}