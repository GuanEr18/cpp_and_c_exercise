//
// Created by Zheng on 2026/6/22.
//
#include<iostream>
using namespace std;

string total;
void core11() {
    int rightCore=0,leftCore=0;
    for (int i = 0; i < total.length(); i++) {
        char c = total[i];
        if (c=='W') {
            leftCore++;
        }
        else if (c=='L') {
            rightCore++;
        }
        if ((leftCore>=11 || rightCore>=11) && abs(leftCore-rightCore)>=2) {
            cout << leftCore << ":" << rightCore << endl;
            leftCore=0;
            rightCore=0;
        }
    }
    cout << leftCore << ":" << rightCore << endl;
}
void core21() {
    int rightCore=0,leftCore=0;
    for (int i = 0; i < total.length(); i++) {
        char c = total[i];
        if (c=='W') {
            leftCore++;
        }
        else if (c=='L') {
            rightCore++;
        }
        if ((leftCore>=21 || rightCore>=21) && abs(leftCore-rightCore)>=2) {
            cout << leftCore << ":" << rightCore << endl;
            leftCore=0;
            rightCore=0;
        }
    }
    cout << leftCore << ":" << rightCore << endl;
}
int main() {
    total="";
    string s;
    while (getline(cin, s)) {
        size_t pos = s.find("E");
        if (pos != string::npos) {
            total += s.substr(0, pos);
            break;
        }
        else {
            total+=s;
        }
    }
    //11
    core11();
    cout << endl;
    //21
    core21();
    return 0;
}