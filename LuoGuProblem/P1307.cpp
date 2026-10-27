#include <iostream>
using namespace std;
int main()
{
    int n,target,bit;
    cin >> n;
    if(n>=0)
    {
        target = 0;
        while(n)
        {
            bit = n%10;
            n /= 10;
            target = target*10 + bit;
        }
    }
    else
    {
        target = 0;
        n = -n;
        while(n)
        {
            bit = n%10;
            n /= 10;
            target = target*10 + bit;
        }
        target = -target;
    }
    cout << target << endl;
    return 0;
}