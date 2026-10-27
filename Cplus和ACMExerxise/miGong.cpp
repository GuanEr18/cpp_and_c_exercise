#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 105;
int g[N][N];
bool vis[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool bfs(int n, int sx, int sy, int ex, int ey) {
    // 起始点判断是不是坑
    if (g[sx][sy] == 0 || g[ex][ey] == 0)
        return false;
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> q;
    q.push({sx, sy});
    vis[sx][sy] = true;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == ex && y == ey)
            return true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (g[nx][ny] == 0 || vis[nx][ny])
                continue;
            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    return false;
}

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> g[i][j];
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (bfs(n, x1, y1, x2, y2))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}