#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int m = n * n;
    vector<int> a;
    while (m)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
        m -= temp;
    }
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i]; j++)
        {
            count++;
            if (i % 2 == 0)
            {
                cout << "0";
            }
            else
            {
                cout << "1";
            }
            if (count % n == 0)
            {
                cout << endl;
            }
        }
    }
    return 0;
}