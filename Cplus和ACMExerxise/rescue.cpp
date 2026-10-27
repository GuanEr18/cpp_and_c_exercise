#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

const int INF = 0x3f3f3f3f;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int dijk(const vector<string> &grid, pair<int, int> start, pair<int, int> target)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INF));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    dist[start.first][start.second] = 0;
    pq.push({0, start.first, start.second});
    while (!pq.empty())
    {
        auto [d, cx, cy] = pq.top();
        pq.pop();
        // 过期状态剪枝
        if (d > dist[cx][cy])
            continue;
        // 终点首次弹出即为最优解
        if (cx == target.first && cy == target.second)
            return d;
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i], ny = cy + dy[i];
            // 边界 + 非墙
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '#')
                continue;
            // 根据格子类型确定边权
            int w = (grid[nx][ny] == 'x') ? 2 : 1;
            int nd = d + w;
            // 松弛操作
            if (nd < dist[nx][ny])
            {
                dist[nx][ny] = nd;
                pq.push({nd, nx, ny});
            }
        }
    }
    return -1;
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        vector<string> grid(n);
        pair<int, int> start, target;
        for (int i = 0; i < n; i++)
        {
            cin >> grid[i];
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'r')
                    start = {i, j};
                else if (grid[i][j] == 'a')
                    target = {i, j};
            }
        }
        int answer = dijk(grid, start, target);
        if (answer == -1)
            cout << "Poor ANGEL has to stay in the prison all his life." << endl;
        else
            cout << answer << endl;
    }
}
/** 之前自己写的错误方法
 * int bfs (const vector<vector<char>> &map) {
    queue<pair<int,int>> q;
    memset(dist, -1, sizeof(dist));
    memset(pre, -1, sizeof(pre));
    if (set1[0]==set2[0] && set1[1]==set2[1]) {
        return 0;
    }
    q.push(pair<int,int> (set1[0], set1[1]));
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        pair<int, int> next[4] = {
            pair<int, int>(current.first - 1, current.second),
            pair<int, int>(current.first, current.second + 1),
            pair<int, int>(current.first + 1, current.second),
            pair<int, int>(current.first, current.second - 1)};
        for (int i = 0; i < 4;i++) {
            pair<int, int> nextpos = next[i];
            if (nextpos.first>=0 && nextpos.second>=0 && nextpos.first<=205 && nextpos.second<=205) {
                if (map[nextpos.first][nextpos.second]=='.')
                    dist[nextpos.first][nextpos.second] = dist[current.first][current.second] + 1;
                else if (map[nextpos.first][nextpos.second]=='x')
                    dist[nextpos.first][nextpos.second] = dist[current.first][current.second] + 1;
                else if (map[nextpos.first][nextpos.second]=='#')
                    break;
                pre[nextpos.first][nextpos.second] = current;
                if (nextpos.first==set2[0] && nextpos.second==set2[1])
                    return dist[nextpos.first][nextpos.second];
                q.push(nextpos);
            }

        }
    }
    return -1;
}
 */