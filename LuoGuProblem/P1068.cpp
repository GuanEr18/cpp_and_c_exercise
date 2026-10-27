#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct com
{
    int number;
    int score;
};

int n, m;
int main()
{
    while (cin >> n >> m)
    {
        vector<com> a;
        a.reserve(n);
        com temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp.number >> temp.score;
            a.push_back(temp);
        }
        int schedule = m * 3 / 2;
        sort(a.begin(), a.end(), [](const com &x, const com &y)
             {
            if (x.score != y.score) return x.score > y.score;
            return x.number < y.number; });
        int cutoff = a[schedule - 1].score;
        int actual = schedule;
        while (actual < n && a[actual].score == cutoff)
        {
            actual++;
        }
        cout << cutoff << " " << actual << endl;
        for (int i = 0; i < actual; i++)
        { // ← 用 actual 替代 schedule
            cout << a[i].number << " " << a[i].score << endl;
        }
    }
}