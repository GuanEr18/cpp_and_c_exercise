/**
 * 这道题目未完成
 * 思考过程GPT中有
 * 节点第一次入队时确定最短距离，节点出队前允许继续累加最短路径数量。
 */

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int N = 1000005;
const int MOD = 100003;
int n, m;
vector<int> graph[N];
int dist[N];
int ways[N];
void BFS() {
    memset(dist, -1, sizeof(dist));
    memset(ways, 0, sizeof(ways));
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    ways[1] = 1;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int next : graph[current]) {
            // 第一次到达该节点
            if (dist[next] == -1) {
                dist[next] = dist[current] + 1;
                ways[next] = ways[current];

                q.push(next);
            }
            // 找到另一条最短路径
            else if (dist[next] == dist[current] + 1) {
                ways[next] =
                    (ways[next] + ways[current]) % MOD;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    BFS();
    for (int i = 1; i <= n; i++) {
        cout << ways[i] << "\n";
    }
    return 0;
}

