#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = { 0,0,-1,1 }; // k를 넘었을 때 상하좌우로 이동
int dy[4] = { -1,1,0,0 };
int horse_dx[8] = { -1,1,-2,2,-2,2,1,-1 }; // k를 넘지 않았을 때, 말처럼 이동 
int horse_dy[8] = { -2,-2,-1,-1,1,1,2,2 };
int board[202][202]; // 이동할 수 있는 배열을 입력받음
int dist[32][202][202]; // k보다 작을때와 k보다 클때 모두 기록
queue<tuple<int, int, int>> Q;
int w, h; // 높이 넓이 입력
int sister; // k 입력

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> sister;
	cin >> w >> h;
	for (int x = 0; x < h; x++) {
		for (int y = 0; y < w; y++){
			cin >> board[x][y];
		}
	} // 배열 입력 받음
	Q.push({ 0,0,0 }); // 0,0,0에 대입
	dist[0][0][0] = 1;

	while (!Q.empty()) {
		int vk, vx, vy;
		tie(vk, vx, vy) = Q.front();
		Q.pop();
		if(vk<sister){ // k보다 작을때
		for (int i = 0; i < 8; i++) {
			int nx = vx + horse_dx[i];
			int ny = vy + horse_dy[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (board[nx][ny]) continue; // board가 장애물일때
 			if (dist[vk + 1][nx][ny]) continue; // vk+1, nx, ny가 0이 아닐때
			dist[vk + 1][nx][ny] = dist[vk][vx][vy] + 1; // 한 번 증가시키고 거리 표시 
			Q.push({ vk+1,nx,ny });
			}
		}
		// vk가 k보다 커졌을 때
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
	int ans = 0x7f7f7f7f; // 최소 거리를 구하기 위해 
	for (int i = 0; i < sister + 1; i++)
		if (dist[i][h - 1][w - 1]) ans = min(ans, dist[i][h - 1][w - 1]);
	if (ans != 0x7f7f7f7f) cout << ans - 1;
	else cout << -1;
	return 0;
}