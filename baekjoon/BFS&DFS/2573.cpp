#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second
int ice[303][303];
int vis[303][303];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int n, m; 
int year = 0;

int bfs() {
	int zero[303][303] = { 0 };
	queue<pair<int, int>> Q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ice[i][j] == 0) continue;
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if(ice[nx][ny]==0) zero[i][j]++;
			}
		}
	}
	Q.push({ x,y });
	vis[x][y] = 1;
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] == 0 && ice[nx][ny] == 0) {
				ice[x][y] = ice[x][y] - ice[nx][ny];
			}
			if (vis[nx][ny] == 0 && ice[nx][ny] != 0) {
				Q.push({ nx,ny });
				vis[nx][ny] = 1;
			}
		}
	}
	
}
int status() {
	int x = -1, y = -1;
	int cnt1 = 0; // 빙산의 개수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ice[i][j]) {
				x = i;
				y = j;
				cnt1++;
			}
		}
	}
	if (cnt1 == 0) return 0;
	int cnt2 = 0; // x,y와 붙어있는 빙산의 수
	queue<pair<int, int>> Q2;
	vis[x][y] = 1;
	Q2.push({ x,y });
	while (!Q2.empty()) {
		auto cur = Q2.front();
		Q2.pop();
		cnt2++;
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] == 1 || ice[nx][ny] <= 0)continue;
			vis[nx][ny] = 1;
			Q2.push({ nx,ny });
		}
	}
	if (cnt1 == cnt2) return 1;
	return 2;
}

int main() {
	cin >> n >> m; // 행,열 입력
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			cin >> ice[x][y];
		}
	}
	while (1) {
		year++;
		bfs();
		status();
	}
		
		
	return 0;
}