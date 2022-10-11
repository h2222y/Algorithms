#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define X first
#define Y second

int board[101][101];
int n, m;//행,열
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int vis[101][101] = { 0 };

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			board[i][j] = str[j] - '0';
		}
	}
	queue<pair<int, int>> Q;
	vis[0][0] = 1;
	Q.push({ 0,0 });
	int cnt = 0;
	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		cnt++;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] != 0 || board[nx][ny]!=1 ) continue;
			vis[nx][ny] = vis[cur.X][cur.Y]+1;
			Q.push({ nx,ny });
		}
	}
	cout << vis[n-1][m-1];
	return 0;
}