#include <iostream>
#include <utility>
#include <queue>
#include <vector>
using namespace std;
#define X first
#define Y second

int board[103][103];
int vis[103][103];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
vector<int> ans;
int main() {
	int n;
	cin >> n;
	int maxheight = 0;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cin >> board[x][y];
			if (board[x][y] > maxheight) {
				maxheight = board[x][y];
			}
		}
	}
	int mx = 0;
	for (int i = 0; i <= maxheight; i++) {
		int cnt = 0;
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (board[x][y] <= i) vis[x][y] = -1;
			}
		}

		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (vis[x][y]!=0) continue;
				queue<pair<int, int>> Q;
				Q.push({ x,y });
				vis[x][y] = 1;
				while (!Q.empty()) {
					auto cur = Q.front();
					Q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cur.X + dx[k];
						int ny = cur.Y + dy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
						if (board[nx][ny] <= i || vis[nx][ny] == 1)continue;
						Q.push({ nx,ny });
						vis[nx][ny] = 1;
					}
				}
				cnt++;
			}
		}
		mx = max(mx, cnt);
		for (int x = 0; x < n; x++) {
			fill(vis[x], vis[x] + n, 0);
		}
	}

	cout << mx;


	return 0;
}