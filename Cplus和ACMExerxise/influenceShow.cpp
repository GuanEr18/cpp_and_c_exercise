//
// Created by Zheng on 2026/9/22.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int x, y;

void sultion(const vector<vector<long long>> &power)
{
    vector<vector<long long>> cost(x, vector<long long>(y, 0));
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {

            for (int k = 0; k < x; k++)
            {
                for (int l = 0; l < y; l++)
                {
                    int length = max(abs(i - k), abs(j - l));
                    cost[i][j] += power[i][j] * length;
                }
            }
        }
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    while (cin >> x >> y)
    {
        vector<vector<long long>> v(x, vector<long long>(y, 0));
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                cin >> v[i][j];
            }
        }
        sultion(v);
    }
}
