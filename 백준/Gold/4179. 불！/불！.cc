#include <iostream>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#define X first
#define Y second
using namespace std;

char map[1002][1002]; // map
int vis1[1002][1002]; // for fire 
int vis2[1002][1002]; // for jihun
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int r, c;
	cin >> r >> c;
	queue<pair<int, int>> Q1; // queue for fire
	queue<pair<int, int>> Q2; // queue for jihun

	for (int i = 0; i < r; i++) { //initialization vis1, vis2 -1
		fill(vis1[i], vis1[i] + c, -1);
		fill(vis2[i], vis2[i] + c, -1);
	}

	for (int x = 0; x < r; x++) {
		string str;
		cin >> str;
		for (int y = 0; y < c; y++) {
			map[x][y] = str[y]; // map
		}
	}

	for (int x = 0; x < r; x++) {
		for (int y = 0; y < c; y++) {
			if (map[x][y] == 'F') {
				vis1[x][y] = 0; // first fire location
				Q1.push({ x,y });
			}

			if (map[x][y] == 'J') {
				vis2[x][y] = 0; // first jihun location 
				Q2.push({ x,y });
			}
		}
	}

	while (!Q1.empty()) { // fire bfs
		auto cur = Q1.front();
		Q1.pop();
		for (int t = 0; t < 4; t++) {
			int nx = cur.X + dx[t];
			int ny = cur.Y + dy[t];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (vis1[nx][ny] >= 0 || map[nx][ny] == '#') continue; //already vis or wall
			vis1[nx][ny] = vis1[cur.X][cur.Y] + 1;
			Q1.push({ nx,ny });
		}
	}

	while (!Q2.empty()) {
		auto cur = Q2.front();
		Q2.pop();
		for (int t = 0; t < 4; t++) {
			int nx = cur.X + dx[t];
			int ny = cur.Y + dy[t];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) { // escape
				cout << vis2[cur.X][cur.Y] + 1; // +1 because start from -1
				return 0;
			}
			if (vis2[nx][ny] >= 0 || map[nx][ny] == '#')continue;//already visit or wall
			if (vis1[nx][ny] != -1 && vis1[nx][ny] <= vis2[cur.X][cur.Y] + 1) continue;
			// fire already visit or fire visit at the same time 
			vis2[nx][ny] = vis2[cur.X][cur.Y] + 1;
			Q2.push({ nx,ny });
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}