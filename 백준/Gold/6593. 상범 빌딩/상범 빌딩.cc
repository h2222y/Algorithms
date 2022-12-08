#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
#include <string>
using namespace std;


char board[33][33][33];
int vis[33][33][33];
int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		bool escape = false;
		int l, r, c;
		cin >> l >> r >> c;
		queue<tuple<int, int, int>> Q;
		if (l == 0 && r == 0 && c == 0) return 0;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> board[i][j][k];
					if (board[i][j][k] == 'S') {
						Q.push({ i,j,k });
						vis[i][j][k] = 0;
					}
					else if (board[i][j][k] == '.') {
						vis[i][j][k] = -1;
					}
				}
			}
		}
		while (!Q.empty() && !escape) {
			tuple<int, int, int> cur = Q.front();
			Q.pop();
			int curX, curY, curZ;
			tie(curZ, curX, curY) = cur;
			for (int i = 0; i < 6; i++) {
				int nx = curX + dx[i];
				int ny = curY + dy[i];
				int nz = curZ + dz[i];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l)continue;
				if (board[nz][nx][ny] == '#' || vis[nz][nx][ny] > 0) continue;
				vis[nz][nx][ny] = vis[curZ][curX][curY] + 1;
				if (board[nz][nx][ny] == 'E') {
					cout << "Escaped in " << vis[nz][nx][ny] << " minute(s).\n";
					escape = true;
					break;
				}
				Q.push({ nz,nx,ny });

			}
		}

		if (!escape) cout << "Trapped!\n";

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				fill(vis[i][j], vis[i][j] + c, 0);
			}
		}

	}

	return 0;
}