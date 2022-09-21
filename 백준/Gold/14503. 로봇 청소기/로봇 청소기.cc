#include <iostream>
#include <utility>
using namespace std;

#define X first
#define Y second
int n, m;
int vis_cnt=0; // 청소하는 칸 카운트 
int map[50][50]; // 로봇 청소기가 방문할 지도
int vis[50][50]; // 방문 여부 체크

int dx[4] = { -1,0,1,0 }; // 북 동 남 서 방향
int dy[4] = { 0,1,0,-1 };
int r, c, d; // 로봇 청소기의 현재 좌표와 바라보고 있는 방향

void input() {
	cin >> n >> m; // 배열 크기 입력
	cin >> r >> c >> d; // 현재좌표와 바라보는 방향 입력
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			cin >> map[x][y]; // 지도 입력
		}
	}
	vis[r][c] = 1; // 현재 칸을 방문함 표시
	vis_cnt++; // 방문횟수 1 증가 
}

void solve() {
	for (int i = 0; i < 4; i++) { // 방향 배열 사용 
		int nxt_d = (d + 3 - i) % 4; // 왼쪽으로 돌기
		int nxt_x = r + dx[nxt_d]; // 현재 좌표에서 다음 방향으로 돌기
		int nxt_y = c + dy[nxt_d];
		if (nxt_x < 0 || nxt_x >= n || nxt_y < 0 || nxt_y >= m || map[nxt_x][nxt_y]) continue;
		// 범위 벗어나거나 벽이면 무시
		if (map[nxt_x][nxt_y] == 0 && vis[nxt_x][nxt_y] == 0) {
		// 벽이 아니고 방문하지 않았다면 
			vis[nxt_x][nxt_y] = 1; // 방문하기
			r = nxt_x; // 현재 좌표를 갱신
			c = nxt_y;
			d = nxt_d; // 방향 갱신 
			vis_cnt++; // 방문 횟수 증가 
			solve(); // 다시 반복
		}
	}
	int back_idx = d > 1 ? d - 2 : d + 2; // 이전 인덱스가 1보다 크면 -2번 방향 바라보기 아니면 +2번방향
	int back_x = r + dx[back_idx]; // 현재좌표에서 돌아가는 좌표로
	int back_y = c + dy[back_idx]; 
	if (back_x >= 0 && back_x <= n || back_y >= 0 || back_y <= m)
	{
		// 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는,

		if (map[back_x][back_y] == 0)
		// 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.

		{
			r = back_x;
			c = back_y;
			solve();
		}
		// 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
		else
		{
			cout << vis_cnt << endl;
			exit(0);
		}
	}
}
int main() {
	input();
	solve();
	return 0;
}