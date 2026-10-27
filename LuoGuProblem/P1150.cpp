#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int smoke = n;
    while (n>=k)
    {
        n-=k-1;
        smoke++;

    }
    cout << smoke << endl;
    return 0;
}