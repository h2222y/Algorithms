#include <iostream>
#include <queue>
#include <utility>
#define X first
#define Y second
using namespace std;

int board[501][501];
int vis[501][501];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
queue<pair<int, int>> Q;

int main() {
	int n, m;
	cin >> n >> m;

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			cin >> board[x][y];
		}
	}

	int width = 0;
	int cnt = 0;
	int max_width = 0;

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (board[x][y] == 0 || vis[x][y] == 1)continue;
			cnt++;
			vis[x][y] = 1;
			Q.push({ x,y });
			width = 1;

			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();
				for (int t = 0; t < 4; t++) {
					int nx = cur.X + dx[t];
					int ny = cur.Y + dy[t];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] == 1 || board[nx][ny] == 0) continue;
					vis[nx][ny] = 1;
					Q.push({ nx,ny });
					width++;
				}
				max_width = max(max_width, width);
			}
		}
	}
	cout << cnt << "\n" << max_width;
	return 0;
}