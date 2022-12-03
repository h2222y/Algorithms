#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int horse_dx[8] = { -1,1,-2,2,-2,2,1,-1 };
int horse_dy[8] = { -2,-2,-1,-1,1,1,2,2 };
int board[202][202];
int dist[32][202][202];
queue<tuple<int, int, int>> Q;
int w, h;
int k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;
	cin >> w >> h;
	for (int x = 0; x < h; x++) {
		for (int y = 0; y < w; y++){
			cin >> board[x][y];
		}
	}
	Q.push({ 0,0,0 });
	dist[0][0][0] = 1;

	while (!Q.empty()) {
		int vk, vx, vy;
		tie(vk, vx, vy) = Q.front();
		Q.pop();
		if(vk<k){
		for (int i = 0; i < 8; i++) {
			int nx = vx + horse_dx[i];
			int ny = vy + horse_dy[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (board[nx][ny]) continue;
			if (dist[vk + 1][nx][ny]) continue;
			dist[vk + 1][nx][ny] = dist[vk][vx][vy] + 1;
			Q.push({ vk+1,nx,ny });
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = vx + dx[i];
			int ny = vy + dy[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (board[nx][ny]) continue;
			if (dist[vk][nx][ny]) continue;
			dist[vk][nx][ny] = dist[vk][vx][vy] + 1;
			Q.push({ vk,nx,ny });
		}
	}
	int ans = 0x7f7f7f7f;
	for (int i = 0; i < k + 1; i++)
		if (dist[i][h - 1][w - 1]) ans = min(ans, dist[i][h - 1][w - 1]);
	if (ans != 0x7f7f7f7f) cout << ans - 1;
	else cout << -1;
	return 0;
}