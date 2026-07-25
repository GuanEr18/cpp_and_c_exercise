#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,count=0;
    cin >> n;
    vector<int> a(n,0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool flag = false;
    for (int i=1;i<n;i++)
    {
        if (a[i]<a[i-1])
        {
            flag = true;
        }
        if (flag && a[i]>a[i-1])
        {
            count++;
            flag = false;
        }
    }
    cout << count << endl;
}