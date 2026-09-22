#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n))
        return 0;
    vector<int> teams(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> teams[i];
    }
    vector<vector<int>> schoolseats(n);
    for (int i = 0; i < n; ++i)
    {
        schoolseats[i].resize(teams[i] * 10);
    }
    vector<int> assignedcount(n, 0);
    int current = 1;
    int remainschools = n;
    while (remainschools > 0)
    {
        for (int i = 0; i < n; ++i)
        {
            if (assignedcount[i] < teams[i] * 10)
            {
                schoolseats[i][assignedcount[i]] = current;
                assignedcount[i]++;
                if (assignedcount[i] == teams[i] * 10)
                {
                    remainschools--;
                }
                if (remainschools == 0)
                {
                    break;
                }
                // if (remainingschools != 0 && assignedcount[i] < teams[i] * 10)
                // {
                //     current += (n + 1 - remainingschools);
                // }
                if (remainschools == 1 && assignedcount[i] < teams[i] * 10)
                {
                    current += 2;
                }
                else
                {
                    current += 1;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << "#" << (i + 1) << "\n";
        for (int j = 0; j < teams[i] * 10; ++j)
        {
            cout << schoolseats[i][j];
            if ((j + 1) % 10 != 0)
            {
                cout << " ";
            }
            else
            {
                cout << "\n";
            }
        }
    }
    return 0;
}