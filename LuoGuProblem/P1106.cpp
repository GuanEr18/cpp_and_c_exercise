#include <iostream>
#include <string>
using namespace std;
/**
 * 这种题目必须用单调栈 考虑子序列方法是有局限性的
 */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    int remove;
    cin >> n >> remove;
    string stk;
    for (char c : n)
    {
        while (remove > 0 && !stk.empty() && stk.back() > c)
        {
            stk.pop_back();
            remove--;
        }
        stk.push_back(c);
    }
    stk.resize(stk.size() - remove);
    int start = 0;
    while (start < stk.size() && stk[start] == '0')
        start++;
    if (start == stk.size())
    {
        cout << "0";
    }
    else
    {
        cout << stk.substr(start);
    }
    cout << endl;
    return 0;
}