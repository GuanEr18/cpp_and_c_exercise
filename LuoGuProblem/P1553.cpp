#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string revSub(string s) {
    reverse(s.begin(), s.end());
    int pos = s.find_first_not_of("0");
    if (pos==string::npos) return "0";
    return s.substr(pos);
}
string fraction (string s) {
    reverse(s.begin(), s.end());
    int pos = s.find_last_not_of("0");
    if (pos==string::npos) return "0";
    return s.substr(0,pos+1);
}
int main () {
    string s;
    cin >> s;
    if (s.find("%")!=string::npos) {
        int pos = s.find("%");
        if (pos==s.size()-1) {
            cout << revSub(s.substr(0,pos)) << "%" << endl;
            return 0;
        } else {
            string temp1=revSub(s.substr(0,pos));
            string temp2=revSub(s.substr(pos+1));
            cout << temp1 << "%" << temp2 << endl;
        }
    } else if (s.find(".")!=string::npos) {
        int pos = s.find(".");
        cout << revSub(s.substr(0,pos)) << "." << fraction(s.substr(pos+1)) << endl;
    } else if (s.find("/")!=string::npos) {
        int pos = s.find("/");
        string temp1=revSub(s.substr(0,pos));
        string temp2=revSub(s.substr(pos+1));
        cout << temp1 << "/" << temp2 << endl;
    } else {
        cout << revSub(s) << endl;
    }
}