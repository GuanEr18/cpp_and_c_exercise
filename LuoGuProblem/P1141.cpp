#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
int dx[]={0, 0, 1, -1},
    dy[]={1, -1, 0, 0};
int map[1001][1001];
int dist[1001][1001];
bool visited[1001][1001];

bool XOR (int a,int b) {
    return a ^ b;
}
long long BFS (int startX, int startY) {
    // BFS implementation would go here
    queue<pair<int, int>> q;
    vector<pair<int, int>> component;
    // 记录当前连通块的所有点
    q.push({startX, startY});
    component.push_back({startX, startY});
    // 因为对联通区块进行了记忆处理，所以不能重置
    // memset(visited, false, sizeof(visited));
    // memset(dist, -1, sizeof(dist));
    visited[startX][startY] = true;
    dist[startX][startY] = 0;
    // 题目要求起点计入 所以初始为1，现在的sum作为冗余
    long long sum = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX >= 0 && newX < n &&
                newY >= 0 && newY < n &&
                !visited[newX][newY] &&
                XOR(map[x][y], map[newX][newY])) {
                sum++;
                visited[newX][newY] = true;
                // 这里的最短路径计算会污染原来的连通块大小的计算 
                // 所以我们不需要记录最短路径
                // dist[newX][newY] = dist[x][y] + 1;
                q.push({newX, newY});
                component.push_back({newX, newY});
            }
        }
    }
    // 这道题目对于连通块的大小要求是一样的 所以我们可以在这里记录下当前连通块的所有点
    int size = component.size();
    for (auto &p : component) {
        dist[p.first][p.second] = size;
    }
    return sum;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i=0;i<n;i++) {
        string temp;
        cin >> temp;
        for (int j=0;j<temp.length();j++) {
            map[i][j] = temp[j]-'0';
        }
    }
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < m;i++) {
        int x, y;
        cin >> x >> y;
        if (dist[x-1][y-1] != -1) {
            cout << dist[x-1][y-1] << "\n";
            continue;
        }
        long long result = BFS(x-1, y-1);
        cout << result << "\n";
    }
}