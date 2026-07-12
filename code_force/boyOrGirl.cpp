//
// Created by Zheng on 2026/4/25.
//
#include <iostream>
#include <set>
using namespace std;
int main() {
    set<char> s;
    string str;
    while(cin>>str) {
        for(int i=0;i<str.length();i++) {
            s.insert(str[i]);
        }
        if (s.size()%2==0) {
            cout<<"CHAT WITH HER!"<<endl;
        } else {
            cout<<"IGNORE HIM!"<<endl;
        }
    }
    return 0;
}