#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
    int n;
    if (!(cin >> n)) {
        return 0;
    }
    vector<pair<int,int> > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    int maxContinution=0;
    for (int i = 0; i < n; i++) {
        vector<pair<int,int> > remaining;
        for(int j = 0; j < n; j++) {
            if (j != i) {
                remaining.push_back(v[j]);
            }
        }
        sort(remaining.begin(), remaining.end());
        int currentContinution=0;
        int start=-1,end=-1;
        for (const pair<int,int> &p: remaining) {
            // 这是区间中断的的情况
            if (p.first > end) {
                if (start != -1) {
                    // 不是第一次就会计算区间的长度
                    currentContinution += end - start;
                }
                // 这里只用于记录当前区间的起点和终点
                // 中断后和第一次赋值才会用这里
                start = p.first;
                end = p.second;
            } else {
                // 演唱区间部分
                end = max(end, p.second);
                start = min(start, p.first);
            }
        }
        if (start != -1) {
            currentContinution += end - start;
        }
        maxContinution = max(maxContinution, currentContinution);
    }
    cout << maxContinution << endl;
    return 0;
}