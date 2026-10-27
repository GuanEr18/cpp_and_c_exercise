#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m; 
    vector<int> a;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    int minSum = INT_MAX;
    for(int i = 0; i < n-m+1; i++)
    {
        int temp = 0;
        for(int j = i; j < i+m; j++)
        {
            temp += a[j];
        }
        if(temp < minSum)
        {
            minSum = temp;
        }
    }
    cout << minSum << endl;
}