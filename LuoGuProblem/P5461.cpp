#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
void change(vector<vector<int>> &a, int range, int x, int y)
{
    if (range <= 1)
        return;

    int half = range / 2;
    for (int i = x; i < x + half; i++)
    {
        for (int j = y; j < y + half; j++)
        {
            a[i][j] = 0;
        }
    }

    change(a, half, x, y);
    change(a, half, x + half, y);
    change(a, half, x, y + half);
    change(a, half, x + half, y + half);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<vector<int>> a((1 << n), vector<int>((1 << n), 1));
    change(a, 1 << n, 0, 0);
    for (int i = 0; i < 1 << n; i++)
    {
        for (int j = 0; j < 1 << n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}