#include <iostream>
#include <vector>
#include <set>
using namespace std;

int mex(const vector<int> &a, int l, int r)
{
    set<int> s(a.begin() + l, a.begin() + r + 1);
    for (int i = 0;; ++i)
    {
        if (!s.count(i))
            return i;
    }
    return -1;
}
int cmin(const vector<int> &a, int l, int r)
{
    int cmin = a[0];
    for (int i = 0; i < l; i++)
    {
        if (a[i] < cmin)
            cmin = a[i];
    }
    for (int i = r + 1; i < a.size(); i++)
    {
        if (a[i] < cmin)
            cmin = a[i];
    }
    return cmin;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count = 0;
    for (int l = 0; l < n; l++)
    {
        for (int r = l; r < n; r++)
        {
            if (mex(a, l, r) == cmin(a, l, r)) count++;
        }
    }
    cout << count << endl;
    return 0;
}
