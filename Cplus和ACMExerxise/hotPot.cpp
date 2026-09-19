#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s;
    vector<string> str;
    while (getline(cin, s))
    {
        if (s == ".")
            break;
        str.push_back(s);
    }
    int count = str.size();
    cout << count << endl;
    if (count == 0) {
        cout << "-_-#" << endl;
        return 0;
    }
    int firstposition = -1;
    int totalcount = 0;
    for (int i = 0; i < count; ++i)
    {
        if (str[i].find("chi huo guo") != string::npos)
        {
            totalcount++;
            if (firstposition == -1) {
                firstposition = i + 1;
            }
        }
    }
    if (totalcount == 0)
    {
        cout << "-_-#" << endl;
    }
    else
    {
        cout << firstposition << " " << totalcount << endl;
    }
    return 0;
}