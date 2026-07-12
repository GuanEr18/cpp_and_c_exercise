//
// Created by Zheng on 2026/4/25.
//
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int round;
    while (cin>>round) {
        int n;
        for (int i=0; i<round; i++) {
            cin>>n;
            vector<int> v(n);
            for (int i=0; i<n; i++) {
                cin>>v[i];
            }
            if (n==1) {
                cout<<1<<endl;
            } else {
                for (int j=0; j<n; j++) {
                    cout<<2;
                }
                cout<<endl;
            }
        }
    }
    return 0;
}