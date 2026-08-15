//
// Created by Zheng on 2026/4/10.
//
#include <iostream>
#include <cmath>
using namespace std;

void solve(int a)
{
    bool first = true;

    for (int i = 14; i >= 0;i--) {
        if (a & (1 << i)) {
            if (!first) {
                cout << "+";
            }
            first = false;
            if (i==0) {
                cout << "2(0)";
            }
            else if  (i==1) {
                cout<<"2";
            }
            else {
                cout <<"2(";
                solve(i);
                cout << ")";
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;
    if (cin >> x) {
        solve(x);
        cout << endl;
    }
    return 0;
}