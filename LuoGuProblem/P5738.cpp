#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m)
    {
        vector<vector<int>> a(n, vector<int>(m));
        vector<double> score(n, 0.);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            int Max = INT_MIN, Min = INT_MAX;
            for (int j = 0; j < m; j++)
            {
                score[i] += a[i][j];
                Max = max(Max, a[i][j]);
                Min = min(Min, a[i][j]);
            }
            score[i] -= Max;
            score[i] -= Min;
            score[i] /= (m - 2);
        }
        double temp = -1;
        for (int i = 0; i < n; i++)
        {
            temp = max(temp, score[i]);
        }
        cout << fixed << setprecision(2) << temp << endl;
    }
}