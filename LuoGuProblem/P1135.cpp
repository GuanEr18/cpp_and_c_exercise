#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, a, b;
int k[1001];
int dist[1001];
bool visited[1001];
void BFS (int start) {
    queue<int> q;
    memset(dist, -1, sizeof(dist));
    memset(visited, false, sizeof(visited));
    q.push(start);
    dist[start] = 0;
    visited[start] = true;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        // Process the current node
        int change=k[current];
        if (current + change <= n && !visited[current + change]) {
            dist[current + change] = dist[current] + 1;
            q.push(current + change);
            visited[current + change] = true;
        }
        if (current - change >= 1 && !visited[current - change]) {
            dist[current - change] = dist[current] + 1;
            q.push(current - change);
            visited[current - change] = true;
        }
    }
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> a >> b;
    for (int i=1;i<=n;i++) {
        cin >> k[i];
    }
    if (a==b) {
        cout << 0 << endl;
        return 0;
    }
    BFS(a);
    cout << dist[b] << endl;
}