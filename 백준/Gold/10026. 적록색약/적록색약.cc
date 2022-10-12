#include <iostream>
#include <utility>
#include <queue>
#include <string>
#define X first
#define Y second
using namespace std;

string map[102];
int vis[102][102];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n;

void bfs(int x,int y) {
	queue<pair<int, int>> Q;
	Q.push({ x,y });
	vis[x][y] = 1;
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		for (int t = 0; t < 4; t++) {
			int nx = cur.X + dx[t];
			int ny = cur.Y + dy[t];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // out of range
			if (vis[nx][ny] != 0 || map[nx][ny] != map[x][y]) continue; // already visit or not same color
			vis[nx][ny] = 1;
			Q.push({ nx,ny });
		}
	}
}
int area() {
	int cnt = 0;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (vis[x][y] == 0) { // when not visited, 
				bfs(x, y); // bfs
				cnt++; // count area's number
			}
		}
	}
	return cnt;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i]; // add map information 
	}

	int not_blindless = area(); // not_blindless person's area count
	for (int i = 0; i < n; i++) { // initialization vis array
		fill(vis[i], vis[i]+n, 0);
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (map[x][y] == 'R') { // if blind, they can't distinguish R and G
				map[x][y] = 'G';
			}
		}
	}
	int blindless = area(); // count blind area
	cout << not_blindless << " " << blindless; 

	return 0; 
}