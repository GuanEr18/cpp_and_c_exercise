#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long water = 0, juice = 0, temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        water += temp;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        juice += temp;
    }
    cout << fixed << setprecision(6) << double(juice) / double(water) << endl;
}