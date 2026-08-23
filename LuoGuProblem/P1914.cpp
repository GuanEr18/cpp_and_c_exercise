#include <iostream>
using namespace std;

int main () {
    int step;
    string s;
    cin >> step >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] + step>'z')
            s[i] += (step - 26);
        else
            s[i] += step;
    }
    cout << s;
}