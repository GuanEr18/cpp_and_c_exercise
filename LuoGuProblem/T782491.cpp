#include <iostream>
#include <vector>
using namespace std;

int operate (vector<vector<int>> B,vector<vector<int>> A)
{
    int count = 0;
    for (int i = 0; i < A[0].size(); i++)
    {
        if (A[0][i] != A[0][i+1])
        {
            return -1;
            break;
        }
    }

    /**
     * operate 1 : 从0~R队列中最大的数值
     */

    
    /**
     * operate 2 : 从0~C列中最大的数值
     */

}
int main ()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> R(n);
        for (int i = 0; i < n; i++)
        {
            cin >> R[i];
        }
        vector<int> C(m);
        for (int i = 0; i < m; i++)
        {
            cin >> C[i];
        }
        vector<vector<int>> A(n, vector<int>(m,0));
        vector<vector<int>> B(n, vector<int>(m,0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                A[i][j] = R[i] + C[j];
            }
        }

    }
    
}