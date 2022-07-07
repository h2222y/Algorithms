#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second

int box[1003][1003];
int dis[1003][1003];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, n;
	cin >> m >> n;
	queue<pair<int, int>> Q;

	for (int x = 0; x < m; x++) {
		for (int y = 0; y < n; y++) {
			cin >> box[x][y];
			if (box[x][y] == 1) Q.push({ x,y });
			if (box[x][y] == 0) dis[x][y] = -1;
		}
	}

	// 1 익은 토마토, 0 익지 않은 토마토, -1 토마토 없음
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n)continue;
			if (dis[nx][ny] >= 0) continue;
			dis[nx][ny] = dis[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
		}
	}
	int ans = 0;
	for (int x = 0; x < m; x++) {
		for (int y = 0; y < n; y++) {
			if (dis[x][y] == -1) {
				cout << -1;
				return 0;
			}
			ans = max(ans, dis[x][y]);
		}
	}
	cout << ans;


	return 0;
}