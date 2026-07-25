#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int countB = 0,countG = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'b' || (i+1<s.length() && s[i+1] == 'o') || (i+2<s.length() && s[i+2] == 'y'))
        {
            countB++;   
        }
        else if (s[i] == 'g' || (i+1<s.length() && s[i+1] == 'i') || (i+2<s.length() && s[i+2] == 'r') || (i+3<s.length() && s[i+3] == 'l'))
        {
            countG++;
        }
    }
    cout << countB <<endl<< countG << endl;
}