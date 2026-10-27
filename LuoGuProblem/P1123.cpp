#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Node
{
    int number, time;
};
Node nodes[1005];
int main()
{
    int n;
    cin >> n;
    double sumWaitTime = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nodes[i].time;
        nodes[i].number = i + 1;
    }
    sort(nodes, nodes + n, [](Node a, Node b)
         { return a.time < b.time; });
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            sumWaitTime += nodes[j].time;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << nodes[i].number << " ";
    }
    cout << endl;
    cout << fixed << setprecision(2) << sumWaitTime / n << endl;
    return 0;
}