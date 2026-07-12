//
// Created by Zheng on 2026/4/29.
//
#include <iostream>
#include <vector>
using namespace std;

//太难了  题目222H   以后再来

vector<int> turn(const vector<int>& a) {
    int n = a.size();
    vector<int> v(n, 0);
    // O(N) 时间复杂度统计频率
    for (const int x : a) {
        if (x >= 0 && x < n) {
            v[x]++;
        }
    }
    return v;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int round,n,k;
    cin>>round;
    vector<int> g(round,0);
    for (int i=0;i<round;i++) {
        cin>>n>>k;
        vector<int> a(n);
        for (int j=0;j<n;j++) {
            cin>>a[j];
        }
        int temp=0;
        while (true) {
            vector<int> naext_a=turn(a);
            if (naext_a==a) {
                break;
            }
            a=naext_a;
            temp++;
            if (temp>=k) {
                break;
            }
        }
        cout<<temp<<endl;
    }
    return 0;
}