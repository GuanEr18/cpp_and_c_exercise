//
// Created by Zheng on 2026/5/26.
//
#include <iostream>
#include <queue>
using namespace std;

int main () {
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> n) {
        queue<string> b;
        string temp;
        for(int i = 1; i <= n; i++) {
            cin >> temp;
            b.push(temp);
        }
        while(!b.empty()) {
            cout << b.front();
            b.pop();
            if (!b.empty()) {
                cout << " ";
                string s = b.front();
                b.push(s);
                b.pop();
            }
        }
        cout << endl;
    }
    return 0;
}