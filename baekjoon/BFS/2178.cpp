#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;
#define X first
#define Y second

//1은 이동할 수 있는 칸, 0은 이동할 수 없는 칸
// 끝으로 이동할때 최소 칸 수는?

string map[102];
int dis[102][102];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	queue <pair<int,int>> Q;
	Q.push({ 0,0 });
	dis[0][0] = 1;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();
				for (int i = 0; i < 4; i++) {
					int nx = cur.X + dx[i];
					int ny = cur.Y + dy[i];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (dis[nx][ny] >= 1 || map[nx][ny] != '1') continue;
					Q.push({ nx,ny });
					dis[nx][ny] += 1;
				}
			}
		
		}
	}
	cout << dis[n - 1][m - 1];

	return 0;
}