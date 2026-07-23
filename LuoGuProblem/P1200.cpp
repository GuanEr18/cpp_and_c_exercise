#include <iostream>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    long long a = 1;
    for (int i = 0; i < s1.size(); i++)
    {
        a *= (s1[i] - 'A' + 1);
    }
    a = a % 47;
    long long b = 1;
    for (int i = 0; i < s2.size(); i++)
    {
        b *= (s2[i] - 'A' + 1);
    }
    b = b % 47;
    if (a == b)
    {
        cout << "GO" << endl;
    }
    else
    {
        cout << "STAY" << endl;
    }
    return 0;
}