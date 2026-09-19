#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int toSeconds(const string &s)
{
    int h = (s[0] - '0') * 10 + (s[1] - '0');
    int m = (s[3] - '0') * 10 + (s[4] - '0');
    int sec = (s[6] - '0') * 10 + (s[7] - '0');
    return h * 3600 + m * 60 + sec;
}
string toTimeStr(int totalSec)
{
    char buf[10];
    sprintf(buf, "%02d:%02d:%02d",
            totalSec / 3600,
            (totalSec % 3600) / 60,
            totalSec % 60);
    return string(buf);
}

int main()
{
    int n;
    cin >> n;
    vector<string> start(n);
    vector<string> end(n);
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> start[i] >> c >> end[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (start[i] > start[j])
            {
                swap(start[i], start[j]);
                swap(end[i], end[j]);
            }
        }
    }

    string currentend = "00:00:00";
    for (int i = 0; i < n; i++)
    {
        if (currentend == "23:59:59")
            break;
        else
        {
            if (start[i] > currentend)
            {
                cout << currentend << " - " << start[i] << endl;
                if (currentend < end[i])
                    currentend = end[i];
            }
            else if (currentend < end[i])
                currentend = end[i];
        }
    }
    if (currentend < "23:59:59")
        cout << currentend << " - " << "23:59:59";
}