#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

string tran(const vector<char> &in)
{
    string result = "";
    for (char c : in)
    {
        long long val = 0;
        if (c >= '0' && c <= '9')
        {
            val = c - '0';
        }
        else if (c >= 'A' && c <= 'Z')
        {
            val = c - 'A' + 10;
        }
        string subs = "";
        for (int i = 3; i >= 0; --i)
        {
            subs += ((val >> i) & 1) ? '1' : '0';
        }
        result += subs;
    }
    //
    size_t pos = result.find_first_not_of('0');
    if (pos != std::string::npos)
    {
        return result.substr(pos);
    }
    return "0";
}

int main()
{
    int n;
    cin >> n;
    vector<char> s(n);
    long long l = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    string result = tran(s);
    cout << result;
}