#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int> > a;
int main ()
{
    string s;
    while (getline(cin,s) && !s.empty())
    {
        vector<int> v;
        for (char ch : s)
        {
            v.push_back(ch-'0');
        }
        a.push_back(v);
    }
    int rows = a.size();
    int val = 0,count=0;
    vector<int> b;
    b.push_back(rows);
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            if (a[i][j]==val)
            {
                count++;
            }
            else
            {
                b.push_back(count);
                count = 1;
                val = a[i][j];
            }
        }
    }
    b.push_back(count);
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}