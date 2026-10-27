#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count = 1, countMax = 0;
    for (int i = 0; i <= n-2; i++)
    {
        if (a[i] + 1 == a[i + 1])
        {
            count++;
            
        }
        else
        {
            countMax = max(countMax, count);
            count = 1;
        }
    }
    countMax = max(countMax, count);
    cout << countMax << endl;
    return 0;
}