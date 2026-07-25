#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n)
    {
        vector<vector<int>> a(n, vector<int>(4, 0));
        for (int i = 0; i < n; i++)
        {
            cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
        }
        // 地图
        // int rowMax = 0, colMax = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     int row = a[i][0] + a[i][2];
        //     int col = a[i][1] + a[i][3];
        //     if (row > rowMax)
        //         rowMax = row;
        //     if (col > colMax)
        //         colMax = col;
        // }
        // // 填入地图
        // int matrix[rowMax][colMax] = {-1};
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = a[i][0]; j < a[i][0] + a[i][2]; j++)
        //     {
        //         for (int k = a[i][1]; k < a[i][1] + a[i][3]; k++)
        //         {
        //             matrix[j][k] = i + 1;
        //         }
        //     }
        // }
        //
        int x, y;
        cin >> x >> y;
        // if (x < 0 || x >= rowMax || y < 0 || y >= colMax)
        // {
        //     cout << "-1" << endl;
        // }
        // else
        // {
        //     cout << matrix[x][y] << endl;
        // }
        /**
         * cover判断来省内存
         */
        int cover = -1;
        for (int i = 0; i < n; i++)
        {
            if (x<a[i][0]+a[i][2] && x>=a[i][0] && y<a[i][1]+a[i][3] && y>=a[i][1])
            {
                cover = i + 1;
            }
        }
        cout << cover << endl;
    }
    return 0;
}