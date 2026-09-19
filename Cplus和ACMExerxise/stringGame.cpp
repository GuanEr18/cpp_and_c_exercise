#include <iostream>
#include <string>
using namespace std;
/**
 * 只能通过一个测试点
 */
bool jiou(char c)
{
    int n = c - '0';
    if ((n & 1) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    string ans1={}, ans2={};
    for (int i = 1; i < s1.length(); i++)
    {
        if (jiou(s1[i - 1]) == jiou(s1[i]))
        {
            ans1.push_back(max(s1[i], s1[i - 1]));
        }
    }
    for (int i = 1; i < s2.length(); i++)
    {
        if (jiou(s2[i - 1]) == jiou(s2[i]))
        {
            ans2.push_back(max(s2[i], s2[i - 1]));
        }
    }
    if (ans1 == ans2)
    {
        cout << ans1;
    }
    else
    {
        cout << ans1 << endl
             << ans2;
    }
    return 0;
}
