//
// Created by Zheng on 2026/4/25.
//
#include <iostream>
using namespace std;
int main() {
    int round;
    while (cin>>round) {
        int n;
        for (int i=0;i<round;i++) {
            cin>>n;
            for (int j=1;j<=n;j++) {
                cout<<j<<" ";
                cout<<n+2*j-1<<" ";
                cout<<n+2*j<<" ";
            }
        }
    }
    return 0;
}