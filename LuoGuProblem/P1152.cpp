#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> b(n,0);
    for (int i = 0; i < n-1; i++)
    {
        b[i]=i+1;
    }
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int temp = abs(a[i] - a[i - 1]);
        for (int j = 0;j < b.size(); j++)
        {
            if (b[j] == temp)
            {
                b[j] = b.back();// 用最后一个元素覆盖当前元素
                b.pop_back();// 删除最后一个元素
            }
        }
    }
    if (b.size() == 1)
    {
        cout << "Jolly" << endl;
    }
    else
    {
        cout << "Not jolly"<<endl;
    }
    return 0;
}