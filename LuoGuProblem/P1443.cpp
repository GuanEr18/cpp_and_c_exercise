#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dist[1005][1005];
int m, n, x, y;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
void BFS (pair<int,int> start) {
    queue<pair<int,int>> q;
    memset(dist, -1, sizeof(dist));
    q.push(start);
    dist[start.first][start.second]=0;
    while (!q.empty())
    {
        pair<int,int> current = q.front();
        q.pop();
        int cx=current.first;
        int cy=current.second;
        for (int i=0;i<8;i++) {
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if (nx>=1 && nx<=n && ny>=1 && ny<=m && dist[nx][ny]==-1) {
                dist[nx][ny]=dist[cx][cy]+1;
                q.push({nx,ny});
            }
        }
    }
    
}
int main () {
    cin >> n >> m >> x >> y;
    BFS({x,y});
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}