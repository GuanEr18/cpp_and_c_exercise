#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addStrings(string num1, string num2)
{
    string result;
    int i = num1.size() - 1; // 指向 num1 的末尾
    int j = num2.size() - 1; // 指向 num2 的末尾
    int carry = 0;
    while (i >= 0 || j >= 0 || carry > 0)
    {
        int sum = carry;
        if (i >= 0)
            sum += num1[i--] - '0';
        if (j >= 0)
            sum += num2[j--] - '0';
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0 || n == 1)
        {
            cout << "1" << endl;
            continue;
        }
        string prev2 = "1"; // 代表 f[i-2]
        string prev1 = "1"; // 代表 f[i-1]
        string current;
        for (int i = 2; i <= n; ++i)
        {
            current = addStrings(prev1, prev2);
            prev2 = prev1;
            prev1 = current;
        }
        cout << current << endl;
    }
    return 0;
}