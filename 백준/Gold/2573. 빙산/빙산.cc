#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second

int ice[302][302];
int vis[302][302];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int n, m;

int status() {
	int x = -1, y = -1;
	int cnt = 0; // 빙산의 개수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ice[i][j] == 0)continue;
			x = i;
			y = j;
			cnt++;
		}
	}
	if (cnt == 0) return 0;
	int cnt2 = 0;
	queue<pair<int, int>> Q;
	vis[x][y] = 1;
	Q.push({ x,y });
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		cnt2++;
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] == 1 || ice[nx][ny] <= 0) continue;
			vis[nx][ny] = 1;
			Q.push({ nx,ny });
		}
	}
	if (cnt == cnt2) return 1;
	return 2;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			cin >> ice[x][y];
		}
	}
	int year = 0;
	while (1) {
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				if (ice[x][y] == 0) continue;
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (ice[nx][ny] != 0) continue;
					vis[x][y]++;
				}
			}
		}
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				ice[x][y] = max(0, ice[x][y] - vis[x][y]);
			}
		}
		year++;
		for (int x = 0; x < n; x++) {
			fill(vis[x], vis[x] + m, 0);
		}
		int check = status();
		for (int x = 0; x < n; x++) {
			fill(vis[x], vis[x] + m, 0);
		}
		if (check == 0) {
			cout << 0;
			return 0;
		}
		else if (check == 1) continue;
		else break;
	}
	cout << year;
	return 0;
}