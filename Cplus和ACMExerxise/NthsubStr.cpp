#include <iostream>
using namespace std;

int main()
{
    int l;
    long long n;
    cin >> l >> n;
    long long total = 1;
    for (int i = 0; i < l; i++)
    {
        total *= 26;
    }
    long long index = total - n;
    char str[7];
    for (int i = l - 1; i >= 0; i--)
    {
        str[i] = 'a' + (index % 26);
        index /= 26;
    }
    for (int i = 0; i < l; i++)
    {
        cout << str[i];
    }
    cout << endl;
}