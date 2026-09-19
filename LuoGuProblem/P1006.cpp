#include <iostream>
#include <vector>
using namespace std;

int m, n;

int dp(const vector<vector<int>> &a, int x, int y, vector<vector<bool>> &act)
{
    if (x == 1 && y == 1 && act[1][1])
    {
        act[1][1] = false;
        return a[1][1];
    }
    if (x == 1 && act[x][y - 1])
    {
        act[x][y - 1] = false;
        return dp(a, x, y - 1, act) + a[x][y];
    }
    if (y == 1 && act[x - 1][y])
    {
        act[x - 1][y] = false;
        return dp(a, x - 1, y, act) + a[x][y];
    }
    int go = max(dp(a, x - 1, y, act), dp(a, x, y - 1, act)) + a[x][y];
    int back = max(dp(a, x - 1, y, act), dp(a, x, y - 1, act)) + a[x][y];
    return go + back;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    vector<vector<int>> a(m + 1, vector<int>(n + 1, 0));
    vector<vector<bool>> act(m + 1, vector<bool>(n + 1, true));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    a[1][1] = 0;
    a[m][n] = 0;
    cout << dp(a, m, n, act) << endl;
}