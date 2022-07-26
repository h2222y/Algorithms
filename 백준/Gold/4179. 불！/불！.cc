#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;
#define X first
#define Y second

string map[1001];
int vis1[1001][1001]; // 불의 전파 시간
int vis2[1001][1001]; // 지훈이의 이동 시간 

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		fill(vis1[i], vis1[i] + c,-1);
		fill(vis2[i], vis2[i] + c,-1);
	}
	for (int x = 0; x < r; x++) {
		cin >> map[x];
	}
	queue<pair<int, int>> Q1;
	queue<pair<int, int>> Q2;
	// # 벽, . 지나갈 수 있는 공간, J 지훈이의 미로에서의 초기위치(지나갈 수 있는 공간)
	// F 불이 난 공간
	// 지훈이와 불은 매 분마다 한 칸씩 수평 또는 수직으로 이동한다
	// 지훈이는 벽과 불이 있는 공간을 통과하지 못한다.
	// 시작점이 두개(지훈이의 이동, 불의 이동)
	for (int x = 0; x < r; x++) {
		for (int y = 0; y < c; y++) {
			if (map[x][y] == 'F') {
				Q1.push({ x,y });
				vis1[x][y] = 0;
			}
			if (map[x][y] == 'J') {
				Q2.push({ x,y });
				vis2[x][y] = 0;
			}
		}
	}
	while (!Q1.empty()) {
		pair<int,int> cur = Q1.front();
		Q1.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (vis1[nx][ny] >= 0 || map[nx][ny] == '#') continue;
			vis1[nx][ny] = vis1[cur.X][cur.Y] + 1;
			Q1.push({ nx,ny });
		}
	}

	while (!Q2.empty()) {
		pair<int,int> cur = Q2.front();
		Q2.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
				cout << vis2[cur.X][cur.Y]+1;
				return 0;
			}
			if (vis2[nx][ny] >= 0 || map[nx][ny] == '#') continue;
			if (vis1[nx][ny] != -1 && vis1[nx][ny] <= vis2[cur.X][cur.Y]+1) continue;
			vis2[nx][ny] = vis2[cur.X][cur.Y] + 1;
			Q2.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}