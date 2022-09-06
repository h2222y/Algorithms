#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second

int dx[8] = { -2,-1,-2,-1,2,1,2,1 };
int dy[8] = { -1,-2,1,2,-1,-2,1,2 };
int map[302][302];
int dist[302][302];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int l;
		cin >> l;
		for (int x = 0; x < l; x++) {
			fill(dist[x], dist[x] + l, 0);
			fill(map[x], map[x] + l, 0);
		}
		int nowx, nowy;
		cin >> nowx >> nowy;
		int movx, movy;
		cin >> movx >> movy;
 		//map[nowx][nowy] = 1;
		map[movx][movy] = 2;
		queue<pair<int, int>> Q;
		Q.push({ nowx,nowy });
		dist[nowx][nowy] = 1;
		int mx = 0;
		while (!Q.empty()) {
			auto cur = Q.front();
			Q.pop();
			for (int i = 0; i < 8; i++) {
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];
				if (nx < 0 || nx >= l || ny < 0 || ny >= l)continue;
				if (dist[nx][ny] > 0) continue;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				Q.push({ nx,ny });
				if (map[nx][ny] == 2) {
					mx = max(mx, dist[nx][ny]-1);
				}
			}
		}
		cout << mx << "\n";
	}
	return 0; 
}