#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, average = 0;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        average += k;
        a[i] = k;
    }
    average /= n;
    int step = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == average) continue;
        else 
        {
            int diff = a[i] - average;
            a[i + 1] += diff;
            step++;
        }
    }
    cout << step << endl;
}
/**
 * 贪心算法是得出局部最优解后得出总体最优解。得到题目用了这个算法是因为题目要求一次只能移动一格，所以最后一步永远是填平之前留下的差值。这个点对应无后效性
 */