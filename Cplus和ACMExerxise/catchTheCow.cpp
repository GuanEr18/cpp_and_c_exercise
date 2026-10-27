//
// Created by Zheng on 2026/9/22.
//
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100000;
int parent[MAX];
int perPos[MAX];
int Dist[MAX];
vector<int> getPath(int start, int end)
{
    vector<int> path;
    for (int cur = end; cur != -1; cur = perPos[cur])
    {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    return path;
}
int bfs(int n, int k)
{
    queue<int> q;
    memset(Dist, -1, sizeof(Dist));
    q.push(n);
    Dist[n] = 0;
    memset(perPos, -1, sizeof(perPos));
    if (n == k)
    {
        return 0;
    }
    while (!q.empty())
    {
        // 取出现在要处理的位置，因为之前处理过的数字虽然在顶上 但是处理过后就被弹开了
        int current = q.front();
        q.pop();
        int next[3] = {current - 1, current + 1, current * 2};
        for (int i = 0; i < 3; i++)
        {
            int nextpos = next[i];
            if (nextpos >= 0 && nextpos <= MAX && Dist[nextpos] == -1)
            {
                Dist[nextpos] = Dist[current] + 1;
                perPos[nextpos] = current;
                // 到位置了就返回
                if (nextpos == k)
                    return Dist[nextpos];
                // 没到位置就压入继续
                q.push(nextpos);
            }
        }
    }
    return -1;
}

int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        int result = bfs(n, k);
        cout << result << endl;
        if (result != -1)
        {
            vector<int> path = getPath(n, k);
            for (int i = 0; i < path.size(); i++)
            {
                if (i > 0)
                    cout << " ";
                cout << path[i];
            }
            cout << endl;
        }
    }
}

/**
 * 
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
#include <climits>
using namespace std;

const int INF = 0x3f3f3f3f;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int dijkstra(const vector<string> &grid, pair<int,int> start, pair<int,int> target) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INF));
    
    // 小根堆：{累计时间, x, y}
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    
    dist[start.first][start.second] = 0;
    pq.push({0, start.first, start.second});
    
    while (!pq.empty()) {
        auto [d, cx, cy] = pq.top(); pq.pop();
        
        // ★ 过期状态剪枝
        if (d > dist[cx][cy]) continue;
        
        // ★ 终点首次弹出即为最优解
        if (cx == target.first && cy == target.second) return d;
        
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            
            // 边界 + 非墙
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '#')
                continue;
            
            // ★ 核心：根据格子类型确定边权
            int w = (grid[nx][ny] == 'x') ? 2 : 1;
            int nd = d + w;
            
            // ★ 松弛操作
            if (nd < dist[nx][ny]) {
                dist[nx][ny] = nd;
                pq.push({nd, nx, ny});
            }
        }
    }
    return -1; // 不可达
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<string> grid(n);
        pair<int,int> start, target;
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'r') start = {i, j};
                if (grid[i][j] == 'a') target = {i, j};
            }
        }
        
        int ans = dijkstra(grid, start, target);
        if (ans == -1)
            cout << "可怜的 ANGEL 必须终身监禁。" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
 */