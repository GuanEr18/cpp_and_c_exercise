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
        queue<int> b;
        for(int i = 1; i <= n; i++) {
            b.push(i);
        }
        while(!b.empty()) {
            cout << b.front();
            b.pop();
            if (!b.empty()) {
                cout << " ";
                int temp = b.front();
                b.push(temp);
                b.pop();
            }
        }
        cout << endl;
    }
    return 0;
}