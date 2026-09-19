#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long x, y;
    int num;
    cin >> x >> y >> num;
    set<int> t;
    set<int> c;
    for (int i = 0; i < num; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        if (temp1 == 0)
            t.insert(temp2);
        else
            c.insert(temp2);
    }
    long long saferow = x - t.size();
    long long safecol = y - c.size();
    cout << saferow * safecol << endl;
}