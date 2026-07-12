//
// Created by Zheng on 2026/5/26.
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int n;
vector<int> D;
vector<int> S;
void maxFrequency() {
    unordered_map<int, int> m;
    int max_cnt = 0;
    for (int i = 0; i < n; i++) {
        int k=S[i]-D[i];
        m[k]++;
        max_cnt = max(max_cnt, m[k]);
    }
    cout << max_cnt << endl;
}
int main() {
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> t) {
        for (int i = 0; i < t; i++) {
            cin >> n;
            D.clear();
            S.clear();
            D.resize(n);
            S.resize(n);
            for (int j = 0; j < n; j++) {
                cin >> D[j];
            }
            for (int j = 0; j < n; j++) {
                cin >> S[j];
            }
            maxFrequency();
        }
    }
    return 0;
}