#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second

int map[501][501];
int vis[501][501];
queue<pair<int,int>> Q;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			cin >> map[x][y];
		}
	}

	// 0�� ��ĥ�� �ȵȺκ�, 1�� ��ĥ�� �� �κ�

	int cnt = 0;
	int width = 0;
	int mx = 0;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (map[x][y] == 0 || vis[x][y] == 1) continue;
			cnt++;
			vis[x][y] = 1;
			Q.push({ x,y });
			width = 1;

			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = cur.X + dx[i];
						int ny = cur.Y + dy[i];
						if (nx < 0 || nx >= n || ny<0 || ny>=m)continue;
						if (vis[nx][ny] == 1 || map[nx][ny] == 0)continue;
						vis[nx][ny] = 1;
						Q.push({ nx,ny });
						width++;
					}
				mx = max(mx, width);
			}
		}
	}
	cout << cnt << "\n"<<mx;

	
	return 0; 
}