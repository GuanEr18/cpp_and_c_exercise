#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long sum = 0;
    cin >> n;
    // 小根堆：greater<int> 使堆顶为最小值
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }
    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int merged = a + b;
        sum += merged;
        pq.push(merged);
    }
    cout << sum << endl;
    priority_queue<int, vector<int>, greater<int>>().swap(pq); // 清空
    return 0;
}

// // 默认就是大根堆，堆顶永远是最大值
// priority_queue<int> pq;
// pq.push(3); pq.push(1); pq.push(5);
// cout << pq.top(); // 输出 5

// // 必须写全三个模板参数！
// priority_queue<int, vector<int>, greater<int>> pq;

// pq.push(3); pq.push(1); pq.push(5);
// cout << pq.top(); // 输出 1