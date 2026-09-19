#include <iostream>
#include <string>
#include <cctype>
using namespace std;
/**
 * 只能通过一个测试点
 */
int main()
{
    string s;
    getline(cin, s);
    int count[4] = {0, 0, 0, 0};
    for (char c : s)
    {
        char upper_c = toupper(c);
        if (upper_c == 'G')
            count[0]++;
        else if (upper_c == 'P')
            count[1]++;
        else if (upper_c == 'L')
            count[2]++;
        else if (upper_c == 'T')
            count[3]++;
    }
    while (count[0] > 0 || count[1] > 0 || count[2] > 0 || count[3] > 0)
    {
        if (count[0] > 0)
        {
            cout << 'G';
            count[0]--;
        }
        if (count[1] > 0)
        {
            cout << 'P';
            count[1]--;
        }
        if (count[2] > 0)
        {
            cout << 'L';
            count[2]--;
        }
        if (count[3] > 0)
        {
            cout << 'T';
            count[3]--;
        }
    }
    return 0;
}
