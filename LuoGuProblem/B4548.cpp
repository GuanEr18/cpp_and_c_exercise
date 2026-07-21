//
// Created by Zheng on 2026/7/19.
//
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int main()
{
    while (cin >> n >> m)
    {
        vector<vector<int>> a(n, vector<int>(2, 0));
        for (int i = 0; i < n; i++)
        {
            cin >> a[i][0];
        }
        int temp, s;
        for (int i = 0; i < m; i++)
        {
            cin >> temp >> s;
            for (int j = 0; j < s; j++)
            {
                if (a[j][0] == temp)
                {
                    a[j][1] = s;
                    break;
                }
            }
        }
        int count1 = 0, count2 = 0;
        for (int i = 0; i < n; i++)
        {

            if (a[i][1] == 0)
            {
                count1++;
            }
            else if (a[i][1] < 60)
            {
                count2++;
            }
        }
        cout << count1 << " " << count2 << endl;
    }
    return 0;
}