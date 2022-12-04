#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MX =102;
int board[MX][MX];
int dist[MX][MX];
int vis[MX][MX];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
queue <pair<int, int>> Q;
int n;

int main() {
	cin >> n;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cin >> board[x][y];
		}
	}
	int cnt = 0;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (board[x][y] == 0 || vis[x][y]) continue;
			cnt++;
			Q.push({ x,y });
			vis[x][y] = 1;
			board[x][y] = cnt;
			while (!Q.empty())
			{
				auto cur = Q.front();
				Q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (vis[nx][ny] || board[nx][ny] == 0) continue;
					Q.push({ nx,ny });
					board[nx][ny] = cnt;
					vis[nx][ny] = 1;
				}
			} 
		}
	}
	for (int i = 0; i < n; i++)
		fill(dist[i], dist[i] + n, -1);
	int ans = 999999;

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (board[x][y] == 0) continue;
			Q.push({ x,y });
			dist[x][y] = 0;
			bool escape = false;
			while (!Q.empty() && !escape) {
				auto cur = Q.front();
				Q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
					if (dist[nx][ny] >= 0 || board[nx][ny] == board[x][y]) continue;
					if (board[nx][ny] != 0 && board[nx][ny] != board[x][y]) {
						ans = min(ans, dist[cur.first][cur.second]);
						while (!Q.empty())Q.pop();
						escape = true;
						break;
					}
					dist[nx][ny] = dist[cur.first][cur.second] + 1;
					Q.push({ nx,ny });
				}
			}
			for (int i = 0; i < n; i++)
				fill(dist[i], dist[i] + n, -1);
		}
	}
	cout << ans;
}