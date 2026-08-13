#include <iostream>
#include <string>
using namespace std;

int n,mad=0,s;
void change (const string &s) {
    for (int i = 0; i < s.size(); i++) {        
        if (s.substr(i,i+5)=="shiki" && i+5<=s.size()) {
            mad++;
        }
        else if (s.substr(i,i+7)=="daishiki" && i+7<=s.size()) {
            mad+=2;
        }
        else if (s.substr(i,i+5)=="kirai" && i+5<=s.size()) {
            if (mad>=0) mad=0;
        }
        else mad--;
    }
    // if (s=="shiki") {
    //     mad++;
    // }
    // else if (s=="daishiki") {
    //     mad+=2;
    // }
    // else if (s=="kirai") {
    //     if (mad>=0) mad=0;
    // }
    // else mad--;
}
 int main () {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        change(str);
    }
    if (s+mad>0) {
        cout << mad-s << endl;
    }
    else {
        cout << "shuki" << endl;
    }
}