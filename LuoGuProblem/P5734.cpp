#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string str;
    cin >> n;
    cin >> str;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num == 1)
        {
            string s;
            cin >> s;
            str += s;
            cout << str << "\n";
        }
        else if (num == 2)
        {
            int a, b;
            cin >> a >> b;
            str = str.substr(a, b);
            cout << str << "\n";
        }
        else if (num == 3)
        {
            int a;
            string s;
            cin >> a >> s;
            str.insert(a, s);
            cout << str << "\n";
        }
        else if (num == 4)
        {
            string s;
            cin >> s;
            size_t pos = str.find(s);
            if (pos != string::npos)
            {
                cout << pos << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
    }

    return 0;
}