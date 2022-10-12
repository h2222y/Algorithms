#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

int board[103][103][103];
int dist[103][103][103];
int dx[6] = { 0,0,0,0,-1,1 };//위, 아래,왼,오,앞,뒤
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { -1,1,0,0,0,0 };
queue<tuple<int, int, int>> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, n, h;
    cin >> m >> n >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                int tmp;
                cin >> tmp;
                board[j][k][i] = tmp;
                if (tmp == 1) Q.push({ j, k, i });
                if (tmp == 0) dist[j][k][i] = -1;
            }
        }
    }
    while (!Q.empty()) {
        tuple<int, int, int> cur = Q.front();
        Q.pop();
        int curX, curY, curZ;
        tie(curX, curY, curZ) = cur;
        for (int i = 0; i < 6; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            int nz = curZ + dz[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if (dist[nx][ny][nz] >= 0) continue;
            dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
            Q.push({ nx,ny,nz });
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (dist[j][k][i] == -1) {
                    cout << -1;
                    return 0;
                }
                ans = max(ans, dist[j][k][i]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}