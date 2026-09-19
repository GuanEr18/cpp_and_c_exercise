#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int n, m, smax;
    cin >> n >> m >> smax;
    string track[n + 1];
    int pos[n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        cin >> track[i];
    }
    stack<char> b;
    int op;
    while (cin >> op && op != -1)
    {
        if (op == 0)
        {
            if (!b.empty())
            {
                cout << b.top();
                b.pop();
            }
        }
        else
        {
            if (pos[op] >= m)
                continue;
            if ((int)b.size() >= smax)
            {
                cout << b.top();
                b.pop();
            }
            b.push(track[op][pos[op]]);
            pos[op]++;
        }
    }
    return 0;
}